/*
  配列の各要素に先頭から順に0,1,2,3,4を代入して表示(for文を使用)
*/

#include <stdio.h>

int main(void)
{
  int i;
  int vc[5]; /* 要素数が5で要素型がint型の配列 */

  for(i = 0; i < 5; i++)
    vc[i] = i;

  for(i = 0; i < 5; i++)
    printf("vc[%d] = %d\n", i, vc[i]);

  return (0);
}
