#pragma once
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_mul(Vec3 a, Vec3 b);
Vec3 vec3_div(Vec3 a, Vec3 b);
Vec3 vec3_scale(Vec3 v, float scalar);
Vec3 vec3_normalize(Vec3 v);

float vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_cross(Vec3 a, Vec3 b);
float vec3_length(Vec3 v);
float vec3_length_squared(Vec3 v);
float vec3_distance(Vec3 a, Vec3 b);
float vec3_distance_squared(Vec3 a, Vec3 b);

// Utility
Vec3 vec3_project(Vec3 a, Vec3 b); // Project vector `a` onto vector `b`
Vec3 vec3_reflect(Vec3 v, Vec3 normal);
Vec3 vec3_lerp(Vec3 a, Vec3 b, float t); // Linear interpolation


