#include <stdio.h>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int res=(v-a)/(a-b);
    
    if(a<=b){
        if(v<=a) printf("1");
        else printf("-1");
    }
    else{
        if(res*(a-b)>=(v-a)) printf("%d", res+1);
        else printf("%d", res+2);
    }
    return 0; 
}