// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    double minA = (A[0] + A[1])/2.0;
    int minP = 0;

    for (int i = 0; i<N-2; i++) {
        double temp2 = (A[i] + A[i+1])/2.0;
        double temp3 = (A[i] + A[i+1]+ A[i+2])/3.0;
        double tempMinA = (temp2<temp3)?temp2:temp3;
        printf("\nI:%d    Min:%.1f    temp2:%.1f    temp3:%.1f    MinP:%d",i,minA,temp2,temp3,minP);
        if(minA > tempMinA){
            minA = tempMinA;
            minP = i;
        }
    }

    if (minA > ((A[N-2] + A[N-1])/2.0)) {
        minP = N-2;
    }
    return  minP;
}
