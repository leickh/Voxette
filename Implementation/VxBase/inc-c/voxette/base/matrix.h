
#ifndef VOXETTE_BASE_MATRIX_H
#define VOXETTE_BASE_MATRIX_H

#include <stdint.h>

typedef struct VxMatrix2f VxMatrix2f;
typedef struct VxMatrix3f VxMatrix3f;
typedef struct VxMatrix4f VxMatrix4f;

struct VxMatrix2f
{
    float v[2 * 2];
};

struct VxMatrix3f
{
    float v[3 * 3];
};

struct VxMatrix4f
{
    float v[4 * 4];
};

VxMatrix2f vx_ident_mat2f();
VxMatrix3f vx_ident_mat3f();
VxMatrix4f vx_ident_mat4f();

#endif // VOXETTE_BASE_MATRIX_H

