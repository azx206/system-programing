#ifndef STIME
#define STIME

#include <unistd.h>
#include <time.h>

clock_t start_time;
unsigned int left_time;
const int FRAME_LIMIT = 30;

void set_time();
unsigned int get_time();
void set_left_time(unsigned int time);
unsigned int get_left_time();

void set_time()
{
    start_time = clock();
}

unsigned int get_time()
{
    clock_t now = clock();
    
    return ((now - start_time) / CLOCKS_PER_SEC);
}

void set_left_time(unsigned int time)
{
    left_time = time;
}

unsigned int get_left_time()
{
    unsigned int ret = left_time - get_time();
    if(ret < 0) ret = 0;

    return ret;
}

void cap_fps(int frames)
{
	if(frames > FRAME_LIMIT)
	{
	//	usleep();
	}
}

#endif
