#include <stdio.h>
#define score 0
#define find 0
#define W_MAX 31 // MAP width +1(for '\0')
#define H_MAX 30

char map1[H_MAX][W_MAX] = { // example maps W : wall, . : road(empty space), Q : Question, | : portal conneted next maps, E : end point
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"WQ....W...............WW...WWW".
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
	"W.........W..W.E.W..W........W",//15
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

char map2[H_MAX][W_MAX] =  { // example maps W : wall, . : road(empty space), Q : Question, | : portal conneted next maps, E : end point
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

int main()
{
	printf("시간은 오후 5시 30분 모든 정규수업이 끝나는 시간...\n");
	printf("하지만 아직 난 집에 갈 수 없었다.\n");
	printf("그래도 다행인 것은 우리 학교는 선생님이 주신 문제만 다 풀면 조기귀가가 가능하다.\n");
	printf("");



	

}