#ifndef camera_h
#define camera_h

#include "../math/geometry.h"

typedef enum {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
} CameraType;

typedef struct Camera {
    CameraType cameraMode;
    Point3 position;
    Point3 lookat;
    Vector3 up;
} Camera;

#endif
