#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        vector<pair<int, int>> arr;
        int ans = 0;
        int sum = 0;

        arr.resize(n);
        for (int i = 0; i < n; i++) arr[i] = {tiles[i][0], tiles[i][1]};
        sort(arr.begin(), arr.end());

        int l = 0;
        int r = 0;
        while (l < n) {
            while ((r < n && arr[r].first <= arr[l].first + carpetLen - 1)) {
                sum += arr[r].second - arr[r].first + 1;
                r++;
            }

            int tmp;
            if (r == l + 1)
                tmp = min(sum, carpetLen);
            else if (arr[r - 1].second <= arr[l].first + carpetLen - 1)
                tmp = sum;
            else
                tmp = sum -
                      ((arr[r - 1].second - arr[r - 1].first + 1) -
                       ((arr[l].first + carpetLen - 1) - arr[r - 1].first + 1));

            ans = max(ans, tmp);
            sum -= arr[l].second - arr[l].first + 1;
            l++;
        }

        return ans;
    }
};