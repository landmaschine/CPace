#include "vec3.h"

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 vec3_mul(Vec3 a, Vec3 b) {
    return (Vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

Vec3 vec3_div(Vec3 a, Vec3 b) {
    return (Vec3){a.x / b.x, a.y / b.y, a.z / b.z};
}

Vec3 vec3_scale(Vec3 v, float scalar) {
    return (Vec3){v.x * scalar, v.y * scalar, v.z * scalar};
}

Vec3 vec3_normalize(Vec3 v) {
    float length = vec3_length(v);
    if (length == 0.0f) return (Vec3){0.0f, 0.0f, 0.0f};
    return vec3_scale(v, 1.0f / length);
}

float vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float vec3_length(Vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float vec3_length_squared(Vec3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float vec3_distance(Vec3 a, Vec3 b) {
    return vec3_length(vec3_sub(a, b));
}

float vec3_distance_squared(Vec3 a, Vec3 b) {
    return vec3_length_squared(vec3_sub(a, b));
}

// Utility
Vec3 vec3_project(Vec3 a, Vec3 b) {
    float b_length_squared = vec3_length_squared(b);
    if (b_length_squared == 0.0f) return (Vec3){0.0f, 0.0f, 0.0f};
    float scale = vec3_dot(a, b) / b_length_squared;
    return vec3_scale(b, scale);
}

Vec3 vec3_reflect(Vec3 v, Vec3 normal) {
    Vec3 normalized_normal = vec3_normalize(normal);
    return vec3_sub(v, vec3_scale(normalized_normal, 2.0f * vec3_dot(v, normalized_normal)));
}

Vec3 vec3_lerp(Vec3 a, Vec3 b, float t) {
    return (Vec3){
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t
    };
}
