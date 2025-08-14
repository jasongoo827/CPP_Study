#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int inorder[100001];
int postorder[100001];
int inorderIndex[100001];

void build(int in_left, int in_right, int post_left, int post_right)
{
    if (in_left > in_right || post_left > post_right)
        return;
    
    int root = postorder[post_right];
    cout << root << " ";
    
    int rootIndex = inorderIndex[root];
    int leftSize = rootIndex - in_left;
    
    build(in_left, rootIndex - 1, post_left, post_left + leftSize - 1);
    build(rootIndex + 1, in_right, post_left + leftSize, post_right - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];
    
    build(0, n - 1, 0, n - 1);
    
    return 0;
}
