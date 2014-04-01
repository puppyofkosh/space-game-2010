/*
 *  TGAImage.h
 *
 *  Created by puppyofkosh on 3/2/10.
 */

#pragma once

#include <fstream>
#include <vector>

#include <iostream>

#ifndef TGAIMAGE_H_
#define TGAIMAGE_H_

class TGAImage
{
private:
    //general stuff
    unsigned int headerLength;

    //Field #1 is the ID length. It is 1 byte.
    unsigned char idLength;

    //Field #2
    unsigned char isColorMap;//1 byte

    //Field #3
    unsigned char imageType;//1 byte

    //Field #4
    unsigned short colorMapFirst;//2 bytes
    unsigned short colorMapCount;//2 bytes
    // Either 16, 24, or 32.
    unsigned char bitsPerColorMapEntry;

    //Field #5 -> image specs/dimensions
    unsigned short xOrigin;
    unsigned short yOrigin;
    unsigned short width;//measured in pixels.
    unsigned short height;
    unsigned int pixelDepthBits;//bits per pixel
    unsigned char imageDescriptor;


    //The file loaded into a vector
    std::vector<unsigned char> rawFile;
    std::vector<unsigned char> colorMap;
    //The actual "image"/pixels we extract out of the file
    std::vector<unsigned char> imageData;

    void cleanup();

    // returns success/fail
    bool loadPixelData(const std::string& filename);

    bool readHeader();
    //will look at the image type and load the pixels accordingly
    bool readFromImageType();
    bool loadColorMap();
    bool loadImageData();//stores actual image data to pixels array
    bool loadImageDataRLECompressed();

    void flipColorOrder();
public:
    bool load(const std::string& filename);

    short getWidth()	const
    {
        return width;
    }
    short getHeight()	const
    {
        return height;
    }
    unsigned char*	getImageData()
    {
        return &imageData[0];
    }
    unsigned char getPixelDepthBits()		const
    {
        return pixelDepthBits;
    }

    TGAImage();
    TGAImage(const std::string& filename);



    virtual ~TGAImage();

};


#endif
