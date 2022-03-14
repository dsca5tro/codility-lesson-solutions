// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: O(N) or O(N * log(N))

#include <string.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    //Create bitmap array
    int bitmap[N];
    //Clear bitmap 
    memset(bitmap, 0x00, sizeof(bitmap[0])*N);

    int p = -1;
    int result = 1;
    for (int i = 0; i<N; i++) {
        p = A[i]-1;
        if (p > N-1 || p < 1 ) {
            result = 0;
            break;
        }
        if (bitmap[p]==0) {
            bitmap[p] = 1;  
        }else {
            result = 0;
            break;
        }
    }

    return result;
}