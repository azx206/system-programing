#include "def.h"

void print_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
  clear();

  for(int i = 0; i < MAP_HEIGHT; i++)
  {
    for(int j = 0; j < MAP_WIDTH; j++)
    {
      move(i, j); addch(map[i][j]);
    }
  }

  refresh();
}

void reset(struct Object* obj, char map[MAP_HEIGHT][MAP_WIDTH])
{
  move(obj->x, obj->y);
  addch(map[obj->x][obj->y]);
}

void draw(struct Object* obj)
{
  move(obj->x, obj->y);
  standout();
  if(obj->type == PLAYER)
  {
    addch(PLAYER_SYMBOL);
  }
  else
  {
    addch(ENEMY_SYMBOL);
  }
  standend();
}

int check_move(char map[MAP_HEIGHT][MAP_WIDTH], struct Position* pos)
{
  int x = pos->x;
  int y = pos->y;
  if(x < 0 || y < 0 || x >= MAP_HEIGHT || y >= MAP_WIDTH) return FALSE;

  if(map[x][y] == WALL_SYMBOL) return FALSE;
  if(map[x][y] == PORTAL_SYMBOL) return FALSE;
  if(map[x][y] == END_SYMBOL) return FALSE;
//  if(map[x][y] == QUIZ_SYMBOL) return FALSE;

  return TRUE;
}

void set_timer(struct timeval* timer)
{
  gettimeofday(timer, NULL);
}

long long get_elapsed_time(struct timeval* timer)
{
  struct timeval temp;
  gettimeofday(&temp, NULL);

  long long cur = temp.tv_sec * 1000 * 1000 + temp.tv_usec;
  long long start = timer->tv_sec * 1000 * 1000 + timer->tv_usec;

  return cur - start;
}

void cap_frame(long long elapsed_time)
{
  if(elapsed_time >= 1000 * 1000) return;
  unsigned int sleep_time = 1000 * 1000 - elapsed_time;
  usleep(sleep_time);
}

void random_walk(char map[MAP_HEIGHT][MAP_WIDTH], struct Object* obj)
{
  static const int dx[4] = {0, 1, 0, -1};
  static const int dy[4] = {1, 0, -1, 0};
  static const int possible_move[4][4] = {
    {3, 0, 1, 2},
    {0, 1, 2, 3},
    {1, 2, 3, 4},
    {2, 3, 0, 1}
  };

  srand(time(NULL));

  int i;
  int cnt = 0;
  struct Position pos;
  do {
    i = possible_move[obj->face][rand() % 3];
    pos.x = obj->x + dx[i];
    pos.y = obj->y + dy[i];
    ++cnt;
    if(cnt > 5)
    {
      i = possible_move[obj->face][3];
      break;
    }
  } while(check_move(map, &pos) == FALSE);

  obj->x = pos.x;
  obj->y = pos.y;
  obj->face = i;
}

int collision_detect(struct Object* player, struct Object* enemy_array, int enemy_number)
{
  for(int i = 0; i < enemy_number; i++)
  {
    if(player->x == enemy_array[i].x && player->y == enemy_array[i].y) return TRUE;
  }
  return FALSE;
}

void key_handling(char input, struct Object* player, char map[MAP_HEIGHT][MAP_WIDTH])
{
  int i = -1;
  switch (input)
  {
    case 'd':
    i = 0;
    break;
    case 's':
    i = 1;
    break;
    case 'a':
    i = 2;
    break;
    case 'w':
    i = 3;
    break;
  }
  if(i == -1) return;

  static const int dx[4] = {0, 1, 0, -1};
  static const int dy[4] = {1, 0, -1, 0};
  int nx = player->x + dx[i];
  int ny = player->y + dy[i];
  if(nx < 0 || ny < 0 || nx >= MAP_HEIGHT || ny >= MAP_WIDTH) return;

  if(map[nx][ny] == WALL_SYMBOL) return;
  reset(player, map);
  //move(player->x, player->y); addch(EMPTY_SYMBOL);
  player->x = nx; player->y = ny;
  draw(player);
  //move(player->x, player->y); addch(PLAYER_SYMBOL);
}

int portal_warp(char symbol, struct Object* player)
{
  if(symbol == PORTAL_SYMBOL) return TRUE;
  return FALSE;
}

int end_warp(char symbol, struct Object* player, int solved)
{
  if(solved == TOTAL_PROBLEMS && symbol == END_SYMBOL) return TRUE;
  return FALSE;
}

int quiz_collision()
{
  return FALSE;
}

long long time_penalty(int flag, long long penalty)
{
  static long long ret = 0;
  if(flag == SET)
  {
    ret += penalty;
    move(PENALTY_X, PENALTY_Y); addstr("                                        ");
    addstr("[RECENT PENALTY]: decrease left time!");
  }
  return ret;
}

void set_new_penalty(int* enemy_speed, int* enemy_number)
{
  srand(time(NULL));
  int i = rand() % 4;

  char buffer[4][70] = {
    "[RECENT PENALTY]: increase enemy speed and number!",
    "[RECENT PENALTY]: increase enemy speed!",
    "[RECENT PENALTY]: increase enemy number!"
    "[RECENT PENALTY]: NON-Penalty!"
  };
  move(PENALTY_X, PENALTY_Y); addstr("                                        ");
  addstr(buffer[i]);

  if(i == 3) return;

  switch(i)
  {
    case 0:
    case 1:
    if(*enemy_speed > 0.1 * 1000 * 1000) (*enemy_speed) /= 2;
    if(i == 1) break;
    case 2:
    if(*enemy_number < ENEMY_MAX) ++(*enemy_number);
    break;
  }
}
