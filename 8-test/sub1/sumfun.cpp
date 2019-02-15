

#include <stdio.h>
#include "sumfun.h"

int sum_test(int val1, int val2){
//    return val1 + val2;
    return (val1>0?val1:-val1) + (val2>0?val2:-val2);
}

