#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> father;
    vector<bool> vis;

    int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }

    void merge(int x, int y) { father[find(x)] = find(y); }

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cityCount = isConnected.size();
        int ans = 0;

        father.resize(cityCount);
        vis.resize(cityCount, false);

        for (int i = 0; i < cityCount; i++) father[i] = i;

        for (int i = 0; i < cityCount; i++) {
            for (int j = i + 1; j < cityCount; j++) {
                if (isConnected[i][j]) merge(i, j);
            }
        }

        for (int i = 0; i < cityCount; i++) {
            if (!vis[find(i)]) {
                vis[find(i)] = true;
                ans++;
            }
        }

        return ans;
    }
};