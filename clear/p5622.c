#include <stdio.h>

int ctoi(char c) {
	int result = -1;
	if('A' <= c && c <= 'C')		result = 2;
	else if('D' <= c && c <= 'F')	result = 3;
	else if('G' <= c && c <= 'I')	result = 4;
	else if('J' <= c && c <= 'L')	result = 5;
	else if('M' <= c && c <= 'O')	result = 6;
	else if('P' <= c && c <= 'S')	result = 7;
	else if('T' <= c && c <= 'V')	result = 8;
	else if('W' <= c && c <= 'Z')	result = 9;
	return result;
}
int itot(int i) {
	if(i == 0) i = 10;
	return i + 1;
}

int main(void) {
	char a;
	int result = 0;
	
	while(scanf("%c", &a), a != EOF && a != '\n' && a != '\0') {
		result += itot(ctoi(a));
	}
	
	printf("%d", result);
	
	return 0;
}
