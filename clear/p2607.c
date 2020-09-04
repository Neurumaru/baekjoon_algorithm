#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, i, j, len1, len2, result, ch_abs_error;
	int ch1_comp['z' - 'a'] = { 0 }, ch2_comp['z' - 'a'];
	char ch1[11], ch2[11];
	
	scanf("%d", &N);
	scanf("%s", ch1);
	
	for(len1 = 0; len1 < 11 && ch1[len1] != '\0'; len1++)
		ch1_comp[ch1[len1]-'A']++;
	
	result = 0;
	for(i = 1; i < N; i++) { 
		ch_abs_error = 0; 
		for(j = 0; j <= 'z' - 'a'; j++)
			ch2_comp[j] = 0;
			
		scanf("%s", ch2);
			
		for(len2 = 0; len2 < 11 && ch2[len2] != '\0'; len2++)
			ch2_comp[ch2[len2]-'A']++;
		
		for(j = 0; j <= 'z'-'a'; j++)
			ch_abs_error += abs(ch1_comp[j] - ch2_comp[j]);
		
		if(abs(len2 - len1) < 2 && ch_abs_error < 3)
			result++;
	}
	
	printf("%d", result);
	
	return 0;
}
