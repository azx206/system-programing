#include "def.h"
#define MACROF refresh(); sleep(2); clear();


void print_string(char* str, int x)
{
//clear(); endwin(); printf("debuf\n"); exit(0);
  int i = 0;
  move(x, 10); addstr(BLANK);
move(x, 10);
	printw(str);
/*
  while(str[i] != '\0')
  {
    move(x, i); printw(str[i++]);
    usleep(10000);
	refresh();
  }
*/

}

void print_opening(int* root)
{

  print_string("Escape From School", 0);
  print_string("현재 시간 - 17: 30", 2);
  print_string("나는........", 4);
  print_string("선택", 6);
  print_string("1. 대기열이 차기 전에 로스트 아크에 접속해야 한다.", 8);
  print_string("2. 집에 있는 민트초코 아이스크림을 먹으러 가야 한다.", 10);
  print_string("3. 잘 때 얼어죽지 않으려면 집에 있는 땔감을 패야 한다.", 12);

	refresh(); scanf("%d", root);
	clear();
  print_string("그래 이대로 12시 까지 야자를 할 수 없는 노릇이다.", 0);
if(*root == 1)
  print_string("그랬다가는 나는 대기열 10000이 넘어가는 숫자에 정신줄을 놓아버릴거야.", 0);
if(*root == 2)
  print_string("도대체 왜 우리 가족 중에는 자신이 사지 않고 남의 민트초코를 먹는 사람이 있는 걸까?", 0);
if(*root == 3)
  print_string("그대로 집에 가서 쓰러져 잤다가는 나는 내일 9시 뉴스에 '청소년 동사체'기사의 주인공이 되겠지.", 0);
MACROF


  print_string("좋아 이대로 교탁에 놓여진 문제를 전부 다 푼 다음 빠르게 집으로 가서", 0);
MACROF

if(*root == 1)
  print_string("그대로 행복하게 로스트 아크를 즐기는 거야.", 0);
if(*root == 2)
  print_string("어떤 비양심자가 나의 민트초코를 다 먹어치우기 전에 내 위장속으로 옮겨놓는 거야", 0);
if(*root == 3)
  print_string("나의 생존을 위해서 땔감을 팬 다음 따뜻한 방에서 자는거야.", 0);
MACROF

  print_string("좋아 그러면 행복하지 않은 나의 방과후 학교 생활을 빨리 끝마치기 위해서 선생님들이 나눠주신 문제지를 풀어보도록 할까.", 0);
  print_string("우리의 주인공은 ", 2);
MACROF

if(*root == 1)
  print_string("로스트 아크를 하기 위해서 빨리 문제지를 다 풀고 집에 돌아가야 합니다!", 0);
if(*root == 2)
  print_string("다른 사람의 배 속에 민트 초코를 집어넣기 전에 자신의 배 속에 민트초코를 집어넣어야 합니다!", 0);
if(*root == 3)
  print_string("살아남기 위해서 일찍 집에 돌아가야 합니다!", 0);
MACROF

  print_string("여러분이 주인공을 도와서 학교 이곳저곳에 뿌려진 문제지를 되찾아 풀어서는 집에 갈 수 있게 해주세요!", 0);
  print_string("이동키는 W가 위, A가 왼쪽, D가 오른쪽, S가 아래쪽입니다. 문을( | )통해서 다른 교실로 이동할 수 있습니다.", 2);
  print_string("교실 곳곳에 숨어져 있는 문제(Q)를 전부 찾아서 풀고는 교탁(F)에 가면 클리어!", 4);
  print_string("일단은 문제를 전부 찾기만 해도 최소 클리어는 인정입니다.", 6);
  print_string("하지만 문제를 성의없이 풀었다가는 선생님들이 굉장히 싫어하시겠죠? 최대한 노력을 하시길.", 8);
  print_string("그리고 교실 내에는 이미 문제를 푸는 걸 포기하고 12시에 집에 가는 불량학생들이 주인공을 찾으려 하니 주의하시길 바랍니다!", 10);
  print_string("그럼....", 12);
MACROF

if(*root == 1)
  print_string("로스트 아크에 접속하실수 있기를 바라겠습니다.", 0);
if(*root == 2)
  print_string("민트 초코 아이스크림을 즐길 수 있기를 바라겠습니다.", 0);
if(*root == 3)
  print_string("살아남기를 바라겠습니다.", 0);
MACROF
}

void print_ending(int root, int score, long long elapsed_time)
{
clear();
  print_string("축하드립니다 당신은 학교에서 탈출하셨습니다!", 5); 
  print_string("Thank you for playing!", 10); refresh(); sleep(2);
}

void timeout_ending(int root)
{
clear();
  print_string("결국 12시 까지 학교에서 벗어나지 못했다. 그리고 내가 보고 있는 것은....", 0);
MACROF
  if(root == 1)
  {
    print_string("서버 접속 대기", 0);
    print_string("서버가 혼잡합니다. 잠시만 기다려 주세요.", 2);
    print_string("대기순위 23252", 4);
    print_string("BAD END 1-1 Game Over(시작도 못 했음.)", 8);
  }
  else if(root == 2)
  {
    print_string("아, 아아닛! 없어! 내 민트 초코가!", 0);
    print_string("포스트잇 : 당신의 mint choco 나의 Happiness와 satiety으로 대체되었다.", 2);
    print_string("으아아아아!", 4);

    print_string("주인공을 기다리고 있는 건 비어있는 아이스크림 통이었다...", 6);
    print_string("BAD END 2-1 Empty", 10);
  }
  else if(root == 3)
  {
    print_string("네 다음 소식입니다. 전국에 한파가 밀려들어왔는데요. 갑작스런 한파로 인해서 동사자가 발생하였습니다.", 0);
    print_string("....그 중에는 홀로 사는 고등학생도 있어 안타까움을 주고 있습니다.", 2);
    print_string("BAD END 3-1 Frozen", 4);
  }
MACROF
  print_string("더 빠르게 문제를 풀어서 다음에는 집에 일찍 귀가합시다!", 0);
MACROF
}
