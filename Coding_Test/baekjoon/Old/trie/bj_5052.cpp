#include <iostream>
#include <string>
#include <vector>

int t, n;

class TrieNode
{
public:
	TrieNode* children[10];
	bool isEnd;

	TrieNode()
	{
		for (int i = 0; i < 10; ++i)
			children[i] = nullptr;
		isEnd = false;
	}
};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}

	bool insert(const std::string& word)
	{
		TrieNode* node = root;
		for (char c : word)
		{
			int idx = c - '0';
			if (!node->children[idx])
				node->children[idx] = new TrieNode();
			node = node->children[idx];
			if (node->isEnd)
				return false;
		}

		node->isEnd = true;
		for (int i = 0; i < 10; ++i)
		{
			if (node->children[i])
				return false;
		}
		return true;
	}
private:
	TrieNode* root;
};



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> t;

	while (t--)
	{
		std::cin >> n;
		std::cin.ignore();

		Trie trie;
		std::vector<std::string> phoneBook;
		bool isConsistent = true;
		while (n--)
		{
			std::string input;
			std::getline(std::cin, input);
			phoneBook.push_back(input);
		}
		for (const auto& pNum : phoneBook)
		{
			if (!trie.insert(pNum))
			{
				isConsistent = false;
				break;
			}
		}
		if (isConsistent)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	return 0;
}