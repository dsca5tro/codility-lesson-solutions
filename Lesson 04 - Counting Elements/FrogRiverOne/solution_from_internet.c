int solution(int X, int A[], int N) 
{
    //the array to store flags
    int B[X];

    //clear the flags.
    memset(B, 0x00, sizeof(B[0]) * X);
    
    //let leaves fall!
    int t;
    int cnt = 0;
    int ans = -1;
    for (t = 0; t < N; t++){
        //get the position where a leave fall at time T. 
        int p = A[t] - 1; //(the array B is from 0 to X-1)
        //if it is between 0 to X-1 and 
        //no leave has fallen onto the position before, count it.
        if (p < X && B[p] == 0){
            B[p] = 1;
            cnt++;
            //is the route filled with leaves?
            if (cnt == X){
                ans = t;
                break;
            }
        }
    }

    return ans;
}