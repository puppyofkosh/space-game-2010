#include "VBOExtend.h"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif
#ifdef __linux__
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#endif
#ifdef _WIN32
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>




// VBO Extension Function Pointers
PFNGLGENBUFFERSARBPROC glGenBuffersARB = NULL;					// VBO Name Generation Procedure
PFNGLBINDBUFFERARBPROC glBindBufferARB = NULL;					// VBO Bind Procedure
PFNGLBUFFERDATAARBPROC glBufferDataARB = NULL;					// VBO Data Loading Procedure
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;			// VBO Deletion Procedure
PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB = NULL; // return various parameters of VBO
PFNGLMAPBUFFERARBPROC glMapBufferARB = NULL;                       // map VBO procedure
PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB = NULL; 
PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB = NULL;

PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = NULL;	//Declaration of function
#endif