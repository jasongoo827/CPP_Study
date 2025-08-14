#include <stdio.h>

int main() {
    int num[10], list[42]={0,};
    int i, cnt=0;
    
    for(i=0;i<10;i++){
        scanf("%d", &num[i]);
        list[num[i]%42]++;
    }
    
    for(i=0;i<42;i++){
        if(list[i]!=0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}