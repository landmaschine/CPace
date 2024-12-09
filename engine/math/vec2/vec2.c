#include "vec2.h"

Vec2 vec2_add(Vec2 a, Vec2 b) {
    return (Vec2){a.x + b.x, a.y + b.y};
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
    return (Vec2){a.x - b.x, a.y - b.y};
}

Vec2 vec2_mul(Vec2 a, Vec2 b) {
    return (Vec2){a.x * b.x, a.y * b.y};
}

Vec2 vec2_div(Vec2 a, Vec2 b) {
    return (Vec2){a.x / b.x, a.y / b.y};
}

Vec2 vec2_scale(Vec2 v, float scalar) {
    return (Vec2){v.x * scalar, v.y * scalar};
}

Vec2 vec2_normalize(Vec2 v) {
    float length = vec2_length(v);
    if (length == 0.0f) return (Vec2){0.0f, 0.0f};
    return vec2_scale(v, 1.0f / length);
}

// Advanced operations
float vec2_dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

float vec2_cross(Vec2 a, Vec2 b) {
    return a.x * b.y - a.y * b.x;
}

float vec2_length(Vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float vec2_length_squared(Vec2 v) {
    return v.x * v.x + v.y * v.y;
}

float vec2_distance(Vec2 a, Vec2 b) {
    return vec2_length(vec2_sub(a, b));
}

float vec2_distance_squared(Vec2 a, Vec2 b) {
    return vec2_length_squared(vec2_sub(a, b));
}

// Utility
Vec2 vec2_perpendicular(Vec2 v) {
    return (Vec2){-v.y, v.x};
}

Vec2 vec2_project(Vec2 a, Vec2 b) {
    float b_length_squared = vec2_length_squared(b);
    if (b_length_squared == 0.0f) return (Vec2){0.0f, 0.0f};
    float scale = vec2_dot(a, b) / b_length_squared;
    return vec2_scale(b, scale);
}

Vec2 vec2_reflect(Vec2 v, Vec2 normal) {
    Vec2 normalized_normal = vec2_normalize(normal);
    return vec2_sub(v, vec2_scale(normalized_normal, 2.0f * vec2_dot(v, normalized_normal)));
}
