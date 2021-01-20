/*
  Problem 281A
*/


#include<ctype.h>

int main(){
  char inp[1001];
  gets(inp);
  inp[0] = toupper(inp[0]);
  puts(inp);
  return 0;
}