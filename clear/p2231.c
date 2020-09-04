#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, i, j, k, n;
    
    scanf("%d", &N);
    for(i = N-100>0?N-100:0; i < N; i++) {
        n = j = i;
        while(j > 0) {
        	n += j%10;
        	j /= 10;
        }
        if(n == N) break;
    }
    printf("%d", i%N);
    
    return 0;
}