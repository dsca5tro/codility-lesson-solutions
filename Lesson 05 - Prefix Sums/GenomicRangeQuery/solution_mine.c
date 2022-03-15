// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <string.h>

struct Results solution(char *S, int P[], int Q[], int M) {
    int N = strlen(S);
    // write your code in C99 (gcc 6.2.0)
    int *bitmap;
    bitmap = (int *)calloc(M, sizeof(int));
    int seq[N];
    int * seq_1;
    seq_1 = (int *)calloc(M, sizeof(int));
    int cnt = 0;
    //printf("Seq:");
    for (int i = 0; i<N; i++) {
        switch (S[i]) {
            case 'A':
                seq[i] = 1;
                seq_1[cnt]=i;
                cnt++;
                break;
            case 'C':
                seq[i] = 2;
                break;
            case 'G':
                seq[i] = 3;
                break;
            case 'T':
                seq[i] = 4;
                break;
        }
        //printf("%d",seq[i]);
    }

    for (int j = 0; j < M; j++) {
        int min = 4;
        if ( P[j] ==  Q[j]) {
            bitmap[j] = seq[Q[j]];
        }
        else { 
            //printf("\nInterval:%d-%d",P[j],Q[j]);
            int dif = Q[j] - P[j];
            if(dif>cnt && dif>20){
                for(int l = 0; l<dif;l++){
                    if (seq_1[l]<Q[j] && seq_1[l]>P[j] ) {
                        min = 1;
                        break;
                    }
                    else if (l+P[j]>Q[j]) {
                        break;
                    }
                }
            }
            for (int k = P[j]; k<=Q[j]; k++) {
                //printf("\nk:%d    Min:%d    Seq:%d",k,min,seq[k]);
                if (min>seq[k]) {
                    min = seq[k];
                }
                if (min == 1) {
                    break;
                }
            }
            bitmap[j] = min;
        }   
    }
    
    struct Results result;
    result.A = bitmap;
    result.M = M;
    return result;
}