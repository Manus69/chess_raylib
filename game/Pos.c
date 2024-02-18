#include "_private.h"

char Pos_at(const Pos * pos, int idx)
{
    return * Brd_get(& pos->brd, idx);
}

char Pos_at_rc(const Pos * pos, int row, int col)
{
    return Pos_at(pos, transform_rc_idx(row, col));
}

CLR Pos_clr_at(const Pos * pos, int idx)
{
    return CLR_get(Pos_at(pos, idx));
}

CLR Pos_clr_at_rc(const Pos * pos, int row, int col)
{
    return Pos_clr_at(pos, transform_rc_idx(row, col));
}

Pos Pos_new_from_cstr(const char * cstr, CLR turn, Move last_move, KRSts kr_sts)
{
    Brd     brd;
    PosAnal pa;
    
    brd = Brd_from_cstr(cstr);
    pa = PosAnal_compute(& brd);

    return (Pos)
    {
        .anal = pa,
        .brd = brd,
        .last_move = last_move,
        .turn = turn,
        .kr_sts = kr_sts,
    };
}

Pos Pos_new_default(void)
{
    return Pos_new_from_cstr(BRD_DFLT, CLR_WHITE, Move_none(), KRSts_default());
}

char * Pos_Brd_get_cstr(const Pos * pos)
{
    return (char *) pos->brd.cstr;
}

bool Pos_in_check(const Pos * pos, CLR clr)
{
    return bfd64_bit_is_set(pos->anal.attack_mask[! clr], pos->anal.king_idx[clr]);
}