#define near 1.0
#define far 30.0
#define right 0.5
#define left -0.5
#define top 0.5
#define bottom -0.5

#define MODEL_GUBBE 0 

typedef struct
{
	Model* model;

	GLuint program;
	GLuint texture;

	mat4 translation_mat;
	mat4 rotation_mat;	
	mat4 modelView_mat;
	mat4 modelViewProjection_mat;

}Model;

mat4 projection_mat = frustum(left, right, bottom, top, near, far);

void graphicsInitModels();