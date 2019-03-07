#include "swap.h"
#include <string.h>
#include <stdlib.h> 

void Swap(char *left, char *right)
{
    char tmp = *left;
    *left = *right;
    *right = tmp;
}
