/* makefile LBR : -lpthread, -lcurses */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<curses.h>

// for kbhit ::
#include <string.h>
#include <sys/select.h>
#include <termios.h>


#define frame (60) // frame limit
#define frame_utime (1000000/frame) // frame wait time

#define W_MAX 21 // MAP width +1(for '\0')
#define H_MAX 20 // MAP hieght

struct termios orig_termios;

typedef struct student {
	int x_pos;
	int y_pos;
	int speed; // frame needs for student`s 1 move
} student;

typedef struct enemy {
	int x_pos;
	int y_pos;
	int dir;
} enemy;


char map[H_MAX][W_MAX] = { // example maps W : wall, . : road(empty space), Q : Question, | : portal conneted next maps
	"WWWWWWWWWWWWWWWWWWWW",
	"W.......W.....W....|",
	"W.WWWWW.W.W.W.W.WWWW",
	"W.W.....W.W.W.W....W",
	"W.W.Q.W.W.W.W.W.WW.W", // 5
	"W.....W.W.W.W.W....W",
	"W..WWWW.W.W.W.WWWW.W",
	"W.......W.W.W.W....W",
	"W.WWW.WWW.W.W...WW.W",
	"W...........W......W", // 10
	"WWWWWWWWWW.WWWWWWWWW",
	"W.......W...W...W.QW",
	"W.WWWWW.W.W...W....W",
	"W..W....W.W.WWWWWW.W",
	"W....W..W.W........W", // 15
	"W.WWWWW...W.WWWWWW.W",
	"W.W...W.W.W........W",
	"W.W.W.W.W.W.WWWWWW.W",
	"W...W...W..........|",
	"WWWWWWWWWWWWWWWWWWWW" // 20
};

char direction[4] = { 'w', 'a', 's', 'd' }; // (index+1)%4 means 90 counterclockwise rotation
int enemy_speed = 10; // all enemy share the speed

void move_st(student *player, char dir); // student`s move function
void move_enemy(enemy *bully); // enemy`s random move function
char next_place(int x_pos, int y_pos, int dir); // find what is next block
void *frame_sleep(void * usleep_time); // one frame

/* https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input */
void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}
// kbhit judge either any key press or not

int main(){
	initscr(); // make curser
	
	clear(); // clear screen

	pthread_t frame_thread; // make frame thread
	student player = {1, 1, 2}; // student init
	enemy bully[10] = { { 1, 1, rand() % 4 }, { 1, 1, rand() % 4 } }; // enemy init (now 1 enemy is initialized)
	int frame_count = 0;
	int st_count = 0;
	int enemy_count = 0;

	char input_dir = direction[0]; // just initialize
	
	int bully_amount = 2;

	int i;

	srand((int)time(NULL)); // seed of random


	//print all maps
	for (i = 0; i < H_MAX; i++) {
		move(i, 0);
		addstr(map[i]);
		addstr("\n");
	}
	move(4, 30);
	addstr("Press w, a, s, d to Move Player(*)");
	move(5, 30);
	addstr("frame");
	move(8, 30);
	addstr("Question");
	move(11, 30);
	addstr("Answer");
	refresh();



	while(1){ // frame
		
		// create thread to wait 1 frame time
		pthread_create(&frame_thread, NULL, frame_sleep, NULL); // 1frame contents start

		frame_count++;

		// count for move player, enemy
		st_count++;
		enemy_count++;

		// kbhit => judge either press or not
		if (kbhit()) {
			// if something input, get input char.
			input_dir = getchar();
		}

		// player move
		if(st_count >= player.speed){
			// print maps where player was
			move(player.y_pos, player.x_pos);
			addch(map[player.y_pos][player.x_pos]);

			// player move
			move_st(&player, input_dir);

			st_count = 0;
			input_dir = 0;
		}
		
		// enemy move
		if (enemy_count >= enemy_speed) {
			for (i = 0; i < bully_amount; i++) {
				//print maps where enemy[i] was
				move(bully[i].y_pos, bully[i].x_pos);
				addch(map[bully[i].y_pos][bully[i].x_pos]);

				//enemy[i] move
				move_enemy(&bully[i]);
			}
			enemy_count = 0;
		}

		// print player icon where player`s next position
		move(player.y_pos, player.x_pos);
		addch('*');

		// print enemy icon where player`s next position
		for (i = 0; i < bully_amount; i++) {
			move(bully[i].y_pos, bully[i].x_pos);
			addch('@');
		}

		// print frame count % 100
		move(6, 30);
		addch('0' + (frame_count % 100) / 10);
		addch('0' + frame_count % 10);

		pthread_join(frame_thread, NULL); // 1frame contents end

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
	if (dir == direction[0]) { // ก่
		if (player->y_pos > 0) {
			if (map[player->y_pos - 1][player->x_pos] != 'W') {
				player->y_pos--;
			}
		}
	}
	else if (dir == direction[1]) { // ก็
		if (player->x_pos > 0) {
			if (map[player->y_pos][player->x_pos - 1] != 'W') {
				player->x_pos--;
			}
		}
	}
	else if (dir == direction[2]) { // ก้
		if (player->y_pos < H_MAX - 1) {
			if (map[player->y_pos + 1][player->x_pos] != 'W') {
				player->y_pos++;
			}
		}
	}
	else if (dir == direction[3]) { // กๆ
		if (player->x_pos < W_MAX - 2) {
			if (map[player->y_pos][player->x_pos + 1] != 'W') {
				player->x_pos++;
			}
		}
	}
}
void move_enemy(enemy *bully) {
	int next_dir[3] = { bully->dir, (bully->dir + 1) % 4, (bully->dir + 3) % 4 }; // toward, left, right
	int empty[3] = { 0, 0, 0 };
	int i;
	char next;

	for (i = 0; i < 3; i++) {
		next = next_place(bully->x_pos, bully->y_pos, next_dir[i]);
		if (next != 'W' && next != '|') {
			empty[i] = 1;
		}
	}

	if (empty[0] || empty[1] || empty[2]) { // if there is empty space on toward, left, right
		while (1) {
			i = rand() % 4;
			i %= 3;
			if (empty[i])
				break;
		} // loop until i is empty index
		bully->dir = next_dir[i];
	}
	else { // if toward, left, right are all filled
		bully->dir = (bully->dir + 2) % 4; // dir = backward
	}

	if (bully->dir % 2) { // move left or right
		bully->x_pos += bully->dir - 2;
	}
	else { // up or down
		bully->y_pos += bully->dir - 1;
	}
}
char next_place(int x_pos, int y_pos, int dir) {
	if (dir == 0) { // ก่
		if (y_pos > 0) {
			return map[y_pos - 1][x_pos];
		}
	}
	else if (dir == 1) { // ก็
		if (x_pos > 0) {
			return map[y_pos][x_pos - 1];
		}
	}
	else if (dir == 2) { // ก้
		if (y_pos < H_MAX) {
			return map[y_pos + 1][x_pos];
		}
	}
	else if (dir == 3) { // กๆ
		if (x_pos < W_MAX - 1) {
			return map[y_pos][x_pos + 1];
		}
	}
	else {
		return 'W';
	}
}