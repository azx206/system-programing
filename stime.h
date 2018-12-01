#ifndef STIME
#define STIME

#include <unistd.h>
#include <time.h>

time_t start_time;
double left_time;
const int FRAME_LIMIT = 30;

void set_time();
double get_time();
void set_left_time(double time);
double get_left_time();

void set_time()
{
    time(&start_time);
}

double get_time()
{
    time_t now;
    time(&now);
    
    return (now - start_time);
}

void set_left_time(double time)
{
    left_time = time;
}

double get_left_time()
{
    
    double ret = left_time - get_time();
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
