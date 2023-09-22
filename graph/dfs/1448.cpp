#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   private:
    int ans = 0;
    void solve(TreeNode *root, int maxn) {
        if (root->val >= maxn) ans++;
        if (root->left != nullptr) solve(root->left, max(root->val, maxn));
        if (root->right != nullptr) solve(root->right, max(root->val, maxn));
    }

   public:
    int goodNodes(TreeNode *root) {
        solve(root, -(1e9));
        return ans;
    }
};