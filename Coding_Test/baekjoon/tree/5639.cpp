#include <iostream>

using namespace std;

// boj 5639

// #include <iostream>
// #include <vector>

// using namespace std;

// int datas[10000];

// struct Node
// {
//     int var;
//     Node *left;
//     Node *right;
// };

// Node *makeTree(int min, int max, int &i, int maxIdx)
// {
//     if (i >= maxIdx)
//         return nullptr;

//     if (datas[i] <= min || datas[i] >= max)
//     {
//         i--;
//         return nullptr;
//     }

//     Node *node = new Node();
//     node->var = datas[i];
//     node->left = NULL;
//     node->right = NULL;

//     node->left = makeTree(min, node->var, ++i, maxIdx);
//     node->right = makeTree(node->var, max, ++i, maxIdx);
//     return node;
// }

// void post(Node *node)
// {
//     if (node == NULL)
//         return;
//     post(node->left);
//     post(node->right);
//     cout << node->var << "\n";
// }

// int main(int argc, char **argv)
// {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int x;
//     int idx = 0;
//     while (cin >> x)
//     {
//         datas[idx++] = x;
//     }
//     int i = 0;

//     Node *root = makeTree(0, 1000000, i, idx);
//     post(root);

//     return 0;
// }

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