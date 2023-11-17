#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());

        int ans = 0;
        int n = processorTime.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 4; j++)
                ans =
                    max(ans, processorTime[i] + tasks[4 * n - 1 - (i * 4 + j)]);

        return ans;
    }
};