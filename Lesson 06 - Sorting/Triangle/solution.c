// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int cmpfnc(const void *a, const void *b){
    return (*(int*)a >= *(int*)b ? 1 : 0);
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N<3) {
        return 0;
    }
    qsort(A,N,sizeof(int),cmpfnc);
    for (int i = 0; i < N-2; i++) {
        if ((A[i]>0) && (double)A[i]+A[i+1]>A[i+2]) {
            return 1;
        }
    }
    return  0;
}