#include <stdio.h>
#include "stime.h"
#include "map.h"
#include "def.h"

const int MAX_OBSTACLE = 10;
int obstacle_number = 1;
Obstacle ob_array[MAX_OBSTACLE] = { {2, 2, 1, UP} };

char map1[MAP_HEIGHT][MAP_WIDTH] = {
    "0000000000",
    "0333333330",
    "0333333330",
    "0333333330",
    "0333333330",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000"
};

int main(void)
{
    initscr();  noecho();
    nodelay(stdscr, TRUE);
    set_time();
    set_left_time(1000);

    print_map(map1);
    struct Player player = {1, 1};

    while(1)
    {
	for(int i = 0; i < obstacle_number; i++)
	    move_obstacle(map1, &ob_array[i]);
	char ch = getch();
	player_move(&player, ch, map1);
	
	move(30, 30);
	addstr("test!");
	print_obstacles(ob_array, obstacle_number);
	print_player(&player);

	refresh();
	sleep(1);
    }



    endwin();
    return 0;
}
