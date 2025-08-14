#include <stdio.h>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    
    if(h==0&&m<45){
        h=24;
    }
    int sum=60*h+m;
    int altime=sum-45;
    
    printf("%d %d", altime/60, altime%60);
    
    return 0;
}