#include <stdio.h>
#define score 0 // 맞춘 정답의 수
#define find 0 // 찾은 문제의 수
#define root 0 // 루트 선택

int main()
{
	
	printf("Escape From School\n")//글자 크기 키우거나 색깔 변경했으면 좋겠음 1페이지, opening part start

	printf("현재 시간 - 17 : 30 \n");//2페이지 시작
	printf("나는.......\n");
	printf("선택 \n 1. 대기열이 차기 전에 로스트 아크에 접속해야 한다.\n 2.집에 있는 민트초코 아이스크림을 먹으러 가야 한다 \n 3. 잘 때 얼어죽지 않으려면 집에 있는 땔감을 패야 한다.\n");
	while(root >= 1 && root <= 3)
	{
		scanf("%d",&root);
		if(root <= 0 || root >= 4)
		{
			printf("선택지를 다시 고르자\n");
		}
	}//2페이지 끝

	//3페이지 시작
	if(root == 1)
	{
		printf("그래 이대로 12시 까지 야자를 할 수 없는 노릇이다.\n 그랬다가는 나는 대기열 10000이 넘어가는 숫자에 정신줄을 놓아버릴거야.\n");
	}
	if(root == 2)
	{
		printf("그래 이대로 12시 까지 야자를 할 수 없는 노릇이다.\n 도대체 왜 우리 가족 중에는 자신이 사지 않고 남의 민트초코를 먹는 사람이 있는 걸까?\n");	
	}
	if(root == 3)
	{
		printf("그래 이대로 12시 까지 야자를 할 수 없는 노릇이다.\n그대로 집에 가서 쓰러져 잤다가는 나는 내일 9시 뉴스에 '청소년 동사체'기사의 주인공이 되겠지.\n");
	}

	Printf("좋아 이대로 교탁에 놓여진 문제를 전부 다 푼 다음 빠르게 집으로 가서")

	if(root == 1)
	{
		printf("그대로 행복하게 로스트 아크를 즐기는 거야.\n");
	}
	if(root == 2)
	{
		printf("어떤 비양심자가 나의 민트초코를 다 먹어치우기 전에 내 위장속으로 옮겨놓는 거야\n");	
	}
	if(root == 3)
	{
		printf("나의 생존을 위해서 땔감을 팬 다음 따뜻한 방에서 자는거야.\n");
	}

	//3페이지 끝

	printf("좋아 그러면 행복하지 않은 나의 방과후 학교 생활을 빨리 끝마치기 위해서 선생님들이 나눠주신 문제지를 풀어보도록 할 까.\n");

	//4페이지 시작

	printf("우리의 주인공은 ")

	if(root == 1)
	{
		printf("로스트 아크를 하기 위해서 빨리 문제지를 다 풀고 집에 돌아가야 합니다!\n");
	}
	if(root == 2)
	{
		printf("다른 사람의 배 속에 민트 초코를 집어넣기 전에 자신의 배 속에 민트초코를 집어넣어야 합니다!\n");	
	}
	if(root == 3)
	{
		printf("살아남기 위해서 일찍 집에 돌아가야 합니다!\n");
	}

	printf("여러분이 주인공을 도와서 학교 이곳저곳에 뿌려진 문제지를 되찾아 풀어서는 집에 갈 수 있게 해주세요!\n");
	printf("이동키는 W가 위, A가 왼쪽, D가 오른쪽, S가 아래쪽입니다. 문을( | )통해서 다른 교실로 이동할 수 있습니다.\n");
	printf("교실 곳곳에 숨어져 있는 문제(Q)를 전부 찾아서 풀고는 교탁(E)에 가면 클리어! 일단은 문제를 전부 찾기만 해도 최소 클리어는 인정입니다.\n");
	printf("하지만 문제를 성의없이 풀었다가는 선생님들이 굉장히 싫어하시겠죠? 최대한 노력을 하시길.\n");
	printf("그리고 교실 내에는 이미 문제를 푸는 걸 포기하고 12시에 집에 가는 불량학생들이 주인공을 찾으려 하니 주의하시길 바랍니다!\n");
	printf("그럼....")

	if(root == 1)
	{
		
printf("로스트 아크에 접속하실수 있기를 바라겠습니다.\n");
	}
	if(root == 2)
	{
		printf("민트 초코 아이스크림을 즐길 수 있기를 바라겠습니다.\n");	
	}
	if(root == 3)
	{
		printf("살아남기를 바라겠습니다.\n");
	}

	//4페이지 끝, opening part end

	//ending part start

	if()//시간 아웃 엔딩
	{
		//엔딩 1페이지 시작
		printf("결국 12시 까지 학교에서 벗어나지 못했다. 그리고 내가 보고 있는 것은....\n");//엔딩 1페이지 끝
		if(root == 1)
		{
		//엔딩 2페이지 시작 BAD END 1-1 Game Over(시작도 못 했음.)
			printf("서버 접속 대기\n");
			printf("서버가 혼잡합니다. 잠시만 기다려 주세요.\n");
			printf("대기순위 13252\n");
		//엔딩 2페이지 끝, 3페이지 시작
			printf("저는 그만 정신을 잃고 말았습니다.\n");
			printf("BAD END 1-1 Game Over(시작도 못 했음.)\n")
		//엔딩 BAD END 1-1 Game Over(시작도 못 했음.)끝
			printf("더 빠르게 문제를 풀어서 다음에는 집에 일찍 귀가하자!\n");//시간아웃 엔딩 페이지 끝
		}
		if(root == 2)
		{
		//엔딩 2페이지 시작 BAD END 2-1 Empty 
			printf("아, 아아닛! 없어! 내 민트 초코가!\n");
			printf("포스트잇 : 당신의 mint choco 나의 Happiness와 satiety으로 대체되었다.\n");
			printf("으아아아아!");
		//엔딩 2페이지 끝, 3페이지 시작
			printf("주인공을 기다리고 있는 건 비어있는 아이스크림 통이었다...");
			printf("BAD END 2-1 Empty\n");
		//엔딩 BAD END 2-1 Empty끝
			printf("더 빠르게 문제를 풀어서 다음에는 집에 일찍 귀가하자!\n");//시간아웃 엔딩 페이지 끝
		}
		if(root == 3)
		{
		//엔딩 2페이지 시작 BAD END 3-1 Frozen
			printf("네 다음 소식입니다. 전국에 한파가 밀려들어왔는데요. 갑작스런 한파로 인해서 동사자가 발생하였습니다.\n");
			printf("....그 중에는 홀로 사는 고등학생도 있어 안타까움을 주고 있습니다.\n");
			printf("당신은 살아남지 못했다.....만일 다음 생이 있다면 조금 더 노력해보자\n");
		}
	}

	if(find == 10 && /*엔드 포인트에 도착*/) //클리어 엔딩 score와 시간에 따라서 분기 변화.
	{
		if(root == 1)
		{
			if()//시간이 절반 이상 지나갔을 때
			{	
				printf("제발 제발....\n")//엔딩 2페이지
				//엔딩 3페이지 시작
				printf("서버 접속 대기\n");
				printf("서버가 혼잡합니다. 잠시만 기다려 주세요.\n");
				printf("대기순위 2252\n");
				//엔딩 3페이지 시작
				printf("그래 오늘은 이정도로 만족해야겠지...\n");
				//엔딩 3페이지 끝
				//엔딩 4페이지 시작
				printf("그리고 다음날\n");

				//엔딩 분기 2 점수 구별
				if(score <=6)
				{
				}
				else if(score >=6 && score <= 9)
				{
				}
				else if(score == 10)
				{
				}
			}
			else()
			{
				//엔딩 분기 2 점수 구별
				if(score <=6)
				{
				}
				else if(score >=6 && score <= 9)
				{
				}
				else if(score == 10)
				{
				}
			}
		}
		if(root == 2)
		{
			if()//시간이 절반 이상 지나갔을 때
			{
				//엔딩 분기 2 점수 구별
				if(score <=6)
				{
				}
				else if(score >=6 && score <= 9)
				{
				}
				else if(score == 10)
				{
				}

			}
			else()
			{
				//엔딩 분기 2 점수 구별
				if(score <=6)
				{
				}
				else if(score >=6 && score <= 9)
				{
				}
				else if(score == 10)
				{
				}
			}
		}
		if(root == 3)
		{	
			if()//시간이 절반 이상 지나갔을 때
			{
				printf("하...집에 돌아와서 간신히 하루 밤 때울 장작을 다 패고 나니 12시구만....\n")//
				printf("그리고 다음날\n");
				//엔딩 분기 2 점수 구별
				if(score <= 9)
				{
					//Normal End 3-2-1 생존
 					printf("선생님 : ...늦게도 늦게 들어가더니 영 결과물도 좋지 못하구나")
					printf("살고 싶었습니다. 선생님 진짜로 12시에 돌아가서 바로 쓰러지면 전 얼어 죽습니다.\n");
					printf("선생님 : 그래 다 먹고 살기 위해서 하는 일인데 어쩌겠냐. 다음에는 더 열심히 해라.\n");
					//페이지 전환
					printf("축하합니다! 당신은 살아남았습니다. 하지만...조금 더 노력하면 뭔가 달라질지도?");
					//Normal End 3-2 생존
				}
				else if(score == 10)
				{
					//Normal End 3-3-1 희망의 연탄
				}
			}
			else()
			{
				printf("됐어. 이정도의 양이라면 1주일 정도는 집에 오자마자 나무를 넣고 편히 잘 수 있겠군.\n")
				printf("그리고 다음날\n");
				//엔딩 분기 2 점수 구별
				if(score <= 9)
				{
					//Normal End 3-2-2 생존
 					printf("선생님 : 어제는 일찍 들어갔다 싶더니. 이게 뭐냐.")
					printf("네. 아무래도 나무를 캐야, 아니 패야 보니.\n");
					printf("선생님 : 그래 다 먹고 살기 위해서 하는 일인데 어쩌겠냐. 다음에는 더 열심히 해라\n");
					//페이지 전환
					printf("축하합니다! 당신은 살아남았습니다.\n 거기다가 이번 주말은 장작을 팰 필요도 없겠군요.\n하지만...조금 더 노력하면 뭔가 달라질지도?");
					//Normal End 3-2 생존
				}
				else if(score == 10)
				{
					//Normal End 3-3-2 장학생
				}
			}
		}
	} 	

 
}