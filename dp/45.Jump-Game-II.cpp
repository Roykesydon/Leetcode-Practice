#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
   public:
    int jump(vector<int>& nums) {
        int currentFurthestPosition = 0;
        int lastFurthestPosition = 0;
        int leastStepToDestination = 0;
        int size = nums.size();
        if(size == 1)
            return 0;

        for (int i = 0; i < size; i++) {
            currentFurthestPosition = max(currentFurthestPosition, i + nums[i]);

            if (i == lastFurthestPosition) {
                lastFurthestPosition = currentFurthestPosition;
                leastStepToDestination++;
                if (currentFurthestPosition >= size - 1) break;
            }
        }
        return leastStepToDestination;
    }
};

int main() {
    int n;
    vector<int> tmp;
    cin >> n;
    tmp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp[i];
    }
    cout << Solution().jump(tmp) << '\n';
}