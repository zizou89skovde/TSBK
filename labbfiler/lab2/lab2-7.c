// Lab 1-1.
// This is the same as the first simple example in the course book,
// but with a few error checks.
// Remember to copy your file to a new on appropriate places during the lab so you keep old results.
// Note that the files "lab1-1.frag", "lab1-1.vert" are required.

// Should work as is on Linux and Mac. MS Windows needs GLEW or glee.
// See separate Visual Studio version of my demos.
#ifdef __APPLE__
	#include <OpenGL/gl3.h>
	#include "MicroGlut.h"
	// Linking hint for Lightweight IDE
	// uses framework Cocoa
#endif
#include "GL_utilities.h"
#include "VectorUtils3.h"
#include "loadobj.h"
#include "LoadTGA.h"
#include <math.h>
// Globals
// Data would normally be read from files


GLfloat myMatrix[] = {    1.0f, 0.0f, 0.0f, 0.5f,
                        0.0f, 1.0f, 0.0f, 0.0f,
                        0.0f, 0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f 
};

#define near 1.0
#define far 30.0
#define right 0.5
#define left -0.5
#define top 0.5
#define bottom -0.5

// vertex array object

GLuint program;
GLuint myTex;
Model* mbunny;
Model* mcastle;

void init(void)
{
	// Reference to shader program
	dumpInfo();

	// GL inits
	glClearColor(0.2,0.2,0.5,0);
	glEnable(GL_DEPTH_TEST);
	printError("GL inits");

	// Load and compile shader
	program = loadShaders("lab2-7.vert", "lab2-7.frag");
	printError("init shader");
	
	//Load model
	mbunny =  LoadModelPlus("bunnyplus.obj");
	mcastle =  LoadModelPlus("models/various/cow.obj");

	//Load textures
	LoadTGATextureSimple("maskros512.tga", &myTex);
	glBindTexture(GL_TEXTURE_2D, myTex);
	glUniform1i(glGetUniformLocation(program, "texUnit"), 0); // Texture unit 0	
	printError("init texture");
	
	
}


void display(void)
{
	printError("pre display");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	GLfloat t = (GLfloat)glutGet(GLUT_ELAPSED_TIME);
	GLfloat theta = t/5000.0f;

	glUniform1f(glGetUniformLocation(program, "time"),t);

	mat4 proj_mat = frustum(left, right, bottom, top, near, far);

	mat4 mbunny_mat;
	mat4 mcastle_mat;
	mat4 mvp_mat;
	mat4 view_mat;
	mat4 mv_mat;

	GLfloat r = 6;
	GLfloat cam_pos_x = r*cos(theta);
	GLfloat cam_pos_z = r*sin(theta);

	view_mat = lookAt(cam_pos_x, 4, cam_pos_z, 
		    	  0, 0, 0,
		    	  0, 1, 0);

	mbunny_mat = T(0, 0, 1);
	mv_mat 	= Mult(view_mat,mbunny_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);	

	DrawModel(mbunny, program, "in_Position", "in_Normal", "in_TexCoord");

	mcastle_mat = T(0, 0, -1);
	mv_mat  = Mult(view_mat,mcastle_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);

	DrawModel(mcastle, program, "in_Position", "in_Normal", "in_TexCoord");	

	printError("display");
	
	glutSwapBuffers();
}

void OnTimer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(20, &OnTimer, value);	

	printError("init texCoord array");
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(3, 2);
	glutCreateWindow ("GL3 white triangle example");
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutDisplayFunc(display); 
	init ();
	glutTimerFunc(20, &OnTimer, 0);
	glutMainLoop();
}