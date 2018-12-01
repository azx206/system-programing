#ifndef __MOVES__
#define __MOVES__

#include <curses.h>
#include "def.h"

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int possible_direction[4][3] = {
    {3, 0, 1},
    {0, 1, 2},
    {1, 2, 3},
    {2, 3, 0}
};

void set_new_position(struct Obstacle *ob, Position *pos);
void print_obstacles(Obstacle* ob_array, int obstacle_number);
void move_obstacle(char map[MAP_HEIGHT][MAP_WIDTH], struct Obstacle *ob);
int check_move(char map[MAP_HEIGHT][MAP_WIDTH], int nx, int ny);
void player_move(struct Player *player, char ch, char map[MAP_HEIGHT][MAP_WIDTH]);
void print_player(struct Player *player);


#endif
