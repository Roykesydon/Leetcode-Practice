#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   private:
    stack<pair<int, int>> st;  // height, index

   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int index = i;

            while (!st.empty() && st.top().first >= height) {
                int stackIndex = st.top().second;
                int stackHeight = st.top().first;

                ans = max(ans, (i - stackIndex) * stackHeight);

                index = stackIndex;
                st.pop();
            }

            st.push({height, index});
        }

        while (!st.empty()) {
            int stackIndex = st.top().second;
            int stackHeight = st.top().first;

            ans = max(ans, (n - stackIndex) * stackHeight);
            st.pop();
        }

        return ans;
    }
};