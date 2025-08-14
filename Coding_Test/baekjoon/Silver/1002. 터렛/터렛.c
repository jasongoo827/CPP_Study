#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, r1, r2, t;
    scanf("%d", &t);
    
    for(int i=0;i<t;i++){
        scanf("%d %d %d %d %d %d ", &x1, &y1, &r1, &x2, &y2, &r2);
        double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        int plus=r1+r2;
        int minus=(r1>r2)?(r1-r2):(r2-r1);
        if(d==0&&(r1==r2)){
            printf("-1\n");
        }
        else{
            if(d>plus) printf("0\n");
            else if(d==plus) printf("1\n");
            else if((d>minus)&&(d<plus)) printf("2\n");
            else if(d==minus) printf("1\n");
            else if(d<minus) printf("0\n");
        }
    }
    return 0;
}