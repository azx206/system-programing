#include <stdio.h>
#include "stime.h"
#include "obstacle.h"
#include "player.h"
#include "map.h"

int main(void)
{
    initscr();
    set_time();
    set_left_time(1000);

    print_map(map1);

    while(1)
    {
	
//	printf("%d\n", get_left_time());
    }



    endwin();
    return 0;
}
