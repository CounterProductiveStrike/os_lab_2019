#include "revert_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RevertString(char *str)
{
    int count, end = 0;
	while (str[count] != '\0') count++;
      
     end = count - 1;
     printf("count: %i\n", count);
     printf("end: %i\n", end);
     char *temp = malloc(sizeof(char) * (count + 1));
     for (int i = 0; i < count; i++)
     {
         temp[i] = str[end];
         end--;
     }
     strcpy(str, temp);
     free(temp);
}


