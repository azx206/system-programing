#include "stime.h"
#include <stdio.h>

int main(void)
{
    set_time();
    set_left_time(1000);
    while(1)
    {
	printf("%d\n", get_left_time());
    }

    return 0;
}
