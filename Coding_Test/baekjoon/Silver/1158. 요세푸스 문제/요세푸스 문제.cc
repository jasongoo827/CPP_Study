#include <iostream>
#include <queue>

using namespace std;

int n,k;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;

    cin>>n>>k;
    temp = k;

    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }

    cout<<"<";
    while(!q.empty())
    {
        if(k==1) break;
        if(temp == 1)
        {
            if(q.size()==1)
                cout<<q.front();
            else
                cout<<q.front()<<", ";
            q.pop();
            temp = k;
        }

        q.push(q.front());
        q.pop();
        temp--;
    }

    while(!q.empty())
    {
        if(q.size()==1) cout<<q.front();
        else cout<<q.front()<<", ";
        q.pop();
    }
    cout<<">";

    return 0;
}
