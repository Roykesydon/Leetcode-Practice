#include <iostream>

using namespace std;

class Solution {
   private:
    bool solve(string s1, string s2) {
        int cnt[26];
        int ansFlag = true;

        for (int i = 0; i < 26; i++) cnt[i] = 0;

        for (char ch : s1) cnt[ch - 'a']++;

        for (char ch : s2) {
            bool flag = false;
            for (int i = ch - 'a'; i < 26; i++) {
                if (cnt[i]) {
                    cnt[i]--;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ansFlag = false;
                break;
            }
        }

        return ansFlag;
    }

   public:
    bool checkIfCanBreak(string s1, string s2) {
        return (solve(s1, s2) || solve(s2, s1));
    }
};