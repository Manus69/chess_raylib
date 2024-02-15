#include "_private.h"

#define KING        (1)
#define LROOK       (2)
#define RROOK       (4)

#define BRL_IP      (0)
#define BRR_IP      (BRD_SIZE - 1)
#define WRR_IP      (BRD_NSQUARES - 1)
#define WRL_IP      (BRD_WRR_IP - BRD_SIZE + 1)

static void _left_rook_moved(unsigned char * ci)
{
    * ci |= LROOK;
}

static void _right_rook_moved(unsigned char * ci)
{
    * ci |= RROOK;
}

static void _king_moved(unsigned char * ci)
{
    * ci |= KING;
}

static bool _can_castle_left(unsigned char ci)
{
    return ! ((ci & KING) | (ci & LROOK));
}

static bool _can_castle_right(unsigned char ci)
{
    return ! ((ci & KING) | (ci & RROOK));
}

bool Pos_can_castle_left(const Pos * pos, CLR clr)
{
    return _can_castle_left(pos->kr_sts.sts[clr]);
}

bool Pos_can_castle_right(const Pos * pos, CLR clr)
{
    return _can_castle_right(pos->kr_sts.sts[clr]);
}

void Pos_update_KRSts(Pos * pos, Move mv)
{
    CLR     clr;
    char    piece;

    clr = Move_clr(mv);

}