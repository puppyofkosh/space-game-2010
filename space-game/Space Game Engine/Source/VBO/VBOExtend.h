// VBO Extension Definitions, From glext.h

//YOU MUST HAVE GLEXT.h included before using this, otherwise, you will get a load of errors.
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_DYNAMIC_DRAW_ARB 0x88E8

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#endif
#ifdef __linux__
#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#ifdef _WIN32
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>


typedef void (APIENTRY * PFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRY * PFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRY * PFNGLBUFFERDATAARBPROC) (GLenum target, int size, const GLvoid *data, GLenum usage);
typedef void (APIENTRY * PFNGLGETBUFFERPARAMETERIVARBPROC) (GLenum target, GLenum value, GLint * data);
typedef void (APIENTRY * PFNGLMAPBUFFERARBPROC) (GLenum	target, GLenum access);
typedef void (APIENTRY * PFNGLUNMAPBUFFERARBPROC) (GLenum  	target);
typedef void (APIENTRY * PFNGLBUFFERSUBDATAARBPROC) (GLenum target, int offset, int size, const GLvoid * data);

// VBO Extension Function Pointers
extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;					// VBO Name Generation Procedure
extern PFNGLBINDBUFFERARBPROC glBindBufferARB;					// VBO Bind Procedure
extern PFNGLBUFFERDATAARBPROC glBufferDataARB;					// VBO Data Loading Procedure
extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;			// VBO Deletion Procedure
extern PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB; // return various parameters of VBO
extern PFNGLMAPBUFFERARBPROC glMapBufferARB;                       // map VBO procedure
extern PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;                   // unmap VBO procedure
extern PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;

extern PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;	//Declaration of function

#endif
