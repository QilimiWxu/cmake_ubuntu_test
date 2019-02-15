
#include <stdio.h>
#include <stdlib.h>
#include "sub1/sumfun.h"


int main(int argc, char *argv[]){
	if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    int iVal1 = atof(argv[1]);
    int iVal2 = atoi(argv[2]);
    int iSum = sum_test(iVal1, iVal2);
    printf("%d + %d = %d\n", iVal1, iVal2, iSum);
    return 0;
}


