#include <iostream>
#include <string>
#include <vector>
#define MAX 10

using namespace std;

int t, n;
vector<char*> pnum;

struct s_trie
{
    bool finish;
    s_trie *node[MAX];

    s_trie()
    {
        finish = false;
        for (int i = 0; i < MAX; ++i)
            node[i] = NULL;
    }
    void insert(char *str)
    {
        if (*str == '\0')
            finish = true;
        int cur = *str - '0';
        if (node[cur] == NULL)
            node[cur] = new s_trie();
        node[cur]->insert(str + 1);
    }
    bool find(char *str)
    {
        int cur = *str - '\0';
        if (node[cur] == NULL)
            return false;
        node[cur]->find(str + 1);
    }
};

typedef s_trie TRIE;

void solve()
{
    TRIE *root = new TRIE();
    for (auto& str: pnum)
    {

        root->insert(str);
    }
    
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n;
        char* s;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            pnum.push_back(s);
        }
        solve();
    }
}

int main(void)
{

    return (0);
}