#include <curses.h>
#define MAP_HEIGHT 10
#define MAP_WIDTH 10

char map1[MAP_HEIGHT][MAP_WIDTH] = {
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000"
};

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
