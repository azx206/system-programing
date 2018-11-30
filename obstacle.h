#include <time.h>
#include <stdlib.h>
#define MAX_OBSTACLE 10

struct Obstacle;
typedef enum Face {UP, RIGHT, DOWN, LEFT} Face;

void set_new_position(struct Obstacle *ob);

typedef struct Obstacle {
    int x;
    int y;
    int speed;
    enum Face face;
} Obstacle ;


int obstacle_num = 0;
Obstacle ob_array[MAX_OBSTACLE];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int possible_direction[4][3] = {
    {3, 0, 1}, // UP
    {0, 1, 2}, // RIGHT
    {1, 2, 3}, // DOWN
    {2, 3, 0}
};



void set_new_position(Obstacle *ob)
{
	srand(time(NULL));
	int i = possible_direction[ob->face][rand() % 3];
	int nx = ob->x + dx[i];
	int ny = ob->y + dy[i];
	ob->x = nx;
	ob->y = ny;
}

