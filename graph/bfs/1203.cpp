#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> topoSort(int n, vector<unordered_set<int>> edge) {
        vector<int> indegree(n, 0);
        vector<int> topoSort;
        queue<int> bfsQueue;

        for (int i = 0; i < n; i++)
            for (int j : edge[i]) indegree[j]++;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) bfsQueue.push(i);
        }

        while (!bfsQueue.empty()) {
            int index = bfsQueue.front();
            bfsQueue.pop();

            for (int i : edge[index]) {
                indegree[i]--;
                if (indegree[i] == 0) bfsQueue.push(i);
            }

            topoSort.push_back(index);
        }

        if (topoSort.size() != n) return {};

        return topoSort;
    }

   public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        vector<int> ans;
        vector<int> groupTopoSort;
        vector<int> itemTopoSort;
        vector<unordered_set<int>> groupEdge;
        vector<unordered_set<int>> itemEdge;
        vector<vector<int>> groupItemTopoSort;

        // count group's topo sort
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        groupEdge.resize(m);
        itemEdge.resize(n);

        for (int i = 0; i < n; i++) {
            for (int beforeItem : beforeItems[i]) {
                if (group[beforeItem] != group[i])
                    groupEdge[group[beforeItem]].insert(group[i]);
                itemEdge[beforeItem].insert(i);
            }
        }

        groupTopoSort = topoSort(m, groupEdge);

        if (groupTopoSort.size() != m) {
            return {};
        }

        // count item's topo sort

        itemTopoSort = topoSort(n, itemEdge);

        if (itemTopoSort.size() != n) {
            return {};
        }

        groupItemTopoSort.resize(m);
        for (int i = 0; i < n; i++) {
            int groupIndex = group[itemTopoSort[i]];
            groupItemTopoSort[groupIndex].push_back(itemTopoSort[i]);
        }

        for (int i = 0; i < m; i++) {
            int groupIndex = groupTopoSort[i];

            for (int i : groupItemTopoSort[groupIndex]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};