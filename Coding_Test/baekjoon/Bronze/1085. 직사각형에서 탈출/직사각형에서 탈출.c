#include <stdio.h>

int main() {
    int x,y,w,h;
    int wid, len;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    if(x>(double)w/2.0){
        wid=w-x;
    }
    else{
        wid=x;
    }
    if(y>(double)h/2.0){
        len=h-y;
    }
    else{
        len=y;
    }
    printf("%d", (wid>len)?len:wid);
    return 0;
}