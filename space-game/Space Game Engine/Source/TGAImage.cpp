#include "TGAImage.h"


TGAImage::TGAImage()
{

}
TGAImage::TGAImage(const std::string& filename)
{
    load(filename);
}
TGAImage::~TGAImage()
{
}

//turns something that was BGRA to RGBA
void TGAImage::flipColorOrder()
{
    unsigned short bytesPerPixel = pixelDepthBits/8;

    int pixelCount = width*height;
    unsigned char* place = &imageData[0];
    for (unsigned int i = 0; i < pixelCount; ++i)
    {
        unsigned char blue = (*place);		//swap
        (*place) = *(place + 2);
        *(place + 2) = blue;

        place += bytesPerPixel;
    }
}

//Just stores the file as a vector<unsigned char>
bool TGAImage::loadPixelData (const std::string& filename)
{
    std::ifstream in (filename.c_str(), std::ios::in|std::ios::binary);

    if (!in)//couldn't open
        return 0;

    in.seekg(0, std::ios::end);
    unsigned long filesize = (unsigned long)in.tellg();
    rawFile.resize(filesize);

    in.seekg(0, std::ios::beg);//take us back to the beginning
    in.read((char*)&rawFile[0], rawFile.size());


    return 1;
}

bool TGAImage::readHeader()
{
    //pixels[0]		//this stores a number 0-255, the ID length

    idLength = rawFile[0];//gotta store this for later.

    isColorMap = rawFile[1];
    //straight off wikipedia:	//0 if image file contains no color map
    //1 if present
    //2-127 reserved by Truevision
    //128-255 available for developer use
    //Just assume/hope that its 1 or 0

    imageType = rawFile[2];//       0  -  No image data included.
    //1  -  Uncompressed, color-mapped images.
    //2  -  Uncompressed, RGB images.
    // 3  -  Uncompressed, black and white images.
    // 9  -  Runlength encoded color-mapped images.
    // 10  -  Runlength encoded RGB images.
    // 11  -  Compressed, black and white images.
    // 32  -  Compressed color-mapped data, using Huffman, Delta, and
    //				runlength encoding.
    // 33  -  Compressed color-mapped data, using Huffman, Delta, and
    //			runlength encoding.  4-pass quadtree-type process.

    // Don't support cases 32 or 33
    if (imageType == 32 || imageType == 33)
        return 0;




    memcpy(&colorMapFirst, &rawFile[3], 2);
    memcpy(&colorMapCount, &rawFile[5], 2);


    if (isColorMap == 1)
        if (colorMapFirst != 0)
            return 0;

    //Located at [7] and is 1 byte. Has a value of 16, 24, or 32.
    bitsPerColorMapEntry = rawFile[7];


    memcpy(&xOrigin, &rawFile[8], 2);
    memcpy(&yOrigin, &rawFile[10], 2);



    memcpy(&width, &rawFile[12], 2);
    memcpy(&height, &rawFile[14], 2);

    //now pixel depth
    pixelDepthBits = rawFile[16];

    //I read that this SHOULD be set to 0
    imageDescriptor = rawFile[17];
    //if (imageDescriptor != 0)
    //return 0;

    headerLength = 18;//we just read thru 0-17

    return 1;

}


bool TGAImage::loadColorMap()
{
    //according to wikipedia, the color map comes after the header and ID



    int offset = headerLength + idLength;
    int colorMapLength = colorMapCount * (pixelDepthBits/8);
    colorMap.resize(colorMapLength);

    memcpy(&colorMap[0], &rawFile[offset], colorMapLength);

    return 1;

}


bool TGAImage::loadImageData()
{
    //First we find the size of the imageData based on what we loaded in from
    //the image spec. It should width*height*pixelDepth/8 bytes
    unsigned short pixelDepthBytes = pixelDepthBits/8;
    unsigned long sizeInBytes = width*height*pixelDepthBytes;
    //Since imageData is made of unsigned chars, which are each 1 byte, we can
    //just store the size in bytes.
    imageData.resize(sizeInBytes);

    //starts after header, unless we have a color map
    unsigned long offset = 18 + rawFile[0];

    //Now we have to load the image data from AFTER the colorMap.
    if (isColorMap == 1)
        offset += colorMap.size();


    memcpy(&imageData[0], &rawFile[offset], sizeInBytes);


    //now we check if it is upside down
    bool upsideDown = imageDescriptor & 0x20;
    //the 5th bit says if its upside down

    if (upsideDown == 0)
    {
        //swap the top "row" with the bottom "row"
        //we can treat this like it is a 2d array being a stored in a 1d array
        //so arr[xPlace + yPlace*(width of 1 line)] will give you arr(xPlace,
        //yPlace)
        //note that the x order remains the same, but the y order does not
        unsigned int lineSize = width*(pixelDepthBits/8);
        unsigned char* firstLine = &imageData[0];
        //we go from row 0 -> (height-1)
        unsigned char* otherLine = &imageData[(lineSize)*(height-1)];

        std::vector<unsigned char> tmp;
        tmp.resize(lineSize);
        //now we go from the top to the middle and the bottom to the middle
        //until the firstLine and otherLine become one
        while (firstLine != otherLine)
        {
            // Swap firstline and other
            std::copy(firstLine, (firstLine+lineSize), tmp.begin());
            std::copy(otherLine, otherLine + lineSize, firstLine);
            std::copy(tmp.begin(), tmp.end(), otherLine);
            firstLine += lineSize;

            if (firstLine == otherLine)
                break;

            otherLine -= lineSize;
        }


    }

    return 1;

}


bool TGAImage::loadImageDataRLECompressed()
{
    //Alright there is a ton of stuff I need to put here.
    //First off, each indice starts with a 1 byte header. This tells whether
    //it is a "raw" packet, or a run-length packet.
    //If the first bit of the 1 byte header is 1, it is run length.
    //if the first bit is 0 it is raw.

    //The next 7 bits are a count of how many pixels there are - 1.
    //So with 7 bits, the max you can get is 127, and since it is "- 1", the
    //highest you can get is 128 and the lowest is 1.

    //RL Packet

    //      __________________________________________________
    //   | 1 bit |   7 bit repetition count minus 1.      |
    //     |   ID  |   Since the maximum value of this      |
    //     |       |   field is 127, the largest possible   |
    //      |       |   run size would be 128.               |
    //     |-------|----------------------------------------|
    //     |   1   |  C     C     C     C     C     C    C  |
    //      --------------------------------------------------

    //For the run length packet, the header is followed by
    //a single color index, which is assumed to be repeated
    //the number of times specified in the header.

    //Raw packet
    //For the raw packet, the header is followed by the number
    //of color indices specified in the header. They don't repeat.

    //First we find the size of the imageData based on what we loaded in from
    //the image spec. It should width*height*pixelDepth/8 bytes
    unsigned short pixelDepthBytes = pixelDepthBits/8;
    unsigned long sizeInBytes = width*height*pixelDepthBytes;
    imageData.resize(sizeInBytes);//Since imageData is made of unsigned chars,
    //which are each 1 byte, we can just store the size in bytes.

    int offset = headerLength + idLength;


    if (isColorMap == 1)			//Nothing we haven't done before
        offset += colorMap.size();

    //our starting point for where the data we will be copying is stored at.
    unsigned char* filePlace = &rawFile[offset];
    //points to where we are copying our data in the imageData array
    unsigned char* imageDataPlace = &imageData[0];

    int bytesPerPixel = pixelDepthBits/8;

    unsigned long dataCopied = 0;//amount of data we've copied so far.

    while (dataCopied < imageData.size())
    {
        //now lets check the most significant bit to see if it is 1 (RL) or
        //0(raw)
        //we will bitwise and it with 80(hex), which is basically
        // (low) 1000 (high)0000
        //or 10000000 in binary. We'll get either 10000000 or 00000000
        //(the value of the high bit)
        bool msb = (*filePlace) & 0x80;

        // Compressed packet
        if (msb == 1)
        {
            //okay now we need to treat this as a 7 bit number, so we have to
            //subtract 128 (if the MSB is 1, it will add 128)
            unsigned int length = (*filePlace) - 128;
            //and the spec above said that the 7 bit number was 1 LESS than the
            //amount of pixels. So we gotta add 1.
            length += 1;


            // Move to next byte
            filePlace++;

            //and now we save this packet to the imageData array
            for (int i = 0; i < length; ++i)
            {
                memcpy(imageDataPlace, filePlace, bytesPerPixel);
                imageDataPlace += bytesPerPixel;

                dataCopied += bytesPerPixel;
            }


            //move our pointer to the next packet
            filePlace += bytesPerPixel;
        }
        else if (msb == 0)//raw packet
        {
            //alright same thing as last time-we have to check that 7 bit
            //number. The main difference is that here the MSB is 0, so we
            //don't have to
            //subtract 128
            //We just add 1
            unsigned char length = (*filePlace) + 1;

            //and we're done with the header, so we move on, TO the pixels
            filePlace++;

            // No decompression needed...just copy directly to imageData
            for (int i = 0; i < length; ++i)
            {
                memcpy(imageDataPlace, filePlace, bytesPerPixel);
                imageDataPlace += bytesPerPixel;
                //this time they(packets) don't repeat, so we have to increment
                // this too.
                filePlace += bytesPerPixel;

                dataCopied += bytesPerPixel;
            }
            //at the end of the loop filePlace should be where it needs for the
            // next packet.
        }
    }

    return 1;



}


bool TGAImage::readFromImageType()
{
    switch (imageType)
    {
    case 0://no data included.
        return 0;
        break;
    case 1:			//uncompressed, color-mapped image
        if (isColorMap == 1)
            if (loadColorMap() == 0)
                return 0;
        //now we just load in the data

        if (loadImageData() == 0)
            return 0;


        break;

    case 2://2 uncompressed, true-color image (no color map)
        //I guess we just load the data directly...
        if (loadImageData() == 0)
            return 0;

        //
        flipColorOrder();//Go from bgr to rgb

        break;

    case 3:			//uncompressed, black-and-white image
        //I guess we just load the data...
        if (loadImageData() == 0)
            return 0;

        break;




    case 9:			//run-length encoded, color-mapped Image,
        //(run length encoded = RLE)
        if (isColorMap == 1)
            if (loadColorMap() == 0)
                return 0;

        if (loadImageDataRLECompressed() == 0)
            return 0;

        flipColorOrder();

        break;

    case 10:		// run-length encoded, true-color image
        if (isColorMap == 1)
            if (loadColorMap() == 0)
                return 0;

        if (loadImageDataRLECompressed() == 0)
            return 0;

        flipColorOrder();

        break;
    default:
        return 0;
    }

    return 1;
}


bool TGAImage::load(const std::string& filename)
{
    if (!loadPixelData(filename))
        return 0;
    if (!readHeader())
        return 0;
    if (!readFromImageType())
        return 0;

    return 1;
}