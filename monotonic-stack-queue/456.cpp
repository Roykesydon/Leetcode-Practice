#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int> &nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int n = nums.size();

        if (n < 3) return false;

        stack<pair<int, int>> st;

        st.push({nums[0], -1e9});

        for (int i = 1; i < n; i++) {
            pair<int, int> u = st.top();
            int val = nums[i];

            if (val == u.first || val == u.second) continue;

            st.pop();

            if (u.second == -1e9) {
                if (val < u.first)
                    st.push({val, -1e9});
                else if (val > u.first) {
                    u.second = val;
                    while (!st.empty()) {
                        pair<int, int> top = st.top();

                        if (val > top.first && val < top.second)
                            return true;

                        if (u.second < top.first) {
                            break;
                        } else if (u.second >= top.first) {
                            st.pop();
                            u = {u.first, max(u.second, top.second)};
                        }
                    }
                    st.push(u);
                }
            } else {
                if (val > u.second) {
                    u.second = val;
                    while (!st.empty()) {
                        pair<int, int> top = st.top();

                        if (val > top.first && val < top.second)
                            return true;

                        if (u.second < top.first) {
                            break;
                        } else if (u.second >= top.first) {
                            st.pop();
                            u = {u.first, max(u.second, top.second)};
                        }
                    }
                    st.push(u);
                } else if (val < u.first) {
                    st.push(u);
                    st.push({val, -1e9});
                } else if (val > u.first && val < u.second)
                    return true;
            }
        }
        return false;
    }
};