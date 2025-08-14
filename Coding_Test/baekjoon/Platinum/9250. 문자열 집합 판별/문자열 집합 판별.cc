#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define MAX 26

using namespace std;

class TrieNode
{
public:
	TrieNode*	children[MAX];
	TrieNode*	fail;
	bool		isEnd;

	TrieNode()
	{
		for (int i = 0; i < MAX; ++i)
			children[i] = nullptr;
		fail = nullptr;
		isEnd = false;
	}
};

class Trie
{
public:
	TrieNode* root;

	Trie()
	{
		root = new TrieNode();
	}

	void insert(const string& s)
	{
		TrieNode* node = root;
		for (auto c : s)
		{
			int idx = c - 'a';
			if (!node->children[idx])
				node->children[idx] = new TrieNode();
			node = node->children[idx];
		}
		node->isEnd = true;
	}

	void buildFailLinks()
	{
		queue<TrieNode*> q;
		root->fail = root;

		for (int i = 0; i < MAX; ++i)
		{
			if (root->children[i])
			{
				root->children[i]->fail = root;
				q.push(root->children[i]);
			}
			else
				root->children[i] = root;
		}
		while (!q.empty())
		{
			TrieNode* cur = q.front();
			q.pop();

			for (int i = 0; i < MAX; ++i)
			{
				if (cur->children[i])
				{
					TrieNode* child = cur->children[i];
					TrieNode* fail = cur->fail;

					while (fail != root && !fail->children[i])
						fail = fail->fail;
					if (fail->children[i])
						fail = fail->children[i];

					child->fail = fail;
					if (fail->isEnd)
						child->isEnd = true;
					q.push(child);
				}
			}
		}
	}

	bool search(const string& s)
	{
		TrieNode* node = root;
		for (auto c : s)
		{
			int idx = c - 'a';
			while (node != root && !node->children[idx])
				node = node->fail;
			if (node->children[idx])
				node = node->children[idx];
			if (node->isEnd)
				return true;
		}
		return false;
	}
};

int n, q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	Trie trie;
	string input;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		trie.insert(input);
	}
	trie.buildFailLinks();
	cin >> q;
	while (q--)
	{
		cin >> input;
		if (trie.search(input))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
