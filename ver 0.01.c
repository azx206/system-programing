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

int main(void)
{
	srand(time(NULL));

	//int a = (rand() % 2) + 1;
	int a = 1;
	problemSet();

	problemSelect(a);
	
	printf("%d\n", correct);

	system("pause");
}

void problemSet()
{
	set[1].state = 1;
	set[1].question = "what is the biggest thing among these?\n\n";
	set[1].choice = "1. moon	2. elephant	3. airplane	4. earth\n";
	set[1].answer = "4";
}

void problemSelect(int select)
{
	int i;
	char *input = NULL;

	problemPrint(set[select]);
	//pause and handie the signal;

	//handler needed

	input = getAnswer();

	printf("%s", input); //wtf?

	compareAnswer(input, set[select].answer);

	set[select].state = -1;
}

void problemPrint(problem select)
{
	char input[50];

	printf("%s%s\n", select.question, select.choice); //if syntax needed for classfy problem state

	printf("answer the question : ");
}

char *getAnswer() //thread needed
{
	char temp[100], *tempp = NULL;

	tempp = gets(temp);

	printf("%s", tempp);

	return tempp;
}

void compareAnswer(char *input, char *answer)
{
	int len = strlen(answer);

	if (!strncmp(input, answer, len))
		correct++;	
}