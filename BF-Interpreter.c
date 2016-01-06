#include <stdio.h>

//Keine schöne Lösung, aber sie funktioniert! :D

void interpreter(char* input){
	char output[5] = {0};
	char *outputPtr = output;
	char temp;
	size_t i, loopFlag;
	

	for (i = 0; input[i] != 0; i++){
		//printf("called for-loop\n");
		temp = input[i];
		
		if (temp == '>'){
			++outputPtr;
		}else if (temp == '<'){
			--outputPtr;
		}else if (temp == '+'){
			++*outputPtr;
		}else if (temp == '-'){
			--*outputPtr;
		}else if (temp == '.'){
			putchar(*outputPtr);
		}else if (temp == ','){
			*outputPtr = getchar();
		}else if (temp == '['){
			continue;
		}else if (temp == ']' && *outputPtr){
			loopFlag = 1;
			while (loopFlag){
				temp = input[--i];
				if (temp == '['){
					--loopFlag;
				}else if (temp == ']'){
					++loopFlag;
				}
			}
		}
	}

}

int main(void){
	interpreter("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
}
