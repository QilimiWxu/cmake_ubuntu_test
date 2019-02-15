#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#ifdef ABS_EXISTS
  #include <math.h>
#else
  #include "sub1/sumfun.h"
#endif

int main(int argc, char *argv[])
{
    if(argc == 2){
        if(strcmp(argv[1], "-v") == 0){
            printf("%s Version %d.%d\n",
                argv[0],
                VERSION_MAJOR,
                VERSION_MINOR);
            return 0;
        }
        else{
            printf("Usage: %s param error! \n", argv[0]);
            printf("        %s is not found!", argv[1]);
            return 1;
        }
    }
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    int iVal1 = atof(argv[1]);
    int iVal2 = atoi(argv[2]);

#ifdef ABS_EXISTS
    printf("Now we use the standard. \n");
    int result = abs(iVal1) + abs(iVal2);
#else
    printf("Now we use our own Math library. \n");
    int result = sum_test(iVal1, iVal2);
#endif
    printf("|%d| + |%d| = %d\n", iVal1, iVal2, result);
    return 0;
}
