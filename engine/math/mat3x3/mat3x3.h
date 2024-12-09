#pragma once

#include <math.h>
#include "../vec3/vec3.h"

typedef struct {
    float m[3][3];
} Mat3x3;

Mat3x3 mat3x3_identity();
Mat3x3 mat3x3_scale(float scale_x, float scale_y);
Mat3x3 mat3x3_translation(float tx, float ty);
Mat3x3 mat3x3_rotation(float angle_radians);

// Basic operations
Mat3x3 mat3x3_add(Mat3x3 a, Mat3x3 b);
Mat3x3 mat3x3_sub(Mat3x3 a, Mat3x3 b);
Mat3x3 mat3x3_mul(Mat3x3 a, Mat3x3 b);
Vec3 mat3x3_mul_vec3(Mat3x3 m, Vec3 v);

// Determinant and inverse
float mat3x3_determinant(Mat3x3 m);
Mat3x3 mat3x3_inverse(Mat3x3 m);

// Utility
Mat3x3 mat3x3_transpose(Mat3x3 m);
Mat3x3 mat3x3_orthographic(float left, float right, float bottom, float top);