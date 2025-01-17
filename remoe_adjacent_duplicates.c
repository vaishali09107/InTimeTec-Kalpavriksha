#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char *str)
{
   int length = strlen(str);
   int i, k = 0; 
   int flag = 0; 
   char temp[length + 1]; 
   for (i = 0; i < length; i++) 
   {
        if (i < length - 1 && str[i] == str[i + 1]) 
        {
           flag = 1; 
           while (i < length - 1 && str[i] == str[i + 1])
            {
               i++;
            }
        }
        else
        {
           temp[k++] = str[i];
        }
   }
   temp[k] = '\0';

   strcpy(str, temp);
   if (flag) 
   {
       removeAdjacentDuplicates(str);
   }
}
int main() 
{
   char input[100];
   printf("Enter a string: ");
   scanf("%s", input);
   removeAdjacentDuplicates(input);
   printf("Output: %s\n", input); 
   return 0;
}