// Task Score:100%
// Correctness:100%
// Performance:100%
// Detected time complexity: O(N)
int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int N = strlen(S);
    if(N==0) return 1;
    if(N%2!=0) return 0;
    char *stack = calloc(N, sizeof(char));
    int top=-1;



    while (*S !='\0') {
        //printf("\nS:%c",*S);
        if (*S == '(' ) {
            top++;
            stack[top] = S[0];
            //printf("\nstack:%s",stack);
        }else{
            switch (*S) {
                case ')':
                    if(stack[top] != '(') return 0;
                    top--;
                    break;
            }
        }
        S++;
    }
    return top == -1;
}