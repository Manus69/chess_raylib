#include "_private.h"

#define BRD_OFFX    200
#define BRD_OFFY    200
#define BRD_SIZE    800
#define PC_SIZE     100

const TxLayout TXL_DFLT = 
{
    .obj[GUI_OBJ_BOARD] = (Rectangle)
    {
        .x = BRD_OFFX,
        .y = BRD_OFFY,
        .height = BRD_SIZE,
        .width = BRD_SIZE,
    },
    .obj[GUI_OBJ_WR] = {1000, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_WN] = {1100, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_WB] = {1200, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_WQ] = {1300, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_WK] = {1400, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_WP] = {1500, 200, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BR] = {1000, 300, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BN] = {1100, 300, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BB] = {1200, 300, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BQ] = {1300, 300, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BK] = {1400, 300, PC_SIZE, PC_SIZE},
    .obj[GUI_OBJ_BP] = {1500, 300, PC_SIZE, PC_SIZE},
};
