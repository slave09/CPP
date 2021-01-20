/* 
  Problem 617A
*/

#include <stdio.h>
int main()
{
  int position;
  scanf("%d", &position);
  if (position == 1 || position == 2 || position == 3 || position == 4 || position == 5)
    printf("%d", 1);
  else if (position % 5 == 0)
    printf("%d", (position / 5));
  else
    printf("%d", (position / 5)+1);

  return 0;
}