#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j, len, groupNum=0;
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
        int alph[26]={0,};
        int GW=1;
        char word[101];
        scanf("%s", word);
        len=strlen(word);\
        if(len==1){
            groupNum+=1;
            continue;
        }
        else{
            for(j=0;j<len;j++){
                if(alph[word[j]-'a']==1){
                    GW=0;
                    break;
                }
                if(word[j]!=word[j+1]){
                    alph[word[j]-'a']=1;
                }
            }
        if(GW==1) groupNum+=1;
        }
    }
    
    printf("%d", groupNum);
    return 0;
}