#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curPtr, *lastPtr, *leftPtr, *lastLeftPtr;
        int cnt = 0;
        lastPtr = nullptr;
        lastLeftPtr = nullptr;
        curPtr = head;
        while (curPtr != nullptr) {
            ListNode* nextPtr = curPtr->next;
            cnt++;
            if (cnt == left) {
                lastLeftPtr = lastPtr;
                leftPtr = curPtr;
            }
            if (cnt > left && cnt < right) {
                curPtr->next = lastPtr;
            }

            if (cnt == right) {
                if (lastLeftPtr != nullptr)
                    lastLeftPtr->next = curPtr;
                else
                    head = curPtr;

                curPtr->next = lastPtr;
                leftPtr->next = nextPtr;

                break;
            }

            lastPtr = curPtr;
            curPtr = nextPtr;
        }
        return head;
    }
};