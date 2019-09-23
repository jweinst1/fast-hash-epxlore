#ifndef FAST_HASH_HASH_INPUT_H
#define FAST_HASH_HASH_INPUT_H

#include <stdlib.h>
#include "hash_parts.h"

typedef struct {
    size_t len;
    uint8_t data*;
} hash_input_t;

int hash_input_init(hash_input_t* input, size_t length);

#endif // FAST_HASH_HASH_INPUT_H
