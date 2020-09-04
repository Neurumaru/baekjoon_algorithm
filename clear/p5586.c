#include <stdio.h>
#include <string.h>

int main(void) {
	char str[10001];
	int joi, ioi, i;
	
	scanf("%s", &str);
	
	for(joi = ioi = i = 0; i < strlen(str)-2; i++) {
		if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I')
			ioi++;
		if(str[i] == 'J' && str[i+1] == 'O' && str[i+2] == 'I')
			joi++;
	}
	
	printf("%d\n%d", joi, ioi);
	
	return 0;
}
