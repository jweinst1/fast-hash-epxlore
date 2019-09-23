#ifndef FAST_HASH_HASH_PARTS_H
#define FAST_HASH_HASH_PARTS_H

/**
 * Standardize integer sizes.
 */
#ifdef HAVE_STDINT_HEAD
#  include <stdint.h>
#else
#  ifdef _MSC_VER
       typedef __int8 int8_t;
       typedef __int16 int16_t;
       typedef __int32 int32_t;
       typedef __int64 int64_t;
       typedef unsigned __int8 uint8_t;
       typedef unsigned __int16 uint16_t;
       typedef unsigned __int32 uint32_t;
       typedef unsigned __int64 uint64_t;
#   else
       // Running this on c89 might not work right.
       typedef char int8_t;
       typedef short int16_t;
       typedef int int32_t;
       typedef long int64_t;
       typedef unsigned char uint8_t;
       typedef unsigned short uint16_t;
       typedef unsigned int uint32_t;
       typedef unsigned long uint64_t;
#   endif
#endif

/**
 * Make hash steps a little more visible
 */
#define HP_LSHIFT(a, n) ((a) << (n))
#define HP_RSHIFT(a, n) ((a) >> (n))
#define HP_CLAMP_8BITS(a) ((a) & 0xff)
#define HP_CLAMP_16BITS(a) ((a) & 0xffff)

#define HP_GET_BIT(a, i) (((a) >> (i)) & 1)


#endif // FAST_HASH_HASH_PARTS_H
