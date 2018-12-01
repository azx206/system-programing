#include <curses.h>
#include "def.h"


void print_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
        clear();
        for(int i = 0; i < MAP_HEIGHT; i++)
        {
            for(int j = 0; j < MAP_WIDTH; j++)
            {
                move(i, j);
                addch(map[i][j]);
            }
        }
        refresh();
}
