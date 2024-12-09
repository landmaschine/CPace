#include "mat3x3.h"

Mat3x3 mat3x3_identity() {
    return (Mat3x3){{
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    }};
}

Mat3x3 mat3x3_scale(float scale_x, float scale_y) {
    return (Mat3x3){{
        {scale_x, 0.0f,   0.0f},
        {0.0f,   scale_y, 0.0f},
        {0.0f,   0.0f,   1.0f}
    }};
}

Mat3x3 mat3x3_translation(float tx, float ty) {
    return (Mat3x3){{
        {1.0f, 0.0f, tx},
        {0.0f, 1.0f, ty},
        {0.0f, 0.0f, 1.0f}
    }};
}

Mat3x3 mat3x3_rotation(float angle_radians) {
    float c = cosf(angle_radians);
    float s = sinf(angle_radians);
    return (Mat3x3){{
        {c, -s, 0.0f},
        {s,  c, 0.0f},
        {0.0f, 0.0f, 1.0f}
    }};
}

Mat3x3 mat3x3_add(Mat3x3 a, Mat3x3 b) {
    Mat3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
    return result;
}

Mat3x3 mat3x3_sub(Mat3x3 a, Mat3x3 b) {
    Mat3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
    return result;
}

Mat3x3 mat3x3_mul(Mat3x3 a, Mat3x3 b) {
    Mat3x3 result = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result;
}

Vec3 mat3x3_mul_vec3(Mat3x3 m, Vec3 v) {
    return (Vec3){
        m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z,
        m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z,
        m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z
    };
}

float mat3x3_determinant(Mat3x3 m) {
    return 
        m.m[0][0] * (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]) -
        m.m[0][1] * (m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0]) +
        m.m[0][2] * (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]);
}

Mat3x3 mat3x3_inverse(Mat3x3 m) {
    float det = mat3x3_determinant(m);
    if (det == 0.0f) return mat3x3_identity();
    float inv_det = 1.0f / det;

    return (Mat3x3){{
        {
            (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]) * inv_det,
            (m.m[0][2] * m.m[2][1] - m.m[0][1] * m.m[2][2]) * inv_det,
            (m.m[0][1] * m.m[1][2] - m.m[0][2] * m.m[1][1]) * inv_det
        },
        {
            (m.m[1][2] * m.m[2][0] - m.m[1][0] * m.m[2][2]) * inv_det,
            (m.m[0][0] * m.m[2][2] - m.m[0][2] * m.m[2][0]) * inv_det,
            (m.m[0][2] * m.m[1][0] - m.m[0][0] * m.m[1][2]) * inv_det
        },
        {
            (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]) * inv_det,
            (m.m[0][1] * m.m[2][0] - m.m[0][0] * m.m[2][1]) * inv_det,
            (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]) * inv_det
        }
    }};
}

Mat3x3 mat3x3_transpose(Mat3x3 m) {
    return (Mat3x3){{
        {m.m[0][0], m.m[1][0], m.m[2][0]},
        {m.m[0][1], m.m[1][1], m.m[2][1]},
        {m.m[0][2], m.m[1][2], m.m[2][2]}
    }};
}

Mat3x3 mat3x3_orthographic(float left, float right, float bottom, float top) {
    Mat3x3 result = {0};
    
    result.m[0][0] = 2.0f / (right - left);
    result.m[1][1] = 2.0f / (top - bottom);
    result.m[2][2] = 1.0f;
    
    result.m[0][2] = -(right + left) / (right - left);
    result.m[1][2] = -(top + bottom) / (top - bottom);
    
    result.m[2][0] = 0.0f;
    result.m[2][1] = 0.0f;
    
    return result;
}
