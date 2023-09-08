#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        int minRegionLength;
        int cnt;
        ListNode *curPtr = head;
        ListNode *regionStart;
        vector<ListNode *> ans;

        while (curPtr != nullptr) {
            n++;
            curPtr = curPtr->next;
        }
        minRegionLength = n / k;

        curPtr = head;
        regionStart = curPtr;
        cnt = 0;

        while (curPtr != nullptr) {
            cnt++;
            if (cnt == minRegionLength + ((n % k) ? (1) : (0))) {
                ans.push_back(regionStart);
                regionStart = curPtr->next;

                ListNode *next = curPtr->next;
                curPtr->next = nullptr;
                curPtr = next;
                cnt = 0;

                if (n % k) n--;
                continue;
            }

            curPtr = curPtr->next;
        }

        for (int i = ans.size(); i < k; i++) ans.push_back(nullptr);

        return ans;
    }
};