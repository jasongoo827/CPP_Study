#include <bits/stdc++.h>

using namespace std;

vector<string> paper;
vector<vector<int>> cutted;
const int direction[2][2]={{0,1},{1,0}};

bool cutting(int y, int x, int dir, int len, int delta){
    bool ok=true;
    int ny=direction[dir][0], nx=direction[dir][1];
    for(int i=0;i<len;i++){
        if((cutted[y][x]+=delta)>1) ok=false;
        y+=ny;
        x+=nx;
    }
    return ok;
}

int getVal(int y, int x, int dir, int len){
    string str;
    if(dir==0) str=paper[y].substr(x,len);
    else{
        for(int i=0;i<len;i++){
            str+=string(1,paper[y+i][x]);
        }
    }
    return stoi(str);
}

int solve(int n, int m){
    int y=-1, x=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cutted[i][j]<1){
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1) break;
    }
    if(y==-1) return 0;
   
    int ret=0;
    int maxLen[2]={m-x,n-y};
    for(int dir=0;dir<2;dir++){
        for(int len=1+dir;len<=maxLen[dir];len++){
            if(cutting(y,x,dir,len,1)){
                ret=max(ret,getVal(y,x,dir,len)+solve(n,m));
            }
            cutting(y,x,dir,len,-1);
        }
    }
    return ret;
}

int main() {
    int n,m;
    cin>>n>>m;
    cutted=vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        paper.push_back(str);
    }
    cout<<solve(n,m);
}