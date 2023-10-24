#include <iostream>
#include <stack>
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
    int dir = 0;  // 0: left to right; 1: right to left;

   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;

        stack<TreeNode *> st;
        if (root == nullptr) return ans;

        st.push(root);
        while (true) {
            vector<int> tmp;
            stack<TreeNode *> tmpStack;

            while (!st.empty()) {
                auto top = st.top();
                st.pop();

                tmp.push_back(top->val);

                if (dir == 0) {
                    if (top->left != nullptr) tmpStack.push(top->left);
                    if (top->right != nullptr) tmpStack.push(top->right);
                } else if (dir == 1) {
                    if (top->right != nullptr) tmpStack.push(top->right);
                    if (top->left != nullptr) tmpStack.push(top->left);
                }
            }

            ans.push_back(tmp);
            dir ^= 1;
            st = tmpStack;

            if (st.size() == 0) break;
        }

        return ans;
    }
};