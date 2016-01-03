#include <stdio.h>
//this code just works for ISBN with length 10.
int checkIsbn(char* isbn){
	int i, sum = 0;
	/*in the for loop 10*i is added to sum if it reads an X,
	   otherwise it reads the current pointer value * i.*/
	for (i = 10; i >= 1; --i)
		sum += *isbn == 'X' ? 10 * i : (*isbn++-48) * i;
	return sum % 11;
}

int main(void){
	char input[11];
	printf("Please enter your ISBN number:\n");
	scanf("%s", input);
	printf("%d\n", checkIsbn(input));
	
}
