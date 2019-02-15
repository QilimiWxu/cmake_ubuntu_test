
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#ifdef USE_MYMATH
  #include "sub1/sumfun.h"
#else
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    int iVal1 = atof(argv[1]);
    int iVal2 = atoi(argv[2]);
    
#ifdef USE_MYMATH
    printf("Now we use our own Math library. \n");
    int result = sum_test(iVal1, iVal2);
#else
    printf("Now we use the standard. \n");
    int result = iVal1 + iVal2;
#endif
    printf("%d + %d = %d\n", iVal1, iVal2, result);
    return 0;
}
