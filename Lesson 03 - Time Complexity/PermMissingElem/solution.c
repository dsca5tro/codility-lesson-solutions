// Code written in C
// Task Score: 100%
// Correctness: 100%
// Performance: 100%
// Time Complexity: O(N) or O(N * log(N))

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    long calculation = 0;
    for(int i = 0; i<N;i++){
        calculation = calculation ^ A[i] ^ i;
    }
    calculation = calculation ^ N ^ (N+1);
    int result = (int) calculation;
    return result;

}