#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> edge;
    vector<int> vis;
    vector<int> ans;
    bool cycle = false;
    void dfs(int index) {
        if (vis[index] == 1) {
            cycle = true;
            return;
        } else if (vis[index] == 2)
            return;
        else if (vis[index] == 0) {
            vis[index] = 1;
            for (int toNode : edge[index]) dfs(toNode);
            vis[index] = 2;
        }
        ans.push_back(index);
    }

   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        vis.resize(numCourses, 0);

        for (vector<int> prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];

            edge[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) dfs(i);

        if (cycle) return vector<int>();

        reverse(ans.begin(), ans.end());

        return ans;
    }
};