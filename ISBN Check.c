#include <stdio.h>
//sum = 272
//388 229 192 3

int checkIsbn(char* isbn){
	int i, sum = 0;
	for (i = 10; i >= 1; --i)
		sum += *isbn == 'X' ? 10 * i : (*isbn++-48) * i;
	return sum % 11;
}

int main(void){
	char input[10];
	printf("Please enter your ISBN number:\n");
	scanf("%s", input);
	printf("%d\n", checkIsbn(input));
	
}
