#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    priority_queue<pair<double, int>> pq;

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>>ans;

        for (int i=0;i<n;i++) {
            vector<int>point = points[i];
            double dis = sqrt(1.0 * point[0]*point[0] + 1.0*point[1]*point[1]);
            pq.push({-dis, i});
        }

        for(int i=0;i<k;i++){
            auto u = pq.top();
            pq.pop();
            ans.push_back(points[u.second]);
        }
        return ans;
    }
};