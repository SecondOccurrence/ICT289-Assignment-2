/*
 * FILE: keyboard_utils.c
 * PURPOSE: function implementation for keyboard utility functions
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): introduced mainKeys, for inputs that manipulate the core scene. also clean up of unused parameters
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed globals
 *   Contributed by Josh S, 34195182
 * - v1.2 (12/05/2024): added keys to alter ball velocity
 *   Contributed by Josh S, 34195182
 *
 */

#include "keyboard_utils.h"

#include "../math/vector_operations.h"

void toggleKeys(unsigned char key, AnimationFlag* animation_flag, GridFlag* grid_flag, AxisFlag* axis_flag, ObjectsFlag* objects_flag) {
    switch(key) {
    case 'P':
    case 'p':
        if(*animation_flag == ANIMATION_ENABLED) {
            *animation_flag = ANIMATION_DISABLED;
        }
        else {
            *animation_flag = ANIMATION_ENABLED;
        }
        break;
    case 'G':
    case 'g':
        if(*grid_flag == GRID_ENABLED) {
            *grid_flag = GRID_DISABLED;
        }
        else {
            *grid_flag = GRID_ENABLED;
        }
        break;
    case 'O':
    case 'o':
        if(*axis_flag == AXIS_ENABLED) {
            *axis_flag = AXIS_DISABLED;
        }
        else {
            *axis_flag = AXIS_ENABLED;
        }
        break;
    case 'L':
    case 'l':
        if(*objects_flag == OBJECTS_ENABLED) {
            *objects_flag = OBJECTS_DISABLED;
        }
        else {
            *objects_flag = OBJECTS_ENABLED;
        }
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }   
}

BallProperties objectKeys(unsigned char key, BallProperties* objectProperties) {
    switch(key) {
<<<<<<< HEAD
=======
    case 'X':
        strafeLeft();
        break;
    case 'x':
        strafeRight();
        break;
    case 'Y':
        camera.position[1] -= 0.1;
        camera.lookat[1] -= 0.1;
        break;
    case 'y':
        camera.position[1] += 0.1;
        camera.lookat[1] += 0.1;
        break;
    case 'Z':
        moveForward();
        break;
    case 'z':
        moveBackward();
        break;
    case 'F':
        viewFront();
        break;
    case 'R':
        viewRear();
        break;
    case 'T':
        viewTop();
        break;
    case 'B':
        viewBottom();
        break;
    case 'I':
        viewLeft();
        break;
    case 'L':
        viewRight();
        break;
    }
}

void strafeLeft() {
    Vector3 direction, result;

    subtractVectors(direction, camera.lookat, camera.position);
    calcCrossProduct(result, direction, camera.up);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera.position, camera.position, result);
    subtractVectors(camera.lookat, camera.lookat, result);
}

void strafeRight() {
    Vector3 direction, result;

    subtractVectors(direction, camera.lookat, camera.position);
    calcCrossProduct(result, direction, camera.up);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera.position, camera.position, result);
    addVectors(camera.lookat, camera.lookat, result);
}

void moveForward() {
    Vector3 result;

    subtractVectors(result, camera.lookat, camera.position);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera.position, camera.position, result);
    subtractVectors(camera.lookat, camera.lookat, result);
}

void moveBackward() {
    Vector3 result;

    subtractVectors(result, camera.lookat, camera.position);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera.position, camera.position, result);
    addVectors(camera.lookat, camera.lookat, result);
}

void viewFront() {
    camera.position[0] = 0.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 3.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewRear() {
    camera.position[0] = 0.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = -3.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewTop() {
    camera.position[0] = 0.0f;
    camera.position[1] = 3.0f;
    camera.position[2] = 0.0f;

    if(camera.up[1] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 0.0f;
        camera.up[2] = 1.0f;
    }
}

void viewBottom() {
    camera.position[0] = 0.0f;
    camera.position[1] = -3.0f;
    camera.position[2] = 0.0f;

    if(camera.up[1] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 0.0f;
        camera.up[2] = 1.0f;
    }
}

void viewRight() {
    camera.position[0] = 3.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 0.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewLeft() {
    camera.position[0] = -3.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 0.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void transformKeys(unsigned char key, int x, int y, Object3D* obj) {
    Vector3 transformation = {0.0, 0.0, 0.0};
    switch(key) {
    case 'a':
        transformation[0] = -0.25;
        transformation[1] = 0.0;
        transformation[2] = 0.0;
<<<<<<< HEAD
        translateObject(obj, transformation);
        break;
    case 'd':
        transformation[0] = 0.25;
        transformation[1] = 0.0;
        transformation[2] = 0.0;
=======
>>>>>>> 0dfd7f60034b857f7270aa0d7dcdea3337965752
        translateObject(obj, transformation);
        break;
>>>>>>> c4920f9 (Added ball generation rectangle/triangle)
    case 'd':
        objectProperties->velocity[0] += 0.5f;
        break;
    case 'a':
        objectProperties->velocity[0] -= 0.5f;
        break;
    case 'w':
        objectProperties->velocity[1] += 1.0f;
        break;
    case 's':
        objectProperties->velocity[1] -= 1.0f;
        break;
    case 'q':
        objectProperties->velocity[2] += 0.5f;
        break;
    case 'e':
        objectProperties->velocity[2] -= 0.5f;
        break;
    default:
        break;
    }

    return *objectProperties;
}

void cameraKeys(unsigned char key, Camera* camera) {
    switch(key) {
    case 'X':
        strafeLeft(camera);
        break;
    case 'x':
        strafeRight(camera);
        break;
    case 'Y':
        camera->position[1] -= 0.1;
        camera->lookat[1] -= 0.1;
        break;
    case 'y':
        camera->position[1] += 0.1;
        camera->lookat[1] += 0.1;
        break;
    case 'Z':
        moveForward(camera);
        break;
    case 'z':
        moveBackward(camera);
        break;
    case 'F':
        viewFront(camera);
        break;
    case 'R':
        viewRear(camera);
        break;
    case 'T':
        viewTop(camera);
        break;
    case 'B':
        viewBottom(camera);
        break;
    case 'I':
        viewLeft(camera);
        break;
    case 'L':
        viewRight(camera);
        break;
    default:
        break;
    }
}

void strafeLeft(Camera* camera) {
    Vector3 direction, result;

    subtractVectors(direction, camera->lookat, camera->position);
    calcCrossProduct(result, direction, camera->up);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera->position, camera->position, result);
    subtractVectors(camera->lookat, camera->lookat, result);
}

<<<<<<< HEAD
void strafeRight(Camera* camera) {
    Vector3 direction, result;

    subtractVectors(direction, camera->lookat, camera->position);
    calcCrossProduct(result, direction, camera->up);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera->position, camera->position, result);
    addVectors(camera->lookat, camera->lookat, result);
}

void moveForward(Camera* camera) {
    Vector3 result;

    subtractVectors(result, camera->lookat, camera->position);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera->position, camera->position, result);
    subtractVectors(camera->lookat, camera->lookat, result);
}

void moveBackward(Camera* camera) {
    Vector3 result;

    subtractVectors(result, camera->lookat, camera->position);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera->position, camera->position, result);
    addVectors(camera->lookat, camera->lookat, result);
}

void viewFront(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 3.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewRear(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = -3.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewTop(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 3.0f;
    camera->position[2] = 0.0f;

    if(camera->up[1] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 0.0f;
        camera->up[2] = 1.0f;
    }
}

void viewBottom(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = -3.0f;
    camera->position[2] = 0.0f;

    if(camera->up[1] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 0.0f;
        camera->up[2] = 1.0f;
    }
}

void viewRight(Camera* camera) {
    camera->position[0] = 3.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 0.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewLeft(Camera* camera) {
    camera->position[0] = -3.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 0.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
=======
void rotationKeys(int key, int x, int y, Object3D* obj) {
    switch(key) {
    case GLUT_KEY_LEFT:
        rotateObject(obj, -10, 'x');
        break;
    case GLUT_KEY_RIGHT:
        rotateObject(obj, 10, 'x');
        break;
    case GLUT_KEY_UP:
        rotateObject(obj, 10, 'y');
        break;
    case GLUT_KEY_DOWN:
        rotateObject(obj, -10, 'y');
        break;
<<<<<<< HEAD
=======
>>>>>>> c4920f9 (Added ball generation rectangle/triangle)
>>>>>>> 0dfd7f60034b857f7270aa0d7dcdea3337965752
    }
}
