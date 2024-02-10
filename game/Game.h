#ifndef GAME_H
#define GAME_H

#include "../lib/mylib.h"

#define BRD_NO_IDX      (0xFF)
#define BRD_SIZE        (8)
#define BRD_NSQUARES    (BRD_SIZE * BRD_SIZE)
#define BRD_FILECHAR    'a'
#define BRD_WR          'r'
#define BRD_WN          'n'
#define BRD_WB          'b'
#define BRD_WQ          'q'
#define BRD_WK          'k'
#define BRD_WP          'p'
#define BRD_BR          'R'
#define BRD_BN          'N'
#define BRD_BB          'B'
#define BRD_BQ          'Q'
#define BRD_BK          'K'
#define BRD_BP          'P'
#define BRD_ES          '_'
#define BRD_DFLT        "RNBQKBNR" \
                        "PPPPPPPP" \
                        "________" \
                        "________" \
                        "________" \
                        "________" \
                        "pppppppp" \
                        "rnbqkbnr"

typedef unsigned short  move;
typedef char            square;
typedef struct Brd      Brd;

struct Brd
{
    square board[BRD_NSQUARES];
};

bool                    square_is_white_piece(square pc);
bool                    square_is_black_piece(square pc);
bool                    square_no_piece(square pc);
bool                    square_white_pawn(square pc);

int                     move_get_from(move mv);
int                     move_get_to(move mv);
move                    move_new(int from, int to);

int                     Brd_row_col_idx(int row, int col);
int                     Brd_idx_row(int idx);
int                     Brd_idx_col(int idx);
square *                Brd_get(const Brd * brd, int idx);
square *                Brd_get_row_col(const Brd * brd, int row, int col);
bool                    Brd_white_piece(const Brd * brd, int idx);
bool                    Brd_black_piece(const Brd * brd, int idx);
bool                    Brd_empty_square(const Brd * brd, int idx);
bool                    Brd_white_pawn(const Brd * brd, int idx);
bool                    Brd_white_piece_row_col(const Brd * brd, int row, int col);
bool                    Brd_black_piece_row_col(const Brd * brd, int row, int col);
bool                    Brd_empty_square_row_col(const Brd * brd, int row, int col);
bool                    Brd_white_pawn_row_col(const Brd * brd, int row, int col);
void                    Brd_set(Brd * brd, int idx, square val);
void                    Brd_move_idx(Brd * brd, int from, int to);
void                    Brd_move(Brd * brd, move mv);
Brd                     Brd_new_empty(void);
Brd                     Brd_from_cstr(const char * cstr);
Brd                     Brd_new_default(void);

bfd64                   mask_Brd(const Brd * board);
bfd64                   mask_white(const Brd * board);
bfd64                   mask_black(const Brd * board);
bfd64                   mask_attack_mask(const Brd * brd, int idx);
bfd64                   mask_attack_mask_row_col(const Brd * brd, int row, int col);

void                    dbg_Brd(const Brd * board);
void                    dbg_mask(bfd64 r);
void                    dbg_mask_numeric(bfd64 msk);

#endif