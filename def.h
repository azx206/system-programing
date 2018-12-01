
#ifndef __DEF__
#define __DEF__

#define TRUE 1
#define FALSE 0

#define wall_symbol '0'
#define player_symbol '1'
#define obstacle_symbol '2'
#define empty_symbol '3'
#define MAP_HEIGHT 10
#define MAP_WIDTH 10

typedef enum Face {UP, RIGHT, DOWN, LEFT} Face;

typedef struct Obstacle {
    int x;
    int y;
    int speed;
    enum Face face;
} Obstacle;

typedef struct Player {
    int x;
    int y;
} Player;

#endif
