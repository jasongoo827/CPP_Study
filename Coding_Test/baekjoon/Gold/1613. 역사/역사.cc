#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

const int MAX_V=401;
const int INF=987654321;

int V,E,s;
int A,B;

int adj[MAX_V][MAX_V];

void floyd()
{
    for(int i=1;i<=V;++i)
        adj[i][i]=0;

    for(int k=1;k<=V;++k)
        for(int i=1;i<=V;++i)
            for(int j=1;j<=V;++j)
                if (adj[i][k] != INF && adj[k][j] != INF && i!=j)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;

    for(int i=1;i<=V;++i)
        for(int j=1;j<=V;++j)
            adj[i][j]=INF;

    while(E--)
    {
        cin>>A>>B;
        adj[A][B]=1;
    }

    floyd();

    cin>>s;
    while(s--)
    {
        cin>>A>>B;
        if(adj[A][B]!=INF)
            cout<<-1<<"\n";
        else
        {
            if(adj[B][A]!=INF)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
    }

    return 0;
}
