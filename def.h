#ifndef __DEF__
#define __DEF__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <sys/time.h>
#include <aio.h>

#define FPS_LIMIT 60

#define MAP_HEIGHT 30
#define MAP_WIDTH 30

#define TRUE 1
#define FALSE 0

#define EMPTY_SYMBOL '.'
#define WALL_SYMBOL 'W'
#define PLAYER_SYMBOL 'P'
#define ENEMY_SYMBOL 'E'
#define QUIZ_SYMBOL 'Q'
#define PORTAL_SYMBOL '|'
#define END_SYMBOL 'E'
#define LEFT_TIME 30 * 60 * 1000 * 1000

#define ENEMY_MAX 3
#define TOTAL_PROBLEMS 10
#define MAX_SPEED

#define GET 1
#define SET 2

#define PENALTY_X 2
#define PENALTY_Y 40

#define QUIZ_X 4
#define QUIZ_Y 40

enum FACE {UP, RIGHT, DOWN, LEFT, NIL};
enum TYPE {PLAYER, ENEMY};

struct Object {
  int x;
  int y;
  enum FACE face;
  enum TYPE type;
};

struct Position {
  int x;
  int y;
};

void print_map(char map[MAP_HEIGHT][MAP_WIDTH]);

void reset(struct Object* obj, char map[MAP_HEIGHT][MAP_WIDTH]);

void draw(struct Object* obj);

int check_move(char map[MAP_HEIGHT][MAP_WIDTH], struct Position* pos);

void set_timer(struct timeval* timer);

long long get_elapsed_time(struct timeval* timer);

void cap_frame(long long elapsed_time);

void random_walk(char map[MAP_HEIGHT][MAP_WIDTH], struct Object* obj);

int collision_detect(struct Object* player, struct Object* enemy_array, int enemy_number);

void key_handling(char input, struct Object* player, char map[MAP_HEIGHT][MAP_WIDTH]);

int portal_warp(char symbol, struct Object* player);

int end_warp(char symbol, struct Object* player, int solved);

int quiz_collision();

long long time_penalty(int flag, long long penalty);

void set_new_penalty(int* enemy_speed, int* enemy_number);

#endif
