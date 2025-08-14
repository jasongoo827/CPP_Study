#include <iostream>
#include <algorithm>
using namespace std;

int Getsum(int arr[]){
    int sum=0;
    for(int i=0;i<9;++i){
        sum+=arr[i];
    }
    return sum;
}

int pickDwarfs(int arr[]){
    int sum=Getsum(arr);
    for(int i=0;i<8;++i){
        for(int j=i+1;j<9;++j){
            if(sum-(arr[i]+arr[j])==100){
                arr[i]=0;
                arr[j]=0;
                return 0;
            }
        }
    }
    return -1;
}

int main() {
    int dwarfs[9];
    for(int i=0;i<9;++i){
        cin>>dwarfs[i];
    }
    
    pickDwarfs(dwarfs);
    sort(dwarfs, dwarfs+9);
    
    for(int i=2;i<9;++i){
        cout<<dwarfs[i]<<endl;
    }
    return 0;
}