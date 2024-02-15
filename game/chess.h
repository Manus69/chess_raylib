#ifndef CHESS_H
#define CHESS_H

#include "../lib/mylib.h"

#define BRD_SIZE        (8)
#define BRD_NSQUARES    (BRD_SIZE * BRD_SIZE)

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


typedef struct Move     Move;
typedef struct Brd      Brd;
typedef struct Pos      Pos;
typedef struct PosAnal  PosAnal;
typedef struct KRSts    KRSts;
typedef enum   CLR      CLR;

enum CLR
{
    CLR_WHITE,
    CLR_BLACK,
    CLR_COUNT,
};

struct Move
{
    char from;
    char to;
};

struct Brd
{
    char                cstr[BRD_NSQUARES];
};

struct PosAnal
{
    bfd64               attack_mask[CLR_COUNT];
    char                material[CLR_COUNT];
    char                king_idx[CLR_COUNT];
};

struct KRSts
{
    unsigned char       sts[CLR_COUNT];
};

struct Pos
{
    PosAnal             anal;
    Brd                 brd;
    KRSts               kr_sts;
    Move                last_move;
};

Rslt_(Pos)
Pos         Pos_from_cstr(const char * cstr);
char *      Pos_Brd_get_cstr(const Pos * pos);
Rslt_Pos    Pos_try_move(const Pos * pos, Move mv);

void dbg_mask(bfd64 mask);

#endif