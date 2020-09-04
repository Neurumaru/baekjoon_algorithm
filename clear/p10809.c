#include <stdio.h>
#include <string.h>

int main(void) {
	char S[101];
	int pos['z'-'a'+1];
	int i;
	
	scanf("%s", &S);
	
	for(i = 0; i <= 'z'-'a'; i++) pos[i] = -1;
	for(i = 0; i < strlen(S); i++) {
		if(pos[S[i]-'a'] == -1)
			pos[S[i]-'a'] = i;
	}
	
	for(i = 0; i <= 'z'-'a'; i++) printf("%d ", pos[i]);
	
	return 0;
}
