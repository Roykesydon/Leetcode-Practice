#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    class CompareSmall {
       public:
        bool operator()(int a, int b) { return a > b; }
    };

    vector<priority_queue<int, vector<int>, CompareSmall>> pq;
    vector<int> sum;

   public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        int ans = -1e9;

        pq.resize(n);
        sum.resize(n);
        for (int i = 0; i < n; i++) ans = max(ans, vals[i]);
        for (int i = 0; i < n; i++) sum[i] = vals[i];

        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // u
            if (vals[v] > 0) {
                pq[u].push(vals[v]);
                sum[u] += vals[v];
                if (pq[u].size() > k) {
                    int top = pq[u].top();
                    pq[u].pop();
                    sum[u] -= top;
                }
                ans = max(ans, sum[u]);
            }

            // v
            if (vals[u] > 0) {
                pq[v].push(vals[u]);
                sum[v] += vals[u];
                if (pq[v].size() > k) {
                    int top = pq[v].top();
                    pq[v].pop();
                    sum[v] -= top;
                }
                ans = max(ans, sum[v]);
            }
        }

        return ans;
    }
};