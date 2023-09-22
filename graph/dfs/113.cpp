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
    vector<vector<int>> paths;

    void findPath(TreeNode *curNode, vector<int> &path, int &sum, int &target) {
        if (curNode == nullptr) return;
        path.push_back(curNode->val);
        sum += curNode->val;
        if (curNode->left == nullptr && curNode->right == nullptr &&
            sum == target)
            paths.push_back(path);
        
        findPath(curNode->left, path, sum, target);
        findPath(curNode->right, path, sum, target);

        path.pop_back();
        sum -= curNode->val;
    }

   public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        int sum = 0;
        findPath(root, path, sum, targetSum);
        return paths;
    }
};