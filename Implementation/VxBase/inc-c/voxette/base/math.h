
#ifndef VOXETTE_BASE_MATH_H
#define VOXETTE_BASE_MATH_H

#include <stdbool.h>
#include <stdint.h>

#include "matrix.h"
#include "vector.h"

// Comparisons

int64_t vx_min_i64(int64_t first, int64_t second);
int64_t vx_max_i64(int64_t first, int64_t second);

// Angles

float vx_degrees_to_radians(
    float degrees
);

#endif // VOXETTE_BASE_MATH_H

