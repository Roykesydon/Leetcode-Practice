#include <algorithm>
#include <iostream>
#include <vector>

#define lowbit(x) (x & -x)
#define MAX_NUM 1000000

using namespace std;

class Solution {
   private:
    int bit[MAX_NUM + 1];

    void update(int index, int x) {
        while (index <= MAX_NUM) {
            bit[index] += x;
            index += lowbit(index);
        }
    }
    int query(int index) {
        int tmp = 0;
        while (index) {
            tmp += bit[index];
            index -= lowbit(index);
        }
        return tmp;
    }
    vector<pair<int, int>> arr;

   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        for (int i = 0; i < properties.size(); i++)
            arr.push_back({properties[i][0], properties[i][1]});

        sort(arr.begin(), arr.end());

        vector<int> tmp;
        int ans = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i != arr.size() - 1 && arr[i].first != arr[i + 1].first) {
                for (auto i : tmp) update(MAX_NUM - i, 1);
                tmp.clear();
            }

            if (query(MAX_NUM - arr[i].second - 1) != 0) ans++;

            tmp.push_back(arr[i].second);
        }

        return ans;
    }
};