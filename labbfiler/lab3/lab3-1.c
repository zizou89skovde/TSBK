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
#define far 50.0
#define right 0.5
#define left -0.5
#define top 0.5
#define bottom -0.5

// vertex array object

GLuint program;
GLuint myTex;
Model* mblade;
Model* mbalcony;
Model* mroof;
Model* mwalls;

void init(void)
{
	// Reference to shader program
	dumpInfo();

	// GL inits
	glClearColor(0.2,0.2,0.5,0);
	glEnable(GL_DEPTH_TEST);
	printError("GL inits");

	// Load and compile shader
	program = loadShaders("lab3-1.vert", "lab3-1.frag");
	printError("init shader");
	
	//Load model
	mblade 	 =  LoadModelPlus("windmill/blade.obj");
	mbalcony =  LoadModelPlus("windmill/windmill-balcony.obj");
	mroof 	 =  LoadModelPlus("windmill/windmill-roof.obj");
	mwalls 	 =  LoadModelPlus("windmill/windmill-walls.obj");
	

	//Load textures
	//LoadTGATextureSimple("maskros512.tga", &myTex);
	//glBindTexture(GL_TEXTURE_2D, myTex);
	//glUniform1i(glGetUniformLocation(program, "texUnit"), 0); // Texture unit 0	
	//printError("init texture");	
}

void display(void)
{
	printError("pre display");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat t = (GLfloat)glutGet(GLUT_ELAPSED_TIME);
	GLfloat theta = t/500.0f;

	glUniform1f(glGetUniformLocation(program, "time"),t);

	mat4 proj_mat = frustum(left, right, bottom, top, near, far);

	mat4 mblade_mat    = IdentityMatrix();
	mat4 mbalcony_mat  = IdentityMatrix();
	mat4 mroof_mat     = IdentityMatrix();
	mat4 mwalls_mat    = IdentityMatrix();


	mat4 rotation_mat;
	mat4 translation_mat;
	mat4 mv_mat;
	mat4 mvp_mat;
	mat4 view_mat;

	vec3 rotate_axis;
	rotate_axis.x = 1;
	rotate_axis.y = 0;
	rotate_axis.z = 0;

	GLfloat r = 40;
	GLfloat cam_pos_x = r*cos(theta);
	GLfloat cam_pos_z = r*sin(theta);

	view_mat = lookAt(cam_pos_x, 4, cam_pos_z, 
		    	  0, 0, 0,
		    	  0, 1, 0);

	rotation_mat = ArbRotate(rotate_axis, theta);
	translation_mat = T(4.5, 10, 0);

	mblade_mat = Mult(translation_mat,rotation_mat);
	mv_mat 	= Mult(view_mat,mblade_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);	
	DrawModel(mblade, program, "in_Position", "in_Normal", "in_TexCoord");
	

	rotation_mat = ArbRotate(rotate_axis, 3.14/2+theta);
	mblade_mat = Mult(translation_mat,rotation_mat);
	mv_mat 	= Mult(view_mat,mblade_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);	
	DrawModel(mblade, program, "in_Position", "in_Normal", "in_TexCoord");

	rotation_mat = ArbRotate(rotate_axis, 3.14+theta);
	mblade_mat = Mult(translation_mat,rotation_mat);
	mv_mat 	= Mult(view_mat,mblade_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);	
	DrawModel(mblade, program, "in_Position", "in_Normal", "in_TexCoord");

	rotation_mat = ArbRotate(rotate_axis, 3*3.14/2+theta);
	mblade_mat = Mult(translation_mat,rotation_mat);
	mv_mat 	= Mult(view_mat,mblade_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);	
	DrawModel(mblade, program, "in_Position", "in_Normal", "in_TexCoord");




	mv_mat  = Mult(view_mat,mbalcony_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);
	DrawModel(mbalcony, program, "in_Position", "in_Normal", "in_TexCoord");

	mv_mat  = Mult(view_mat,mroof_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);
	DrawModel(mroof, program, "in_Position", "in_Normal", "in_TexCoord");	

	mv_mat  = Mult(view_mat,mwalls_mat);
	mvp_mat = Mult(proj_mat,mv_mat);
	glUniformMatrix4fv(glGetUniformLocation(program, "MVP_Matrix"), 1, GL_TRUE, mvp_mat.m);	
  	glUniformMatrix4fv(glGetUniformLocation(program, "MV_Matrix"), 1, GL_TRUE , mv_mat.m);
	DrawModel(mwalls, program, "in_Position", "in_Normal", "in_TexCoord");	

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