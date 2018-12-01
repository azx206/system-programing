#include <stdio.h>
#include <stdlib.h>
#include "stime.h"
#include "map.h"
#include "def.h"

const int MAX_OBSTACLE = 3;
int obstacle_number = 1;
int obstacle_speed = 30;
Obstacle ob_array[MAX_OBSTACLE] = {
    {2, 2, UP},
    {3, 3, DOWN},
    {4, 4, LEFT}
};

void quiz_penalty();

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
    initscr();  noecho(); nodelay(stdscr, TRUE); curs_set(0);
    set_time(); set_left_time(50);

    print_map(map1);
    struct Player player = {1, 1, 5};
    int calculated_frame = 0;
    set_cap_time();

    while(1)
    {
	if(FPS_LIMIT % obstacle_speed == 0)
	{
		for(int i = 0; i < obstacle_number; i++)
		    move_obstacle(map1, &ob_array[i]);
	}
	char ch = getch();
	if(FPS_LIMIT % player.speed == 0)
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

	if(FPS_LIMIT % obstacle_speed == 0)
		print_obstacles(ob_array, obstacle_number);
	if(FPS_LIMIT % player.speed == 0)
		print_player(&player);

	if(FPS_LIMIT % obstacle_speed == 0 || FPS_LIMIT % player.speed == 0)
	{
		if(check_collision_ob(&player, ob_array, obstacle_number))
		{
	   	 // if player meets obstacle..
		   	 time_penalty();
		}
	}

	refresh();
	++calculated_frame;
	if(calculated_frame >= 30)
	{
	    calculated_frame = 0;
	    usleep(get_cap_time());
	    set_cap_time();
	}
    }



    endwin();
    sleep(5);
    return 0;
}



void quiz_penalty()
{
    srand(time(NULL));
    enum Penalty penalty = rand() % 4;
    switch (penalty)
    {
	case SPEED:
	    if(obstacle_speed > 5)
	  	  obstacle_speed -= 1;
	    break;
	case NUMBER:
	    if(obstacle_number + 1 <= MAX_OBSTACLE)
	    {
		obstacle_number += 1;
	    }

	    break;
	case SPEED_AND_NUMBER:
	    if(obstacle_speed > 5)
	    	obstacle_speed += 1;
	    if(obstacle_number + 1 <= MAX_OBSTACLE)
	    {
		obstacle_number += 1;
	    }
	    break;
	case NONE:
	    break;
    }
}
