#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    int i, cnt=0;
    
    scanf("%s", word);
    
    for(i=0;word[i]!='\0';i++){
        if(word[i]=='c'&&(word[i+1]=='='||word[i+1]=='-')) continue;
        if(word[i]=='d'){
            if(word[i+1]=='-') continue;
            else if(word[i+1]=='z'&&word[i+2]=='=') continue;
        }
        if((word[i]=='l'||word[i]=='n')&&word[i+1]=='j') continue;
        if((word[i]=='s'||word[i]=='z')&&word[i+1]=='=') continue;
        else cnt++;
    }
    printf("%d", cnt);
    return 0;
}