// Task Score: 84%
// Correctness: 71%
// Performance: 100%
// Detected time complexity: O(N)
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int sum = 0, first = 0,second=0;
    int min = 1000, diff=100;
    for(int i = 0; i < N; i++) {
        sum += A[i];
    }
    //printf("Total:%d",sum);


    for(int j = 0; j < N; j++) {
        first += A[j];
        second = sum-first;
        diff = abs(first-second);
        //printf("\nIte:%d  1st:%d  2nd:%d  Diff:%d",j,first,second,diff);
        if(min>diff){
            min = diff;
        }
    }
    return min;
}