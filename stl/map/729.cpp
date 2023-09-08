#include <iostream>
#include <map>

using namespace std;

class MyCalendar {
   private:
    map<int, int> mp;

   public:
    MyCalendar() {}

    bool book(int start, int end) {
        // check if can book
        auto result = mp.upper_bound(start);

        // check can find or not
        if (result != mp.end()) {
            if (result->second < end) {
                return false;
            }
        }

        // book it
        mp[end] = start;

        return true;
    }
};