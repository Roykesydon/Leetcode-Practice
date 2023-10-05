#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int cur = -1;
        int ans = 0;
        for(int price: prices){
            if(cur==-1){
                cur = price;
                continue;
            }
            
            if(price > cur){
                ans += price - cur;
                cur = price;
            }
            else{
                cur = price;
            }
        }

        return ans;
    }
};