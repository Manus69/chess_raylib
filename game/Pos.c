#include "Game.h"

Pos Pos_new_default(void)
{
    return (Pos)
    {
        .brd = Brd_new_default(),
    };
}

CLR Pos_turn(const Pos * pos)
{
    int idx;

    if (pos->last_move == 0) return CLR_WHITE;

    idx = move_get_to(pos->last_move);
    if (square_white_piece(* Brd_get(& pos->brd, idx))) return CLR_BLACK;

    return CLR_WHITE;
}

bool Pos_is_capture(const Pos * pos, move mv)
{
    square from;
    square to;

    from = * Brd_get(& pos->brd, move_get_from(mv));
    to = * Brd_get(& pos->brd, move_get_to(mv));

    return (square_white_piece(from) && square_black_piece(to)) ||
            (square_black_piece(from) && square_white_piece(to));
}

static bool _right_piece_color(CLR clr, square sqr)
{
    return (clr == CLR_WHITE && square_white_piece(sqr)) ||
            (clr == CLR_BLACK && square_black_piece(sqr));
}

static bool _legal_after_move(const Pos * pos, move mv, CLR clr)
{
    Brd     new_brd;
    BrdInfo brd_info;

    new_brd = Brd_new_after_move(& pos->brd, mv);
    brd_info = BrdInfo_compute(& new_brd);

    if (clr == CLR_WHITE) return ! BrdInfo_white_in_check(& brd_info);
    if (clr == CLR_BLACK) return ! BrdInfo_black_in_check(& brd_info);

    return false;
}

bool Pos_move_legal(const Pos * pos, move mv)
{
    CLR     turn;
    square  from;
    square  to;
    bfd64   mask;

    from = * Brd_get(& pos->brd, move_get_from(mv));
    to = * Brd_get(& pos->brd, move_get_to(mv));
    turn = Pos_turn(pos);

    if (square_no_piece(from))                          return false;
    if (! _right_piece_color(turn, from))               return false;
    if (square_same_color(from, to))                    return false;

    mask = Pos_is_capture(pos, mv) ? mask_attack(& pos->brd, move_get_from(mv)) : mask_move(& pos->brd, move_get_from(mv));

    if (! (mask & move_get_to(mv)))                     return false;
    
    return _legal_after_move(pos, mv, turn); //this is bad (brdinfo will have to be recomputed)
}

static void _ci_update(Pos * pos, move mv)
{
    int from;

    from = move_get_from(mv);

    if      (square_white_king(* Brd_get(& pos->brd, from))) ci_king_moved(& pos->wci);
    else if (square_black_king(* Brd_get(& pos->brd, from))) ci_king_moved(& pos->bci);
    else if (from == BRD_WRL_IP)                             ci_left_rook_moved(& pos->wci);
    else if (from == BRD_WRR_IP)                             ci_right_rook_moved(& pos->wci);
    else if (from == BRD_BRL_IP)                             ci_left_rook_moved(& pos->bci);
    else if (from == BRD_BRR_IP)                             ci_right_rook_moved(& pos->bci);
}

static void _handle_promotions(Pos * pos, move mv)
{
    int to;

    to = move_get_to(mv);

    if      (Brd_idx_row(to) == 0 && square_white_pawn(* Brd_get(& pos->brd, to)))          Brd_set(& pos->brd, to, BRD_WQ);
    else if (Brd_last_row(Brd_idx_row(to)) && square_black_pawn(* Brd_get(& pos->brd, to))) Brd_set(& pos->brd, to, BRD_BQ);
}

void Pos_move(Pos * pos, move mv)
{
    _ci_update(pos, mv);
    Brd_move(& pos->brd, mv);
    _handle_promotions(pos, mv);

    pos->last_move = mv;
}