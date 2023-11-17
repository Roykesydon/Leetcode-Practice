#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string maximumBinaryString(string binary) {
        string ans = "";
        int firstZeroBeforeOneIndex = -1;
        int afterZeroCount = 0;

        for (int i = 0; i < binary.size() - 1; i++)
            if (binary[i] == '0' && binary[i + 1] == '1') {
                firstZeroBeforeOneIndex = i;
                break;
            }

        if (firstZeroBeforeOneIndex != -1)
            for (int i = binary.size() - 1; i > firstZeroBeforeOneIndex; i--)
                if (binary[i] == '0') afterZeroCount++;

        if (firstZeroBeforeOneIndex == -1 ||
            (firstZeroBeforeOneIndex != -1 && afterZeroCount == 0)) {
            for (int i = 0; i < binary.size() - 1; i++)
                if (binary[i] == '0' && binary[i + 1] == '0') binary[i] = '1';
            return binary;
        }

        for (int i = 0; i < binary.size(); i++)
            if (i != firstZeroBeforeOneIndex + afterZeroCount)
                ans += '1';
            else
                ans += '0';

        return ans;
    }
};