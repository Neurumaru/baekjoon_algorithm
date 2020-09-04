#include <stdio.h>
#include <string.h>

int btoi(char * binary) {
	int result, i;
	for(result = i = 0; i < 3; i++) {
		result *= 2;
		result += binary[i] - '0';
	}
	return result;
}

int main(void) {
	int i;
	char binary[103];
	
	binary[0] = binary[1] = '0';
	scanf("%s", binary + sizeof(char) * 2);
	
	for(i = 0; i < strlen(binary) - 2; i+=3) {
		switch(strlen(binary)%3) {
		case 0:
			printf("%d", btoi((&binary[i])));
			break;
		case 1:
			printf("%d", btoi((&binary[i])+sizeof(char)));
			break;
		case 2:
			printf("%d", btoi((&binary[i])+sizeof(char)*2));
			break;
		}
	}
	
	return 0;
}
