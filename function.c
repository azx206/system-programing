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
    if(cnt > 10)
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

int quiz_collision(char symbol)
{
  if(symbol == QUIZ_SYMBOL) return TRUE;
  return FALSE;
}

long long time_penalty(int flag, long long penalty)
{
  static long long ret = 0;
  if(flag == SET)
  {
    ret += penalty;
    move(PENALTY_X, PENALTY_Y); addstr(BLANK);
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
  move(PENALTY_X, PENALTY_Y); addstr(BLANK);
  move(PENALTY_X, PENALTY_Y); addstr(buffer[i]);

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

void print_status(int solved, int quiz_number)
{
  char buffer[50];
  sprintf(buffer, "solved: %d, quiz_number: %d", solved, quiz_number);
  move(PROBLEM_STATUS_X, PROBLEM_STATUS_Y); addstr(BLANK);
  move(PROBLEM_STATUS_X, PROBLEM_STATUS_Y); addstr(buffer);
}

void clear_problem()
{
  move(QUIZ_X, QUIZ_Y); addstr(BLANK);
  move(QUIZ_X + 2, QUIZ_Y); addstr(BLANK);
}

void init_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
  for(int i = 0; i < MAP_HEIGHT; i++)
  {
    for(int j = 0; j < MAP_WIDTH; j++)
    {
      if(map[i][j] == '.') map[i][j] = EMPTY_SYMBOL;
    }
  }
}

/* in-joon's work */

void problemSet(struct problem* set)
{
  set[0].state = 1;
	set[0].question = "Which is the principle of, always getting lowest available spot in the file descriptor?";
	set[0].choice = "1. Lowest-Allocated-fd    2. Lowest-Granting-fd    3. Lowest-Available-fd    4. Lowest-initializing-fd";
	set[0].answer = "3";

	set[1].state = 2;
	set[1].question = "What is the library to use 'malloc' in C? fill in the blank, [#include <[    ]>]";
	set[1].answer = "stdlib";

	set[2].state = 1;
	set[2].question = "Which programming language is not object-oriented when first published?";
	set[2].choice = "1. Python    2. Pascal    3. Smalltalk    4. Ruby";
	set[2].answer = "2";

	set[3].state = 2;
	set[3].question = "Which is called [    ] process has completed execution but still has an entry in the process table?";
	set[3].answer = "zombie";

	set[4].state = 1;
	set[4].question = "Which is a state that each member of a group is wating for some other member to take action?";
	set[4].choice = "1. Deadlock    2. Semaphore    3. Inconsistency    4. Mutex";
	set[4].answer = "1";

	set[5].state = 2;
	set[5].question = "Which is called [    ] signal caused by events outside the process?";
	set[5].answer = "asynchronous";

	set[6].state = 1;
	set[6].question = "Which is the command of printing the full pathname of the current working directory in Unix?";
	set[6].choice = "1. ls    2. pwd    3. mkdir    4. cd";
	set[6].answer = "2";

	set[7].state = 1;
	set[7].question = "Who is the first developer of Linux kernel and Git?";
	set[7].choice = "1. Yukihiro Matsumoto    2. Linus Pauling    3. James Gosling    4. Linus Torvalds";
	set[7].answer = "4";

	set[8].state = 2;
	set[8].question = "What is animal of mascot of Linux?";
	set[8].answer = "penguin";

	set[9].state = 1;
	set[9].question = "What is name of <System-Programming>'s Professor?";
	set[9].choice = "1. Yoon-Ja Choi    2. Jae-Suk Jang    3. Eun-Kyung Ryu    4. Yong-Ju Lee";
  set[9].answer = "3";
}

void problemPrint(struct problem* quiz)
{
  move(QUIZ_X, QUIZ_Y); addstr(BLANK);
  move(QUIZ_X, QUIZ_Y); addstr(quiz->question);
  if(quiz->state == 1)
  {
    move(QUIZ_X + 2, QUIZ_Y); addstr(BLANK);
    move(QUIZ_X + 2, QUIZ_Y); addstr(quiz->choice);
  }
  refresh();
}
