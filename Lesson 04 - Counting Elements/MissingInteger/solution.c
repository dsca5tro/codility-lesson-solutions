// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: O(N) or O(N * log(N))
#include <string.h>
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    //Create bitmap array
    int bitmap[N];
    int min = 1;
    //Clear bitmap 
    memset(bitmap, 0, sizeof(bitmap[0])*N);
    int n = 0;
    for (int i = 0 ; i<N; i++) {
        n = A[i]-1;
        if ( n >= 0 && n < N && bitmap[n] == 0) {
            bitmap[n] = 1;
        }
    }

    for (int j = 0; j<N; j++) {
        if(bitmap[j]==0){
            break;
        }
        min++;
    }

    return min;

}