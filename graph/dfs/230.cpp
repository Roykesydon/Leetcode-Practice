#include <iostream>
#include <unordered_map>

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
    unordered_map<TreeNode *, int> cnt;
    int ans = 0;
    int n = 0;

    int dfs(TreeNode *curNode) {
        n++;
        int leftCount = 0;
        int rightCount = 0;

        if (curNode->left != nullptr) leftCount = dfs(curNode->left);
        if (curNode->right != nullptr) rightCount = dfs(curNode->right);

        cnt[curNode] = leftCount + 1 + rightCount;

        return cnt[curNode];
    }

    void dfs2(TreeNode *curNode, int k) {
        // cout<<curNode->val<<'\n';
        int leftCount = 0;
        int rightCount = 0;
        if (curNode->left != nullptr) leftCount = cnt[curNode->left];
        if (curNode->right != nullptr) rightCount = cnt[curNode->right];

        if (leftCount == k - 1 || cnt[curNode] - rightCount == k) {
            ans = curNode->val;
            return;
        }

        if (leftCount > k - 1)
            dfs2(curNode->left, k);
        else if (rightCount)
            dfs2(curNode->right, k - leftCount - 1);
    }

   public:
    int kthSmallest(TreeNode *root, int k) {
        dfs(root);
        dfs2(root, k);

        return ans;
    }
};