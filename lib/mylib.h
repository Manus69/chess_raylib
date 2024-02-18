#ifndef MYLIB_H
#define MYLIB_H

#include <stdint.h>
#include <stdbool.h>

#define NO_IDX      (-1)
#define nl_         (printf("\n"))
#define drf_(T)     * (T *)
#define min(x, y)   ({typeof(x) _x = (x); typeof(y) _y = (y); _x < _y ? _x : _y;})
#define max(x, y)   ({typeof(x) _x = (x); typeof(y) _y = (y); _x < _y ? _y : _x;})

typedef enum STS    STS;
typedef uint64_t    u64;
typedef int64_t     i64;
typedef uint32_t    u32;
typedef uint64_t    bfd64;

enum STS
{
    STS_fucked,
    STS_ok,
};

#define Rslt_(type) \
typedef struct  Rslt_ ## type \
{ \
    type    val; \
    STS     sts; \
}               Rslt_ ## type; \
\
static inline Rslt_ ## type Rslt_ ## type ## _ok(type val) { return (Rslt_ ## type) {val, STS_ok};} \
static inline Rslt_ ## type Rslt_ ## type ## _fucked(void) { return (Rslt_ ## type) {.sts = STS_fucked};}

bool char_is_lower(char x);
bool char_is_upper(char x);

u64 hash_fnv(const unsigned char * bytes, i64 size);
u32 utl_rng_spcg(u64 * state);
u64 utl_rng_xor(u64 * state);

bfd64 bfd64_zeroes(void);
bfd64 bfd64_one(int idx);
bfd64 bfd64_ones(void);
bfd64 bfd64_from_hex(u64 x);
bfd64 bfd64_set(bfd64 * bfd, int idx);
bfd64 bfd64_clear(bfd64 * bfd, int idx);
bfd64 bfd64_toggle(bfd64 * bfd, int idx);
bfd64 bfd64_shift_left(bfd64 * bfd, int shift);
bfd64 bfd64_shift_right(bfd64 * bfd, int shift);
bool bfd64_bit_is_set(bfd64 bfd, int idx);
bfd64 bfd64_union(bfd64 lhs, bfd64 rhs);


void dbg_byte(unsigned char x);
void dbg_bytes(unsigned char * ptr, int size);
void dbg_bfd64(bfd64 x);

#endif