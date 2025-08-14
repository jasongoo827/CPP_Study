#include <stdio.h>
#include <string.h>

int main() {
    char str[1000003];
    int i, cnt=1;
    
    fgets(str, 1000003, stdin);
    int len=strlen(str);
    
    if(str[0]==' '||str[0]=='\n') cnt=0;
    
    for(i=0;i<len;i++){
        if(str[i]==' '&&str[i+1]!='\n') ++cnt;
    }
    if(str[len-1]==' ') --cnt;
    
    printf("%d", cnt);
    
    return 0;
}