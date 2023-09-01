#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int gcd(int a, int b) { return (b == 0) ? (a) : (gcd(b, a % b)); }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slope;
            int max_slope_count = 0;
            int same_point = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0] &&
                    points[j][1] == points[i][1]) {
                    same_point++;
                }

                else {
                    int dy = points[j][1] - points[i][1];
                    int dx = points[j][0] - points[i][0];

                    if (dx != 0 && dy != 0) {
                        int origin_dy = dy, origin_dx = dx;
                        dy /= gcd(origin_dy, origin_dx);
                        dx /= gcd(origin_dy, origin_dx);
                    }

                    if (dx == 0) dy = 1;
                    if (dy == 0) dx = 1;

                    slope[{dy, dx}]++;
                }
            }
            ans = max(ans, same_point);

            for (auto key_val : slope) {
                ans = max(ans, key_val.second + same_point);
            }
        }
        return ans;
    }
};