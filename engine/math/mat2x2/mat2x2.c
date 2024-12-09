#include "mat2x2.h"

Mat2x2 mat2x2_identity() {
    return (Mat2x2){{
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    }};
}

Mat2x2 mat2x2_scale(float scale_x, float scale_y) {
    return (Mat2x2){{
        {scale_x, 0.0f},
        {0.0f, scale_y}
    }};
}

Mat2x2 mat2x2_rotation(float angle_radians) {
    float c = cosf(angle_radians);
    float s = sinf(angle_radians);
    return (Mat2x2){{
        {c, -s},
        {s, c}
    }};
}

Mat2x2 mat2x2_add(Mat2x2 a, Mat2x2 b) {
    return (Mat2x2){{
        {a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1]},
        {a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1]}
    }};
}

Mat2x2 mat2x2_sub(Mat2x2 a, Mat2x2 b) {
    return (Mat2x2){{
        {a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1]},
        {a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1]}
    }};
}

Mat2x2 mat2x2_mul(Mat2x2 a, Mat2x2 b) {
    return (Mat2x2){{
        {
            a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0],
            a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]
        },
        {
            a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0],
            a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]
        }
    }};
}

Vec2 mat2x2_mul_vec2(Mat2x2 m, Vec2 v) {
    return (Vec2){
        m.m[0][0] * v.x + m.m[0][1] * v.y,
        m.m[1][0] * v.x + m.m[1][1] * v.y
    };
}

// Determinant and inverse
float mat2x2_determinant(Mat2x2 m) {
    return m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0];
}

Mat2x2 mat2x2_inverse(Mat2x2 m) {
    float det = mat2x2_determinant(m);
    if (det == 0.0f) {
        return mat2x2_identity(); // Return identity as a placeholder for non-invertible matrix
    }
    float inv_det = 1.0f / det;
    return (Mat2x2){{
        { m.m[1][1] * inv_det, -m.m[0][1] * inv_det },
        {-m.m[1][0] * inv_det,  m.m[0][0] * inv_det }
    }};
}
