#include <iostream>
#include <vector>

#define MXN 100005

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *father[MXN];
    TreeNode *newRoot;
    int ans = 0;

    void preDfs(TreeNode *curNode, TreeNode *fatherNode, int &start)
    {
        if (curNode->val == start)
            newRoot = curNode;
        father[curNode->val] = fatherNode;
        if (curNode->left != nullptr)
            preDfs(curNode->left, curNode, start);
        if (curNode->right != nullptr)
            preDfs(curNode->right, curNode, start);
    }
    void dfs(TreeNode *curNode, int dis, TreeNode *fromNode)
    {
        ans = max(ans, dis);
        if (curNode->left != nullptr && curNode->left != fromNode)
            dfs(curNode->left, dis + 1, curNode);
        if (curNode->right != nullptr && curNode->right != fromNode)
            dfs(curNode->right, dis + 1, curNode);
        if (father[curNode->val] != nullptr && father[curNode->val] != fromNode)
            dfs(father[curNode->val], dis + 1, curNode);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        preDfs(root, nullptr, start);
        dfs(newRoot, 0, nullptr);

        return ans;
    }
};