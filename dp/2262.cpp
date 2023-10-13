#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution {
   private:
    ll latestAppear[26];

   public:
    long long appealSum(string s) {
        ll n = s.size();
        ll ans = 0;
        ll latestSuffixSum = 0;

        for (int i = 0; i < 26; i++) {
            latestAppear[i] = -1;
        }

        for (ll i = 0; i < n; i++) {
            int charIndex = s[i] - 'a';

            ll beforeLength = -1;
            ll newSuffixSum;

            if(latestAppear[charIndex] != -1)
                beforeLength = latestAppear[charIndex] + 1;

            
            newSuffixSum = latestSuffixSum + 1 + i;

            if(beforeLength != -1)
                newSuffixSum -=  beforeLength;

            ans = ans + newSuffixSum;

            latestSuffixSum = newSuffixSum;
            latestAppear[charIndex] = i;
        }

        return ans;
    }
};