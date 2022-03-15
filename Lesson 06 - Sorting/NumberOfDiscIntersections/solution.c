// Task Score: 87%
// Correctness: 100%
// Performance: 75%
// Detected time complexity: O(N*log(N)) or O(N)
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int sizeD = 0;
    int inter = 0;
    int max = 5; 
    if(N<=1){
        return 0;
    }else {
        for (int i = 0; i<N; i++) {
            sizeD = A[i];
            max = (sizeD > max && sizeD < 2147483646) ? sizeD : max;
            //printf("\nPoint:%d    Inter:%d    Size:%d",i,inter,sizeD);

            if(sizeD>0){
                // Contar os pontos para a frente até o limite superior
                if ((double)i+sizeD > N-1) {
                    inter += N-1-i;
                }else {
                    inter += sizeD;
                }
                //printf("\nPoint:%d    Inter:%d    Size:%d    Max:%d",i,inter,sizeD,max);
                for (int j = 1; j <= sizeD+max; j++) {
                    int tmpPoint = i-j;
                    if (tmpPoint < 0) {
                        //printf("\tBreak");
                        break;
                    }
                   // printf("\ntmpPoint:%d    ",tmpPoint);
                    int tmpSizeD = A[i-j];
                    int tmpRightLimit = (i-j)+tmpSizeD;
                    int leftLimit = (i -sizeD) >= 0 ? (i -sizeD) : 0 ;
                    // verificar se o disco consegue abranger o ponto atual
                    //printf("tmpRigth:%d    leftLimit:%d  ",tmpRightLimit,leftLimit);
                    if(tmpRightLimit < i && tmpRightLimit >= leftLimit ){
                        inter++;
                        //printf("\tInter UP");
                    }
                }
            }
            if (inter > 10e7) {
                inter = -1;
                break;
            }
            //printf("\nInter:%d",inter);
        }
    }
    return inter;
}