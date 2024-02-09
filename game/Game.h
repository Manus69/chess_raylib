#ifndef GAME_H
#define GAME_H

#include "../lib/mylib.h"

#define BRD_SIZE        (8)
#define BRD_NSQUARES    (BRD_SIZE * BRD_SIZE)
#define BRD_FILECHAR    'a'
#define SQ_WR           'r'
#define SQ_WN           'n'
#define SQ_WB           'b'
#define SQ_WQ           'q'
#define SQ_WK           'k'
#define SQ_WP           'p'
#define SQ_BR           'R'
#define SQ_BN           'N'
#define SQ_BB           'B'
#define SQ_BQ           'Q'
#define SQ_BK           'K'
#define SQ_BP           'P'
#define SQ_ES           '_'
#define BRD_DFLT        "RNBQKBNR" \
                        "PPPPPPPP" \
                        "________" \
                        "________" \
                        "________" \
                        "________" \
                        "pppppppp" \
                        "rnbqkbnr"

typedef unsigned char   brd_idx;
typedef unsigned short  move;
typedef char            square;
typedef bfd64           mask;
typedef struct Brd      Brd;

struct Brd
{
    unsigned char board[BRD_NSQUARES];
};

bool                    square_is_white_piece(square pc);
bool                    square_is_black_piece(square pc);
bool                    square_no_piece(square pc);

brd_idx                 move_from(move mv);
brd_idx                 move_to(move mv);
move                    move_new(brd_idx from, brd_idx to);

square *                Brd_get(const Brd * board, brd_idx n);
square *                Brd_get_row_col(const Brd * board, int row, int col);
square *                Brd_get_rank_file(const Brd * board, int rank, char file);
bool                    Brd_square_empty(const Brd * brd, brd_idx idx);
bool                    Brd_square_white_piece(const Brd * brd, brd_idx idx);
bool                    Brd_square_black_piece(const Brd * brd, brd_idx idx);
void                    Brd_set(Brd * board, brd_idx n, square val);
void                    Brd_set_row_col(Brd * board, int row, int col, square val);
void                    Brd_move_idx(Brd * board, brd_idx from, brd_idx to);
void                    Brd_move(Brd * board, move mv);
u64                     Brd_hash(const Brd * board);
Brd                     Brd_new_empty(void);
Brd                     Brd_copy(const Brd * board);
Brd                     Brd_from_cstr(const char * cstr);
Brd                     Brd_new_default(void);

mask                    mask_mask_Brd(const Brd * board);
mask                    mask_mask_white(const Brd * board);
mask                    mask_mask_black(const Brd * board);

void                    dbg_Brd(const Brd * board);
void                    dbg_mask(mask r);
void                    dbg_mask_numeric(mask msk);

#endif