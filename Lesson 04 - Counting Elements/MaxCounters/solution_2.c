// Task Score: 77%
// Correctness: 100%
// Performance: 60%


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
    int max_counter=0, n=0;
    int *bitmap;
    bitmap = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < M; i++) {
        n = A[i]-1;
        //printf("\nIt:%d    A:%d    Max:%d",i,n,max_counter);
        if (n+1 <= N) {
            bitmap[n] += 1; 
            if (bitmap[n] > max_counter) {
                max_counter = bitmap[n];
            }
        }else {
            //display(bitmap, N);
            max_operation(bitmap, N, max_counter);
            //display(bitmap, N);
        }
    }
    //display(bitmap, N);
    
    result.C = bitmap;
    result.L = N;
    return result;
}