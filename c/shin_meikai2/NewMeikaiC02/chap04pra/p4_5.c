#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_TIMES 15

char string[8][10]={"white","black","red","blue","yellow","green","orange","brown"};

void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 8;			
			for (j = 0; j < i; j++)		
				if (val == x[j])
					break;
		} while (j < i);	
		x[i] = val;
	}
}

int check(const char s[])
{
	int i, j;

	if (strlen(s) != 4)			
		return 1;

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;			
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;		
	}
	return 0;					
    }

void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;
    printf("You enterd \"%s\", \"%s\", \"%s\", \"%s\"\n"
,string[s[0]-'0'],string[s[1]-'0'],string[s[2]-'0'],string[s[3]-'0']);

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	
				if (i == j)
					(*hit)++;			
				else
					(*blow)++;			
		}
	}
}

void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("That's correct!!");
	else if (snum == 0)
		printf("Those colours aren't included\n");
	else {
		printf("%d of them is(are) included\n", snum);

		if (spos == 0)
			printf("non of their positions aren't right though\n");
		else
			printf("%d of them is(are) in the right spot(s)\n", spos);
	}
	putchar('\n');
}

int main(void)
{
    
	int try_no = 0;		
	int chk;			
	int hit;			
	int blow;			
	int no[4];			
	char buff[10];		
	clock_t	start, end;				
	srand(time(NULL));				

	puts("# Lets's play Mastermind with colours");
	puts("# Guess the 4 colours in the right order");
	puts("# No dupulicate colours are included");
	puts("# Enter numbers representing colours sequently such as 4307 (yellow,blue,white,brown)");
	puts("# Do not enter the same number(colour) more than once");
    printf("# You have %d tries\n\n",NUM_OF_TIMES);

	make4digits(no);					

	start = clock();					

	do {
		do {
			printf("\aEnter 4 numbers (0)...white (1)...black (2)...red (3)...blue" 
            " (4)...yellow\n(5)...green (6)...orange (7)...brown:\n");
			scanf("%s", buff);			

			chk = check(buff);			

			switch (chk) {
			 case 1: puts("\aPlease enter \"4\" numbers"); break;
			 case 2: puts("\aPlease enter only numbers"); break;
			 case 3: puts("\aPlease do not enter the same number more than once"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);	
		print_result(hit + blow, hit);	

	} while (hit < 4 && try_no<NUM_OF_TIMES); 

    if(try_no>=NUM_OF_TIMES){
        printf("Too many tries. You lost.\n");
    }
	end = clock();						
	printf("It took %d times.\nThe time you took was %.1f seconds\n",
							try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
