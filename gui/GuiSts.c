#include "_private.h"

GuiSts GuiSts_move(char from, char to)
{
    return (GuiSts)
    {
        .from = from,
        .to = to,
        .move = true,
    };
}

GuiSts GuiSts_no_move(void)
{
    return (GuiSts)
    {
        .move = false,
    };
}