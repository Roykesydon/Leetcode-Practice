#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   private:
    stack<pair<int, int>> st;  // height, index
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int h = height[i];
            int lastHeight = -1;

            if (h == 0) continue;

            while (!st.empty() && st.top().first <= h) {
                int stackHeight = st.top().first;
                int stackIndex = st.top().second;

                if (lastHeight == -1)
                    ans += (i - stackIndex - 1) * stackHeight;
                else
                    ans += (i - stackIndex - 1) * (stackHeight - lastHeight);

                lastHeight = stackHeight;

                st.pop();
            }

            if (!st.empty() && h > lastHeight)
                if (lastHeight == -1)
                    ans += min(st.top().first, h) * (i - st.top().second - 1);
                else
                    ans += min((st.top().first - lastHeight), h - lastHeight) *
                           (i - st.top().second - 1);

            st.push({h, i});
        }

        return ans;
    }
};