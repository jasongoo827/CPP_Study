#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int weight[n], height[n], place[n];
    int i,j;
    
    for(i=0;i<n;i++){
        place[i]=1;
        scanf("%d %d", &weight[i], &height[i]);
    }
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if((weight[i]>weight[j])&&(height[i]>height[j])){
                place[j]++;
            }
            else if((weight[i]<weight[j])&&(height[i]<height[j])){
                place[i]++;
            }
        }
    }
    
    for(i=0;i<n;i++){
        printf("%d ", place[i]);
    }
    
    return 0;
}