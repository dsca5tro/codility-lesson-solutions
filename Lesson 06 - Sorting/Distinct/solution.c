// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Detected time complexity: O(N*log(N)) or O(N)
int cmpfnc(const void *a, const void *b){
    return *(int*) a - *(int*)b;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if(N == 0){
        return 0;
    }
    qsort(A,N,sizeof(int),cmpfnc);
    int counter = 1;
    for (int i = 1 ; i < N; i++) {
        if (A[i] != A[i-1]) {
            counter++;
        }
    }
    return counter;
}
