#include <iostream>
#include <vector>

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
    void solve(TreeNode *curNode, int sum) {
        sum = sum * 10 + curNode->val;
        if (curNode->left == nullptr && curNode->right == nullptr) {
            ans += sum;
            return ;
        }
        if(curNode->left != nullptr)
            solve(curNode->left, sum);
        if(curNode->right != nullptr)
            solve(curNode->right, sum);
    }

   public:
    int sumNumbers(TreeNode *root) {
        if (root != nullptr) {
            solve(root, 0);
        }

        return ans;
    }
};