#include <iostream>

using namespace std;

// boj 5639

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    void insert(TreeNode* node)
    {
        if (node->val > val)
        {
            if (right == nullptr)
                right = node;
            else
                right->insert(node);
        }
        else
        {
            if (left == nullptr)
                left = node;
            else
                left->insert(node);
        }
    }
};

void postorder(TreeNode* node)
{
    if (node->left != nullptr)
        postorder(node->left);
    if (node->right != nullptr)
        postorder(node->right);
    cout << node->val << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool first = true;
    TreeNode *root = new TreeNode();

    while (cin >> n)
    {
        if (first)
        {
            root->val = n;
            first = false;
        }
        else
        {
            TreeNode *node = new TreeNode();
            node->val = n;
            root->insert(node);
        }
    }

    postorder(root);

    return 0;
}