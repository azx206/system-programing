#include "def.h"

void input_handler();
void enemy_movement_handler();
void set_enemy_timer();
int enemy_number;
int enemy_speed;
int current_map;
int solved;
int quiz_number;
char current_symbol;

char map1[MAP_HEIGHT][MAP_WIDTH] = {
  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
  "WQ....W...............WW...WWW",
  "W.W.W...W.WW.W.W.W..W.WW.W..WW",
  "W.W.W.WWWWWW...W...WW....WW.WW",
  "W...W.....WW.WWWWW..W.WW..W..W",//5
  "W.WWWWW.W......WWWW....WW.WW.W",
  "W...W...WWW.W..W.....WQ.W....W",
  "W.W.W.W.WWW.WW...WW.WWW.WW.WWW",
  "W.W.W.W..WW.WW.W.WW..W..WW..WW",
  "W.....WW.......W....WW.WWWW..W",//10
  "W.WWW.W.Q.W.WWWWWWW.W........W",
  "W.WWW.W.W......W......WWWWW..W",
  "W.........W..W.W.W..W.......WW",
  "WW.WWWWWWWWW...W.W.WWWWWWWW.QW",
  "W.........W..W...W..W........W",//15
  "W.W.WWWWW...WW.W.WW...W.WW.WWW",
  "W.......W.W....W...W..W.W....W",
  "W.W.W.W...W..WWWWW..W...WWWW.W",
  "W.W...WW.WWW...W...WWW.WW....W",
  "W.W.WWWW.WW..W.W.W..W..W...W.W",//20
  "W.....WW....WW...WW...W..W.W.W",
  "W.WWW....WW....W....W..W.W...W",
  "W.WW..WW.WWW.W.W.W.WWW.W.W.WWW",
  "W....W....W....W....WW...W...W",
  "W.WW.W.WW.W.WWWWWWW....WWWWW.W",//25
  "W...Q..W.......W.....W...W...W",
  "WW.WWW...W.WWW.W.W.W.W.W.W.W.W",
  "WW..WW.W.W...W.W.W...W.W.W.W.W",
  "WWW........W.......W...W.....|",
  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"//30
};

char map2[MAP_HEIGHT][MAP_WIDTH] = {
  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
  "W.......WW................WW.|",
  "W.W..WW....WW.W.W.W.WWWWW....W",
  "W.WW..WW.WWW..W.W.W....WWW.W.W",
  "W...W....W...WW.Q.WWWW...W...W",//5
  "W.W..WW.WW.W.WW.W..W...W...W.W",
  "W.WW.WW....W.....W...W.WW.W..W",
  "W.W...WWW.WWWW.W..W.WW..W...WW",
  "W...W.WWW..W...WW...WWW.WWW.WW",
  "W.WW....WW...W.WW.W..W....W..W",//10
  "W.WQ.WW..WW.WW.WW.WW...WW..W.W",
  "W.....WW....WW....WWWW.WWW...W",
  "WWW.W..W.W.WW...W..........W.W",
  "W...W.......W.W.WW.W.WWWWW...W",
  "W..W..W.W.W........WQ......WWW",//15
  "W.W..WW.W...W.WW.W.WWW.W.W...W",
  "W.W.W...WWWWW.WW.......W.W.W.W",
  "W.W.W.WWW......WWW.W.W.W...W.W",
  "W.....W...WW.W...W.......WWW.W",
  "W.W.W...WWWW.WWW.WWW.WW.WWWW.W",//20
  "W.....W..W........WW....WW...W",
  "WW.WWWWW.W.W.WW.W..WW.WWW..W.W",
  "W....WW..W....W..W.WW.W...WW.W",
  "W.WW....WW.WW.WW........W..W.W",
  "W.WWW.W.....W....W.WWW.WWW...W",//25
  "W.WW...WW.W...W.W..WW...W..W.W",
  "W.QW.W..W.W.W.W...WW..W...WW.W",
  "WW.W.WW.W.W.W..W.WW..WWW.WWQ.W",
  "WW..........WW..............WW",
  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"//30
};

struct Object player = { 1, 2, NIL, PLAYER };

struct Object enemy_array[ENEMY_MAX] = {
  {1, 10, UP, ENEMY},
  {29, 4, DOWN, ENEMY},
  {21, 2, RIGHT, ENEMY}
};

char input;
int recent_portal;
int recent_enemy;
int recent_quiz;

/* in-joon's work */
struct problem set[10];
/* in-joon's work */

int main(void)
{
  initscr(); noecho(); nodelay(stdscr, TRUE); cbreak(); curs_set(0); enemy_number = 1; enemy_speed = 2 * 1000 * 1000; current_map = 1; problemSet(set);
  struct timeval main_timer; set_timer(&main_timer);
  struct timeval frame_timer; set_timer(&frame_timer);
  int fps = 1; current_symbol = EMPTY_SYMBOL;

  print_map(map1); refresh(); set_enemy_timer(); signal(SIGALRM, enemy_movement_handler);

  while(1)
  {
    //input handling
    input_handler();


    // enemy-collision
    if(recent_enemy == FALSE && collision_detect(&player, enemy_array, enemy_number) == TRUE)
    {
      set_new_penalty(&enemy_speed, &enemy_number);
      set_enemy_timer();
      recent_enemy = TRUE;
    }

    // quiz-collision
    if(recent_quiz == FALSE && quiz_collision(current_symbol) == TRUE)
    {
      recent_quiz = TRUE;
      if(current_map == 1)
      {
        map1[player.x][player.y] = EMPTY_SYMBOL;
      }
      else if(current_map == 2)
      {
        map2[player.x][player.y] = EMPTY_SYMBOL;
      }

      //quiz time!
      problemPrint(&set[quiz_number]);

      char input_answer[100]; scanf("%s", input_answer);
      if(!strcmp(input_answer, set[quiz_number].answer))
        ++solved;
      ++quiz_number;
      time_penalty(SET, 5 * 1000 * 1000);
      print_status(solved, quiz_number);
      clear_problem();
    }

    // portal-collision
    if(portal_warp(current_symbol, &player) == TRUE && recent_portal == FALSE)
    {
      clear(); move(0, 0); addstr("moving to next map..!"); refresh(); sleep(1);
      if(current_map == 1)
      {
        current_map = 2;
        player.x = 1; player.y = 29;
        print_map(map2);
        draw(&player);
      }
      else if(current_map == 2)
      {
        current_map = 1;
        player.x = 28; player.y = 29;
        print_map(map1);
        draw(&player);
      }
      fps = 1; set_timer(&frame_timer); recent_portal = TRUE;
      continue;
    }


    // end-collision
    if(end_warp(current_symbol, &player, solved) == TRUE)
    {
      break;
    }

    // time-over?
    if(get_elapsed_time(&main_timer) + time_penalty(GET, 0) >= LEFT_TIME)
    {
      break;
    }



    refresh(); ++fps;
    // handling fps capping
    move(MAP_HEIGHT + 1, MAP_WIDTH + 1); char buffer[40]; sprintf(buffer, "frame: %d", fps); addstr(buffer);
    if(fps > FPS_LIMIT)
    {
      fps = 1;
      long long elapsed_time = get_elapsed_time(&frame_timer);

      //////
      move(MAP_HEIGHT + 4, MAP_WIDTH + 1); char buffer[40]; sprintf(buffer, "elapsed_time: %lld", elapsed_time); addstr(buffer);
      long long time1 = get_elapsed_time(&main_timer);
      move(MAP_HEIGHT + 8, MAP_WIDTH + 1); char buffer1[40]; sprintf(buffer1, "current_time: %lld", time1); addstr(buffer1);
      refresh();
      /////

      //cap_frame(elapsed_time);
      while(elapsed_time < 1000 * 1000)
      {
        input_handler();
        elapsed_time = get_elapsed_time(&frame_timer);
      }
      set_timer(&frame_timer);
      recent_enemy = FALSE;
    }

  }


// ending


  endwin();
  return 0;
}

void set_enemy_timer()
{
  struct itimerval temp;
  temp.it_interval.tv_sec = enemy_speed / (1 * 1000 * 1000);
  temp.it_interval.tv_usec = enemy_speed % (1 * 1000 * 1000);
  temp.it_value = temp.it_interval;
  if(setitimer(ITIMER_REAL, &temp, NULL) == -1) { clear(); endwin(); puts("error in setitimer!"); exit(5); }
}

void enemy_movement_handler()
{
//  signal(SIGALRM, enemy_movement_handler);
  for(int i = 0; i < enemy_number; i++)
  {
    if(current_map == 1) reset(&enemy_array[i], map1);
    else if(current_map == 2) reset(&enemy_array[i], map2);

    if(current_map == 1) random_walk(map1, &enemy_array[i]);
    else random_walk(map2, &enemy_array[i]);
    draw(&enemy_array[i]);
  }
}

void input_handler()
{
  if((input = getch()) != ERR)
  {
    if(current_map == 1) key_handling(input, &player, map1);
    else key_handling(input, &player, map2);

    if(current_map == 1) current_symbol = map1[player.x][player.y];
    else if(current_map == 2) current_symbol = map2[player.x][player.y];

    recent_portal = FALSE;
    recent_enemy = FALSE;
    recent_quiz = FALSE;
    refresh();
  }
}
