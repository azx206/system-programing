#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct problem
{
	int state; // 1 = choicement  2 = description  -1 = dead
	char *question;
	char *choice;
	char *answer;
} problem;

void problemSelect();
void problemSet();
void problemPrint(problem select);
char *getAnswer();
void compareAnswer(char *input, char *answer);

problem set[50];
int correct = 0;
char answerString[50] = { "" };

int main(void)
{
	int cnt = 5;
	//add the linux things

	problemSet();

	srand(time(NULL));

	while (1)
	{
		int a = (rand() % 10) + 1;

		if (set[a].state != -1)
		{
			problemSelect(a);

			cnt--;
		}

		if (!cnt)
			break;
	}

	printf("correct : %d\n", correct);

	system("pause");
}

void problemSet()
{
	set[1].state = 1;
	set[1].question = "Which is the principle of, always getting lowest available spot in the file descriptor?";
	set[1].choice = "1. Lowest-Allocated-fd    2. Lowest-Granting-fd    3. Lowest-Available-fd    4. Lowest-initializing-fd";
	set[1].answer = "3";

	set[2].state = 2;
	set[2].question = "What is the library to use 'malloc' in C? fill in the blank, [#include <[    ]>]";
	set[2].answer = "stdlib";

	set[3].state = 1;
	set[3].question = "Which programming language is not object-oriented when first published?";
	set[3].choice = "1. Python    2. Pascal    3. Smalltalk    4. Ruby";
	set[3].answer = "2";

	set[4].state = 2;
	set[4].question = "Which is called [    ] process has completed execution but still has an entry in the process table?";
	set[4].answer = "zombie";

	set[5].state = 1;
	set[5].question = "Which is a state that each member of a group is wating for some other member to take action?";
	set[5].choice = "1. Deadlock    2. Semaphore    3. Inconsistency    4. Mutex";
	set[5].answer = "1";

	set[6].state = 2;
	set[6].question = "Which is called [    ] signal caused by events outside the process?";
	set[6].answer = "asynchronous";

	set[7].state = 1;
	set[7].question = "Which is the command of printing the full pathname of the current working directory in Unix?";
	set[7].choice = "1. ls    2. pwd    3. mkdir    4. cd";
	set[7].answer = "2";

	set[8].state = 1;
	set[8].question = "Who is the first developer of Linux kernel and Git?";
	set[8].choice = "1. Yukihiro Matsumoto    2. Linus Pauling    3. James Gosling    4. Linus Torvalds";
	set[8].answer = "4";

	set[9].state = 2;
	set[9].question = "What is animal of mascot of Linux?";
	set[9].answer = "penguin";

	set[10].state = 1;
	set[10].question = "What is name of <System-Programming>'s Professor?";
	set[10].choice = "1. Yoon-Ja Choi    2. Jae-Suk Jang    3. Eun-Kyung Ryu    4. Yong-Ju Lee";
	set[10].answer = "3";
}

void problemSelect(int select)
{
	int i;
	char *input = NULL;

	if (set[select].state != -1)
	{
		problemPrint(set[select]);
		//pause and handie the signal;

		//handler needed

		input = getAnswer();

		compareAnswer(input, set[select].answer);

		set[select].state = -1;
	}
}

void problemPrint(problem select)
{
	printf("%s\n\n", select.question);
	
	if (select.state == 1)
		printf("%s\n", select.choice);

	printf("\nanswer the question : ");
}

char *getAnswer() //thread needed
{
	char temp[100], *tempp = NULL;

	tempp = gets(temp);

	for (int i = 0; i < strlen(tempp); i++)
		answerString[i] = tolower(tempp[i]);

	return &answerString;
}

void compareAnswer(char *input, char *answer)
{
	int len = strlen(answer);

	if (!strncmp(input, answer, len))
		correct++;	
}