#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
   public:
    int get(int index);
    int length();
};

class Solution {
   private:
    int binarySearch(int l, int r, int target, MountainArray &mountainArr,
                     bool reverse = false) {
        while (l < r) {
            int mid = (l + r) / 2;

            int targetValue = target * ((reverse) ? (-1) : (1));
            int midValue = mountainArr.get(mid) * ((reverse) ? (-1) : (1));

            if (targetValue <= midValue)
                r = mid;
            else
                l = mid + 1;
        }

        if (mountainArr.get(r) == target) return r;

        return -1;
    }

   public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l, r, ml, mr;
        int maxn, maxIndex;
        int ans;

        l = 0;
        r = mountainArr.length() - 1;

        // search mountain peak
        // 這邊其實可以用二分搜解決，只要比較 mid 和 mid + 1 就好
        while (l < r) {
            if (r - l < 4) {
                maxn = 0;
                maxIndex = -1;

                maxn = mountainArr.get(l);
                maxIndex = l;

                for (int i = l + 1; i <= r; i++) {
                    int val = mountainArr.get(i);
                    if (val > maxn) {
                        maxn = val;
                        maxIndex = i;
                    }
                }
                break;
            }

            ml = (r - l) / 3 + l;
            mr = ((r - l) * 2) / 3 + l;

            int mlValue = mountainArr.get(ml);
            int mrValue = mountainArr.get(mr);

            if (mlValue > mrValue) {
                r = mr;
            } else {
                l = ml;
            }
        }

        // search peak left
        ans = binarySearch(0, maxIndex, target, mountainArr);

        if (ans != -1) return ans;

        // search peak right
        ans = binarySearch(maxIndex, mountainArr.length() - 1, target,
                           mountainArr, true);

        if (ans != -1) return ans;

        return -1;
    }
};