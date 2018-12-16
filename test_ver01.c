/* makefile LBR : -lpthread, -lcurses */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<curses.h>

#define frame (60)
#define frame_utime (1000000/frame)

#define W_MAX 60
#define H_MAX 20

typedef struct student{
	int x_pos;
	int y_pos;
	int speed;
} student;

typedef struct enemy{
	int x_pos;
	int y_pos;
	int speed;
	int dir;
} enemy;

void move_st(student *player, char dir);
void move_enemy(enemy bully);
void *frame_sleep(void * usleep_time);

int main(){
	initscr();
	
	clear();

	pthread_t frame_thread;
	student player = {0, 0, 2};
	enemy bully[10];
	int frame_count = 0;
	int st_count = 0;
	int enemy_count = 0;

	char input_dir = 'w';
	
	int bully_count = 1;

	while(1){
		
		pthread_create(&frame_thread, NULL, frame_sleep, NULL);
		frame_count++;
		st_count++;
		fflush(stdin);
		input_dir = getchar();
		if(st_count >= player.speed){
			move(player.y_pos, player.x_pos);
			addch(' ');
			move_st(&player, input_dir);
			move(player.y_pos, player.x_pos);
			addch('p');
			st_count = 0;
		}
		

		pthread_join(frame_thread, NULL);
		refresh();
	}

	endwin();
	return 0;
}
void *frame_sleep(void * usleep_time){
	usleep(frame_utime);
	return NULL;
}
void move_st(student *player, char dir){
	if(dir == 'w'){
		if(player->y_pos > 0){
			player->y_pos--;
		}
	}
	else if(dir == 'a'){
		if(player->x_pos > 0){
			player->x_pos--;
		}
	}
	else if(dir == 's'){
		if(player->y_pos < H_MAX){
			player->y_pos++;
		}
	}
	else if(dir == 'd'){
		if(player->x_pos < W_MAX){
			player->x_pos++;
		}
	}
}
