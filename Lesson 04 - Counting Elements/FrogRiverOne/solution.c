// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: O(N)
#include <string.h>

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    //The solution pass for using bitmap
    //As so lets create the arrray
    int bitmap[X];
    //Clear the space 
    memset(bitmap,0x00,sizeof(bitmap[0])*X);

    int timez = -1;     //variable to hold the time passed 
    int p = 0, cnt = 0;          
    for(int i = 0;i < N; i++){
        p = A[i]-1;
        if(p < X && bitmap[p] == 0){
            bitmap[p] = 1;
            cnt++;
            if(cnt == X){
                timez = i;
                break;
            }
        }
    }
    return timez;

}