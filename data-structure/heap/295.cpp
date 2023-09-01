#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
   private:
    class CompareLess {
       public:
        bool operator()(int a, int b) { return a > b; }
    };
    priority_queue<int, vector<int>, CompareLess> minHeap;
    priority_queue<int> maxHeap;
    int numberCount = 0;

   public:
    MedianFinder() {
        while (!minHeap.empty()) minHeap.pop();
        while (!maxHeap.empty()) maxHeap.pop();
        numberCount = 0;
    }

    void addNum(int num) {
        vector<int> sortedVector;

        sortedVector.push_back(num);
        if (!minHeap.empty()) {
            sortedVector.push_back(minHeap.top());
            minHeap.pop();
        }

        while (maxHeap.size() != minHeap.size()) {
            sortedVector.push_back(maxHeap.top());
            maxHeap.pop();
        }

        sort(sortedVector.begin(), sortedVector.end());

        if (sortedVector.size() == 1) {
            maxHeap.push(sortedVector[0]);
        } else if (sortedVector.size() == 2) {
            maxHeap.push(sortedVector[0]);
            minHeap.push(sortedVector[1]);
        } else if (sortedVector.size() == 3) {
            maxHeap.push(sortedVector[0]);
            maxHeap.push(sortedVector[1]);
            minHeap.push(sortedVector[2]);
        } else if (sortedVector.size() == 4) {
            maxHeap.push(sortedVector[0]);
            maxHeap.push(sortedVector[1]);
            minHeap.push(sortedVector[2]);
            minHeap.push(sortedVector[3]);
        }

        numberCount++;
    }

    double findMedian() {
        vector<int> sortedVector;

        if (!minHeap.empty()) {
            sortedVector.push_back(minHeap.top());
            minHeap.pop();
        }

        while (!maxHeap.empty() && maxHeap.size() != minHeap.size()) {
            sortedVector.push_back(maxHeap.top());
            maxHeap.pop();
        }

        sort(sortedVector.begin(), sortedVector.end());

        for (int i = 0; i < sortedVector.size(); i++) addNum(sortedVector[i]);

        if (sortedVector.size() == 1)
            return sortedVector[0];
        else if (sortedVector.size() == 2)
            return (double(sortedVector[0]) + double(sortedVector[1])) / 2;
        else if (sortedVector.size() == 3)
            return sortedVector[1];

        return 0;
    }
};