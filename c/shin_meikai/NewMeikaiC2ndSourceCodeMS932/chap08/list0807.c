// KćđÄAIÉßé

#include <stdio.h>

//--- ŽlnĚKćlđÔp ---//
int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main(void)
{
	int num;

	printf("ŽđüÍšćF");
	scanf("%d", &num);

	printf("%dĚKćÍ%dĹˇB\n", num, factorial(num));

	return 0;
}
