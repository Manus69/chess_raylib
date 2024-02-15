#include "_private.h"

#define BORDER      (10)
#define MIN_SIZE    (500)

static float _square_size(float board_size)
{
    return board_size / GUI_GRID_SIZE;
}

static Rectangle _get_board(Rectangle window)
{
    float size;

    size = min(window.width, window.height);
    size -= 2 * BORDER;

    return (Rectangle)
    {
        .x = BORDER,
        .y = BORDER,
        .height = size,
        .width = size,
    };
}

Layout Layout_default(int ww, int wh)
{
    Rectangle window;
    Rectangle board;

    ww = max(ww, MIN_SIZE);
    wh = max(wh, MIN_SIZE);

    window = (Rectangle) {0, 0, ww, wh};
    board = _get_board(window);

    return (Layout)
    {
        .board = board,
        .window = window,
        .square_size = _square_size(board.width),
    };
}
