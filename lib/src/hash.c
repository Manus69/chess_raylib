#include "../mylib.h"

u64 hash_fnv(const char * bytes, i64 size)
{
    const u64   FNV_PRIME = 0x00000100000001B3;
    u64         hash =      0xcbf29ce484222325;

    for (i64 k = 0; k < size; k ++)
    {
        hash = hash ^ bytes[k];
        hash *= FNV_PRIME;
    }

    return hash;
}