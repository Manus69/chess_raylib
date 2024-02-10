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

bool                    square_white_piece(square sqr);
bool                    square_black_piece(square sqr);
bool                    square_no_piece(square sqr);
bool                    square_white_pawn(square sqr);
bool                    square_white_rook(square sqr);
bool                    square_white_knight(square sqr);
bool                    square_white_bishop(square sqr);
bool                    square_white_queen(square sqr);
bool                    square_white_king(square sqr);
bool                    square_black_pawn(square sqr);
bool                    square_black_rook(square sqr);
bool                    square_black_knight(square sqr);
bool                    square_black_bishop(square sqr);
bool                    square_black_queen(square sqr);
bool                    square_black_king(square sqr);
bool                    square_rook(square sqr);
bool                    square_knight(square sqr);
bool                    square_bishop(square sqr);
bool                    square_queen(square sqr);
bool                    square_king(square sqr);

int                     move_get_from(move mv);
int                     move_get_to(move mv);
move                    move_new(int from, int to);

int                     Brd_row_col_idx(int row, int col);
int                     Brd_idx_row(int idx);
int                     Brd_idx_col(int idx);
int                     Brd_idx_shift(int idx, int n_rows, int n_cols);
bool                    Brd_idx_valid(int idx);
bool                    Brd_row_col_valid(int row, int col);
bool                    Brd_last_row(int row);
bool                    Brd_last_col(int col);
bool                    Brd_row_margin2(int row);
bool                    Brd_col_margin2(int col);
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
void                    Brd_set_row_col(Brd * brd, int row, int col, square val);
void                    Brd_move_idx(Brd * brd, int from, int to);
void                    Brd_move(Brd * brd, move mv);
Brd                     Brd_new_empty(void);
Brd                     Brd_from_cstr(const char * cstr);
Brd                     Brd_new_default(void);

bfd64 mask_shift(bfd64 * mask, int vert, int hor);
bfd64                   mask_Brd(const Brd * board);
bfd64                   mask_white(const Brd * board);
bfd64                   mask_black(const Brd * board);
bfd64                   mask_attack_mask(const Brd * brd, int idx);
bfd64                   mask_attack_mask_row_col(const Brd * brd, int row, int col);

void                    dbg_Brd(const Brd * board);
void                    dbg_mask(bfd64 r);
void                    dbg_mask_numeric(bfd64 msk);

#endif