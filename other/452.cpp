#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution {
   private:
    vector<ll> buffer;
    vector<pair<ll, int>> arr;
    vector<bool> boom;

    class Compare {
       public:
        bool operator()(pair<ll, int>& a, pair<ll, int>& b) {
            if(abs(a.first)!=abs(b.first))
                return abs(a.first) < abs(b.first);
            return a.first > b.first;
        }
    };

   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ll n = points.size();
        ll ans = 0;
        ll l, r;

        if (n == 1) return 1;

        boom.resize(n, false);

        for (int i = 0; i < n; i++) {
            arr.push_back({1e11 + points[i][0], i});
            arr.push_back({-(1e11 + points[i][1]), i});
        }

        sort(arr.begin(), arr.end(), Compare());

        l = arr[0].first;
        r = arr[0].second;
        for (int i = 0; i < arr.size(); i++) {
            if (boom[arr[i].second]) continue;

            if (arr[i].first > 0) {
                buffer.push_back(arr[i].second);
            } else {
                for (int balloon : buffer) boom[balloon] = true;
                ans++;
                buffer.clear();
            }
        }

        return ans;
    }
};