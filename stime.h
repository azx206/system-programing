#ifndef STIME
#define STIME

#include <unistd.h>
#include <time.h>

time_t start_time;
double left_time;
struct timeval start_cap_time;
struct timeval end_cap_time;
const int reduce_time = 5;
int reduce = 0;

void set_time();
double get_time();
void set_left_time(double time);
double get_left_time();
void set_cap_time();
int get_cap_time();

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
    
    double ret = left_time - get_time() - reduce * reduce_time;
    if(ret < 0) ret = 0;

    return ret;
}
void time_penalty()
{
    ++reduce;
}

void set_cap_time() // 현재 시간을 밀리세컨드로 저장
{
    gettimeofday(&start_cap_time, NULL);
}

int get_cap_time() // 1초 - 현재까지 흐른 시간을 밀리세컨드로 반환
{
    gettimeofday(&end_cap_time, NULL);
    int diff = (end_cap_time.tv_sec - start_cap_time.tv_sec) * 1000000;
    diff += (end_cap_time.tv_usec - start_cap_time.tv_usec);
    int ret = 1000000 - diff;
    if(ret < 0) ret = 0;
    return ret;
}

#endif
