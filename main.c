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
    initscr();  noecho(); nodelay(stdscr, TRUE);
    set_time(); set_left_time(50);

    print_map(map1);
    struct Player player = {1, 1};

    while(1)
    {
	for(int i = 0; i < obstacle_number; i++)
	    move_obstacle(map1, &ob_array[i]);
	char ch = getch();
	player_move(&player, ch, map1);
	
	move(40, 30);
	char buffer[50];
	double ret_left_time = get_left_time();
	if(ret_left_time == 0)
	{
	    // time over
	}
	sprintf(buffer, "left time is : %.2lf\n", ret_left_time);
	addstr(buffer);

	print_obstacles(ob_array, obstacle_number);
	print_player(&player);

	if(check_collision_ob(&player, ob_array, obstacle_number))
	{
	    // if player meets obstacle..
	    time_penalty();
	}

	refresh();
	usleep(500);
    }



    endwin();
    sleep(5);
    return 0;
}
