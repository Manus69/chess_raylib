#include <stdio.h>
#include <string.h>
#include "../mylib.h"

void dbg_byte(unsigned char x)
{
    unsigned char   buff[__CHAR_BIT__];
    
    memset(buff, '0', sizeof(buff));
    for (int k = __CHAR_BIT__ - 1; k >= 0; k --)
    {
        buff[k] = x & 1 ? '1' : '0';
        x >>= 1;
    }

    printf("%.*s", __CHAR_BIT__, buff);
}

void dbg_bytes(unsigned char * ptr, int size)
{
    for (int k = 0; k < size; k ++)
    {
        dbg_byte(ptr[k]);
        printf(" ");
    }
}

void dbg_bfd64(bfd64 x)
{
    for (u64 k = 0; k < __CHAR_BIT__ * sizeof(x); k ++)
    {
        printf("%c", (x & (1ul << k)) ? '1' : '0');
    }
    nl_;
}