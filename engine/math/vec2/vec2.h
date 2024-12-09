#pragma once
#include <math.h>

typedef struct Vec2_T {
    float x;
    float y;
} Vec2;

Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
Vec2 vec2_mul(Vec2 a, Vec2 b);
Vec2 vec2_div(Vec2 a, Vec2 b);
Vec2 vec2_scale(Vec2 v, float scalar);
Vec2 vec2_normalize(Vec2 v);

float vec2_dot(Vec2 a, Vec2 b);
float vec2_cross(Vec2 a, Vec2 b);
float vec2_length(Vec2 v);
float vec2_length_squared(Vec2 v);
float vec2_distance(Vec2 a, Vec2 b);
float vec2_distance_squared(Vec2 a, Vec2 b);

Vec2 vec2_perpendicular(Vec2 v);   // Perpendicular vector (rotated 90 degrees CCW)
Vec2 vec2_project(Vec2 a, Vec2 b); // Project vector `a` onto vector `b`
Vec2 vec2_reflect(Vec2 v, Vec2 normal);