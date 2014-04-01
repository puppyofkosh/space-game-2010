#include "Game Class/GameClass.h"
#include "TGAImage.h"

GLuint Game::loadTexture(char *TexName)
 {
	TGAImage Img;
   //TGAImg Img;        // Image loader
   GLuint Texture;

  // Load our Texture
   if(Img.load(TexName)!=true)
    return -1;

   glGenTextures(1,&Texture);            // Allocate space for texture, and generate an ID
   glBindTexture(GL_TEXTURE_2D,Texture); // Set our Tex handle as current

   // Create the texture
    if(Img.getPixelDepthBits()==24)
		glTexImage2D(GL_TEXTURE_2D,0,3,Img.getWidth(),Img.getHeight(),0,GL_RGB,GL_UNSIGNED_BYTE,Img.getImageData());
    else if(Img.getPixelDepthBits()==32)
     glTexImage2D(GL_TEXTURE_2D,0,4,Img.getWidth(),Img.getHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,Img.getImageData());
    else
     return -1;

   // Specify filtering and edge actions
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

   glBindTexture (GL_TEXTURE_2D, 0);//We must unbind the texture.

   return Texture;
 }