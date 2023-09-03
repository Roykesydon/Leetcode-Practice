#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   private:
    unordered_map<char, int> count;
    unordered_map<char, int> curCount;

   public:
    string minWindow(string s, string t) {
        int l, r, curTotal;
        int n = s.size();
        int m = t.size();

        string ans = "";

        for (char ch : t) count[ch]++;

        curTotal = 0;
        l = 0;
        r = 0;

        while (r < n) {
            char rChar = s[r];
            if (count.count(rChar)) {
                curCount[rChar]++;
                if (curCount[rChar] <= count[rChar]) curTotal++;

                while(!count.count(s[l]) || curCount[s[l]] > count[s[l]]){
                    if(count.count(s[l]))
                        curCount[s[l]]--;
                    l++;
                }

                if(curTotal == m){
                    if (r - l + 1 < ans.size() || ans.size() == 0) {
                        ans = s.substr(l, r - l + 1);
                    }
                }
            }
            r++;
        }

        return ans;
    }
};