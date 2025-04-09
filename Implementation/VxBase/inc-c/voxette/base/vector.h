
#ifndef VOXETTE_BASE_VECTOR_H
#define VOXETTE_BASE_VECTOR_H

#include <stdint.h>

typedef struct VxVec2f VxVec2f;
typedef struct VxVec3f VxVec3f;
typedef struct VxVec4f VxVec4f;

typedef struct VxVec2i VxVec2i;
typedef struct VxVec3i VxVec3i;
typedef struct VxVec4i VxVec4i;

struct VxVec2f
{
    float x;
    float y;
};

struct VxVec3f
{
    float x;
    float y;
    float z;
};

struct VxVec4f
{
    float x;
    float y;
    float z;
    float w;
};

struct VxVec2i
{
    int32_t x;
    int32_t y;
};

struct VxVec3i
{
    int32_t x;
    int32_t y;
    int32_t z;
};

struct VxVec4i
{
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
};

VxVec2f vx_new_vec2f(float uni_value);
VxVec3f vx_new_vec3f(float uni_value);
VxVec4f vx_new_vec4f(float uni_value);

VxVec2i vx_new_vec2i(int32_t uni_value);
VxVec3i vx_new_vec3i(int32_t uni_value);
VxVec4i vx_new_vec4i(int32_t uni_value);

bool vx_vec3i_equal(
    const VxVec3i correct,
    const VxVec3i base
);

#endif // VOXETTE_BASE_VECTOR_H

