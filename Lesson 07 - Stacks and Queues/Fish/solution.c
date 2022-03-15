// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

//Implement Stack

int isempty(int *top) {

   if(*top == -1)
      return 1;
   else
      return 0;
}

int pop( int *stack, int *top) {
   int data;
	
   if(!isempty(top)) {
        data = stack[*top];
        *top = *top - 1;   
        return data;
   } else {
        return -1;
        printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int data, int *stack, int *top) {

   //if(!isfull()) {
    *top = *top + 1;   
    stack[*top] = data;
   //} else {
    //  printf("Could not insert data, Stack is full.\n");
   //}
}

int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int *stack = calloc(N, sizeof(char));
    int top=-1; 


    int dir =B[0];
    push(A[0],stack,&top);
    int power = 0;
    for (int i = 1; i<N; i++) {
        printf("\nSize:%d    Dir:%d    top:%d",A[i],B[i],top);
        if (dir!=B[i]) {
            printf("\nDiff dir    ");
            while(isempty(&top)!=1){
                power = pop(stack,&top);
                if (power>A[i]) {
                    push(power,stack,&top);
                    break;
                }
            }
            if (isempty(&top)==1) {
                printf("Stack Empty");
                push(A[i],stack,&top);
                dir = B[i];
            }
        }
        else {
            printf("\nEqual dir");
            push(A[i],stack,&top);
        }
    }

    return top-1;
}
