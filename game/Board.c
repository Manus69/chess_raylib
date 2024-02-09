#include "Game.h"
#include "../lib/mylib.h"
#include <string.h>

static inline brd_idx row_col_to_sqidx(int row, int col)
{
    return row * BRD_SIZE + col;
}

static inline int rank_to_row(int rank)
{
    return BRD_SIZE - rank;
}

static inline char file_to_col(char file)
{
    return file - BRD_FILECHAR;
}

static inline brd_idx rank_file_to_sqidx(int rank, char file)
{
    return row_col_to_sqidx(rank_to_row(rank), file_to_col(file));
}

square * Brd_get(const Brd * board, brd_idx n)
{
    return (square *) board->board + n;
}

square * Brd_get_row_col(const Brd * board, int row, int col)
{
    return Brd_get(board, row_col_to_sqidx(row, col));
}

square * Brd_get_rank_file(const Brd * board, int rank, char file)
{
    return Brd_get(board, rank_file_to_sqidx(rank, file));
}

bool Brd_square_empty(const Brd * brd, brd_idx idx)
{
    return square_no_piece(* Brd_get(brd, idx));
}

bool Brd_square_white_piece(const Brd * brd, brd_idx idx)
{
    return square_is_white_piece(* Brd_get(brd, idx));
}

bool Brd_square_black_piece(const Brd * brd, brd_idx idx)
{
    return square_is_black_piece(* Brd_get(brd, idx));
}

void Brd_set(Brd * board, brd_idx n, square val)
{
    drf_(square) Brd_get(board, n) = val;
}

void Brd_set_row_col(Brd * board, int row, int col, square val)
{
    Brd_set(board, row_col_to_sqidx(row, col), val);
}

void Brd_move_idx(Brd * board, brd_idx from, brd_idx to)
{
    square * val;

    val = Brd_get(board, from);
    Brd_set(board, to, * val);
    * val = SQ_ES;
}

void Brd_move(Brd * board, move mv)
{
    Brd_move_idx(board, move_from(mv), move_to(mv));
}

u64 Brd_hash(const Brd * board)
{
    return hash_fnv(board->board, BRD_NSQUARES);
}

Brd Brd_new_empty(void)
{
    Brd board;

    memset(board.board, SQ_ES, BRD_NSQUARES);
    return board;
}

Brd Brd_copy(const Brd * board)
{
    Brd copy;

    memcpy(copy.board, board->board, BRD_NSQUARES);
    return copy;
}

Brd Brd_from_cstr(const char * cstr)
{
    Brd board;

    memcpy(board.board, cstr, BRD_NSQUARES);
    return board;
}

Brd Brd_new_default(void)
{
    return Brd_from_cstr(BRD_DFLT);
}