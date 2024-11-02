#include <iostream>
#include <vector>
#include <iomanip>

#define MAX 26

using namespace std;

int n;

class TrieNode
{
public:
    TrieNode    *children[MAX];
    bool        isEnd;
    int         numChild;

    TrieNode()
    {
        isEnd = false;
        numChild = 0;
        for (int i = 0; i < MAX; ++i)
            children[i] = nullptr;
    }
    ~TrieNode()
    {
        for (int i = 0; i < MAX; ++i)
        {
            if (children[i])
            {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        delete root;
    }

    void insert(const string& word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
                node->numChild++;
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    int countBtn(const string& word)
    {
        TrieNode *node = root;
        int cnt = 1;
        
        for (size_t i = 0; i < word.size(); ++i)
        {
            int idx = word[i] - 'a';
            node = node->children[idx];
            if (i == word.size() - 1)
                break;
            else if (node->numChild == 1 && !node->isEnd)
                continue;
            else
                cnt++;
        }
        return cnt;
    }

private:
    TrieNode    *root;
};

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    while(cin >> n)
    {
        Trie trie;
        vector<string> dictionary;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            string word;
            cin >> word;
            trie.insert(word);
            dictionary.push_back(word);
        }
        for (const auto& word : dictionary)
            sum += trie.countBtn(word);
        
        cout << fixed << setprecision(2) << static_cast<double>(sum) / n << '\n';
    }
}