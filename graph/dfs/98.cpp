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
    bool checkSubTree(TreeNode *root, TreeNode *father, long long minn,
                      long long maxn) {
        if (root == nullptr) return true;

        if (father == nullptr) {
            minn = root->val;
            maxn = root->val;

            if (!checkSubTree(root->left, root, -1e18,
                              min(maxn, (long long)root->val)))
                return false;
            if (!checkSubTree(root->right, root,
                              max(minn, (long long)root->val), 1e18))
                return false;
        }

        if (father != nullptr) {
            if (root == father->left && root->val >= father->val) return false;
            if (root == father->right && root->val <= father->val) return false;

            if (root->val <= minn || root->val >= maxn) return false;

            if (!checkSubTree(root->left, root, minn,
                              min(maxn, (long long)root->val)))
                return false;
            if (!checkSubTree(root->right, root,
                              max(minn, (long long)root->val), maxn))
                return false;
        }

        return true;
    }

   public:
    bool isValidBST(TreeNode *root) {
        return checkSubTree(root, nullptr, 0, 0);
    }
};