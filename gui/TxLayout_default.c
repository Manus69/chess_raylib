#include "Gui.h"

#define BRD_OFFX    200
#define BRD_OFFY    200
#define BRD_SIZE    800
#define PC_SIZE     100

const TxLayout TXL_DFLT = 
{
    .board = (Rectangle)
    {
        .x = BRD_OFFX,
        .y = BRD_OFFY,
        .height = BRD_SIZE,
        .width = BRD_SIZE,
    },
    .piece[GUI_PC_WR] = {1000, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_WN] = {1100, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_WB] = {1200, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_WQ] = {1300, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_WK] = {1400, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_WP] = {1500, 200, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BR] = {1000, 300, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BN] = {1100, 300, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BB] = {1200, 300, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BQ] = {1300, 300, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BK] = {1400, 300, PC_SIZE, PC_SIZE},
    .piece[GUI_PC_BP] = {1500, 300, PC_SIZE, PC_SIZE},
};
