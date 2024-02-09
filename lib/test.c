#include "mylib.h"
#include <string.h>
#include <stdio.h>

void hash_test()
{
    char * x = "test";
    u64 hash = hash_fnv(x, strlen(x));
    printf("%zu\n", hash);
}

void dbg_test()
{
    // unsigned char x = 0b1101;
    // dbg_byte(x);

    u64 x = 0xFF01;
    dbg_bytes((unsigned char *) & x, sizeof(x));
}

void bfd_test()
{
    bfd64 x = bfd64_ones();
    bfd64 y = bfd64_toggle(& x, 63);
    bfd64_toggle(& x, 63);
    dbg_bfd64(x);
    dbg_bfd64(y);
}

int main()
{
    // hash_test();
    // dbg_test();
    bfd_test();

    return 0;
}