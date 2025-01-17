#include <stdio.h>
#include <string.h>
int isPalindrome(char* s, int start, int end) {
   while (start < end) {
       if (s[start] != s[end]) {
           return 0;
       }
       start++;
       end--;
   }
   return 1;
}
char* longestPalindromicSubstring(char* s) {
   int n = strlen(s);
   static char result[1000];
   int max_len = 0;
   int start_index = 0;
   for (int i = 0; i < n; i++) {
       for (int j = i; j < n; j++) {
           if (isPalindrome(s, i, j)) {
               int len = j - i + 1;
               if (len > max_len) {
                   max_len = len;
                   strncpy(result, s + i, len);
                   result[len] = '\0';
               }
           }
       }
   }
   return result;
}
int main() {
   
   char string[100];
   scanf("%s",string);
   if(string[0]=='\0' || string[0]=='\n')
   {
       return 1;
   }
   
   printf("%s\n", longestPalindromicSubstring(string));
   return 0;
}