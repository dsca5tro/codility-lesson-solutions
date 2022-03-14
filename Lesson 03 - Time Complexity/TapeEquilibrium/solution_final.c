int abs(int n) {
    return (n >= 0) ? n : (-(n));
}


int solution(int A[], int N) {
    long p;
    long index;
    long leftSum;
    long rightSum;
    long totalSum=0;

    long last_minimum=100000;
    long current_min;

    if(N==2) return abs(A[0]-A[1]);
    if(N==1) return abs(A[0]);

    for(index=0; index < N; index++)
        totalSum = totalSum + A[index];    

    leftSum = 0; rightSum = 0;

    for (p = 1; p <= N-1; p++) {

        leftSum += A[p - 1];
        rightSum = totalSum - leftSum;        

        current_min = abs((long)(leftSum - rightSum));

        last_minimum = current_min < last_minimum ? current_min : last_minimum;
        if (last_minimum == 0)
            break;
    }
    return last_minimum;
}