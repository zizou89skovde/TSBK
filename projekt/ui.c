#include "ui.h"

#define CAM_LOOK_SPEED 1.0
#define CAM_STRAFE_SPEED 1.0


void handleKeyboardInput(void) {
/*
	vec3 lookDirection = Normalize(VectorSub(camCenter,camEye));

	if (keyIsDown('a')) {
		vec3 strafeDirection = Normalize(CrossProduct(camUp,lookDirection));
		strafeDirection = ScalarMult(strafeDirection,CAM_STRAFE_SPEED); 
		camEye = VectorAdd(camEye,strafeDirection);
		camCenter = VectorAdd(camCenter,strafeDirection);
	}
	if (keyIsDown('d')){
		vec3 strafeDirection = Normalize(CrossProduct(camUp,lookDirection));
		strafeDirection = ScalarMult(strafeDirection,CAM_STRAFE_SPEED); 
		camEye = VectorSub(camEye,strafeDirection);
		camCenter = VectorSub(camCenter,strafeDirection);
	}
	if (keyIsDown('w')) {
		lookDirection = ScalarMult(lookDirection,CAM_STRAFE_SPEED); 
		camEye = VectorAdd(camEye,lookDirection);
		camCenter = VectorAdd(camCenter,lookDirection);	
	}
	if (keyIsDown('s')) {
		lookDirection = ScalarMult(lookDirection,CAM_STRAFE_SPEED); 
		camEye = VectorSub(camEye,lookDirection);
		camCenter = VectorSub(camCenter,lookDirection);	
	}
*/

}

void handleMouseInput(int x ,int y) {
/*
	vec3 lookDirection = Normalize(VectorSub(camCenter,camEye));

	if (keyIsDown('a')) {
		vec3 strafeDirection = Normalize(CrossProduct(camUp,lookDirection));
		strafeDirection = ScalarMult(strafeDirection,CAM_LOOK_SPEED); 
		camEye = VectorAdd(camEye,strafeDirection);
		camCenter = VectorAdd(camCenter,strafeDirection);
	}
	if (keyIsDown('d')){
		vec3 strafeDirection = Normalize(CrossProduct(camUp,lookDirection));
		strafeDirection = ScalarMult(strafeDirection,CAM_LOOK_SPEED); 
		camEye = VectorSub(camEye,strafeDirection);
		camCenter = VectorSub(camCenter,strafeDirection);
	}
	if (keyIsDown('w')) {
		lookDirection = ScalarMult(lookDirection,CAM_LOOK_SPEED); 
		camEye = VectorAdd(camEye,lookDirection);
		camCenter = VectorAdd(camCenter,lookDirection);	
	}
	if (keyIsDown('s')) {
		lookDirection = ScalarMult(lookDirection,CAM_LOOK_SPEED); 
		camEye = VectorSub(camEye,lookDirection);
		camCenter = VectorSub(camCenter,lookDirection);	
	}
*/

}