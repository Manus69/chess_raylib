#ifndef GUI_H
#define GUI_H

#include <raylib.h>
#include "../lib/mylib.h"

#define GUI_MAX_PC      (32)
#define GUI_GRID_SIZE   (8)
#define GUI_TFPS        (30)
#define GUI_TX_PATH     "./ass/textures.png"

enum GUI_PC
{
    GUI_PC_NONE,
    GUI_PC_WR,
    GUI_PC_WN,
    GUI_PC_WB,
    GUI_PC_WQ,
    GUI_PC_WK,
    GUI_PC_WP,
    GUI_PC_BR,
    GUI_PC_BN,
    GUI_PC_BB,
    GUI_PC_BQ,
    GUI_PC_BK,
    GUI_PC_BP,
    GUI_PC_COUNT,
};

typedef struct  GuiLayout   GuiLayout;
typedef struct  TxLayout    TxLayout;
typedef struct  Piece       Piece;
typedef struct  Board       Board;
typedef struct  Gui         Gui;
typedef struct  Input       Input;
typedef enum    GUI_PC      GUI_PC;

struct GuiLayout
{
    Rectangle window;
    Rectangle board;
};

struct TxLayout
{
    Rectangle board;
    Rectangle piece[GUI_PC_COUNT];
};

struct Piece
{
    GUI_PC      type;
    Vector2     xy;
    Vector2     xy_initial;
};

struct Board
{
    Piece       pieces[GUI_MAX_PC];
    Vector2     board_grid[GUI_GRID_SIZE][GUI_GRID_SIZE];
    float       square_size;
    int         n_pieces;
};

struct Input
{
    int         active_idx;
};

struct Gui
{
    Texture2D   texture;
    GuiLayout   gui_layout;
    TxLayout    tx_layout;
    Board       board;
    Input       input;
};

bool Piece_no_piece(const Piece * piece);
void Piece_reset(Piece * piece);
void Piece_shift(Piece * piece, float dx, float dy);
void Piece_move(Piece * piece, Vector2 xy);
void Piece_move_center(Piece * piece, Vector2 xy, float radius);

Board Board_init(const GuiLayout * layout);
void Board_place(Board * board, int row, int col, GUI_PC piece);
int Board_piece_hovered(const Board * board, Vector2 xy);
Piece * Board_get(const Board * board, int idx);

Gui Gui_init(GuiLayout gl, TxLayout txl, const char * tx_path);
void Gui_kill(Gui * gui);
int Gui_run(void);

void render_Gui(const Gui * gui);


#endif