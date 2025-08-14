#include<stdio.h>
int main()
{
   int a,b,c;

   scanf("%d",&a);

   for (c=0;c<a;c++){
        for(b=0;b<a-c-1;b++){
            printf(" ");
        }
        for(b=a-c;b<=a+c;b++){
            printf("*");
        }
        printf("\n");
   }
   return 0;

}
