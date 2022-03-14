// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: O(N + M)

#include <string.h>

void display(int A[], int N){
    printf("\narray state: {");
    for (int i = 0; i<N; i++) {
        if (i<N-1) {
            printf("%d,",A[i]);
        }
        else {
            printf("%d}",A[i]);
        }   
    }
}

void max_operation(int A[], int N, int max_counter){
    for (int i = 0; i<N; i++) {
        A[i] = max_counter;
    }
    //display(A, N);
}



struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int max_counter=0, n=0, last_increment = 0;
    int *bitmap;
    bitmap = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < M; i++) {
        n = A[i]-1;
        if (n+1 <= N) {
            if(bitmap[n]<last_increment){
                bitmap[n] = last_increment;
            }
            bitmap[n] += 1; 
            if (bitmap[n] > max_counter) {
                max_counter = bitmap[n];
            }
        }else {
            last_increment = max_counter;
            //display(bitmap, N);
            // max_operation(bitmap, N, max_counter);
            //display(bitmap, N);
        }
    }
    //display(bitmap, N);
    
    for (int i = 0; i<N; i++) {
        if (bitmap[i]< last_increment) {
            bitmap[i] = last_increment;
        }
    }
    result.C = bitmap;
    result.L = N;
    return result;
}