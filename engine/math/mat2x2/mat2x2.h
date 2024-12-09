#pragma once
#include <math.h>
#include "../vec2/vec2.h"

typedef struct {
    float m[2][2];
} Mat2x2;

Mat2x2 mat2x2_identity();
Mat2x2 mat2x2_scale(float scale_x, float scale_y);
Mat2x2 mat2x2_rotation(float angle_radians);

Mat2x2 mat2x2_add(Mat2x2 a, Mat2x2 b);
Mat2x2 mat2x2_sub(Mat2x2 a, Mat2x2 b);
Mat2x2 mat2x2_mul(Mat2x2 a, Mat2x2 b);
Vec2 mat2x2_mul_vec2(Mat2x2 m, Vec2 v);

float mat2x2_determinant(Mat2x2 m);
Mat2x2 mat2x2_inverse(Mat2x2 m);

