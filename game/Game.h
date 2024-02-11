#ifndef GAME_H
#define GAME_H

#include "../lib/mylib.h"

#define BRD_SIZE        (8)
#define BRD_NSQUARES    (BRD_SIZE * BRD_SIZE)
#define BRD_BRL_IP      (0)
#define BRD_BRR_IP      (BRD_SIZE - 1)
#define BRD_WRR_IP      (BRD_NSQUARES - 1)
#define BRD_WRL_IP      (BRD_WRR_IP - BRD_SIZE + 1)
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
typedef struct Pos      Pos;
typedef struct BrdInfo  BrdInfo;
typedef unsigned char   castle_info;
typedef enum CLR        CLR;

enum CLR
{
    CLR_WHITE,
    CLR_BLACK,
};


struct Brd
{
    square              board[BRD_NSQUARES];
};

struct Pos
{
    Brd                 brd;
    move                last_move;
    castle_info         wci;
    castle_info         bci;
};

struct BrdInfo
{
    bfd64               w_attack_mask;
    bfd64               b_attack_mask;
    char                w_knig_idx;
    char                b_king_idx;
};

void                    ci_left_rook_moved(castle_info * ci);
void                    ci_right_rook_moved(castle_info * ci);
void                    ci_king_moved(castle_info * ci);
bool                    ci_can_castle_left(castle_info ci);
bool                    ci_can_castle_right(castle_info ci);

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
bool                    square_same_color(square lhs, square rhs);

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
Brd                     Brd_copy(const Brd * brd);
Brd                     Brd_new_after_move(const Brd * brd, move mv);

Pos                     Pos_new_default(void);
void                    Pos_move(Pos * pos, move mv);

BrdInfo                 BrdInfo_compute(const Brd * brd);
bool                    BrdInfo_square_attacked_by_white(const BrdInfo * bi, int idx);
bool                    BrdInfo_square_attacked_by_black(const BrdInfo * bi, int idx);
bool                    BrdInfo_white_in_check(const BrdInfo * bi);
bool                    BrdInfo_black_in_check(const BrdInfo * bi);

bfd64                   mask_Brd(const Brd * board);
bfd64                   mask_white(const Brd * board);
bfd64                   mask_black(const Brd * board);
bfd64                   mask_attack(const Brd * brd, int idx);
bfd64                   mask_attack_row_col(const Brd * brd, int row, int col);
bfd64                   mask_move_row_col(const Brd * brd, int row, int col);
bfd64                   mask_move(const Brd * brd, int idx);

void                    dbg_Brd(const Brd * board);
void                    dbg_mask(bfd64 r);
void                    dbg_mask_numeric(bfd64 msk);
void                    dbg_PosInfo(const BrdInfo * pi);

#endif