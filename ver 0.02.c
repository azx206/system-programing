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
char temp[100], *tempp = NULL;

int main(void)
{
	//add the linux things

	srand(time(NULL));

	int a = (rand() % 3) + 1;

	problemSet();

	problemSelect(a);

	printf("correct : %d\n", correct);

	system("pause");
}

void problemSet()
{
	set[1].state = 1;
	set[1].question = "which is the biggest thing among these?";
	set[1].choice = "1. moon    2. elephant    3. airplane    4. earth";
	set[1].answer = "4";

	set[2].state = 2;
	set[2].question = "what is the library to use 'malloc' in C? fill in the blank, [#include <[    ]>]";
	set[2].answer = "stdlib";

	set[3].state = 1;
	set[3].question = "which programming language is not object-oriented when first published?";
	set[3].choice = "1. Python    2. Pascal    3. Smalltalk    4. Ruby";
	set[3].answer = "2";
}

void problemSelect(int select)
{
	int i;
	char *input = NULL;

	problemPrint(set[select]);
	//pause and handie the signal;

	//handler needed

	input = getAnswer();

	compareAnswer(input, set[select].answer);

	set[select].state = -1;
}

void problemPrint(problem select)
{
	char input[50];

	printf("%s\n\n", select.question);
	
	if (select.state == 1)
		printf("%s\n", select.choice);

	printf("answer the question : ");
}

char *getAnswer() //thread needed
{
	tempp = gets(temp);

	return tempp;
}

void compareAnswer(char *input, char *answer)
{
	int len = strlen(answer);

	if (!strncmp(input, answer, len))
		correct++;	
}