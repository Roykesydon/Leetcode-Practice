#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define MXN 100005
#define ll long long

using namespace std;

class Solution
{
private:
    class Passenger
    {
    public:
        ll start;
        ll end;
        ll tips;

        Passenger(ll _start, ll _end, ll _tips)
        {
            start = _start;
            end = _end;
            tips = _tips;
        }
    };

    class PassengerCompare
    {
    public:
        bool operator()(Passenger a, Passenger b)
        {
            if (a.start != b.start)
                return a.start < b.start;
            if (a.end != b.end)
                return a.end < b.end;
            return a.tips < b.tips;
        }
    };

    vector<Passenger>
        arr;
    set<pair<ll, ll>> dp;

public:
    long long
    maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        ll ans = 0;
        for (auto ride : rides)
            arr.push_back(Passenger(ride[0], ride[1], ride[2]));

        sort(arr.begin(), arr.end(), PassengerCompare());
        n = arr.size();

        for (int i = n - 1; i >= 0; i--)
        {

            ll tmp = arr[i].tips + arr[i].end - arr[i].start;
            auto after = dp.lower_bound({arr[i].end, -1});
            if (after != dp.end())
                tmp += (*after).second;

            ans = max(ans, tmp);

            auto newElement = dp.lower_bound({arr[i].start, -1});
            if (newElement == dp.end())
            {
                dp.insert({arr[i].start, tmp});
                continue;
            }

            ll newSecond = tmp;
            if ((*newElement).first == arr[i].start)
            {
                newSecond = max(newSecond, newElement->second);
                dp.erase(newElement);
            }

            dp.insert({arr[i].start, newSecond});
            newElement = dp.lower_bound({arr[i].start, -1});

            auto tmpPointer = newElement;
            tmpPointer++;
            if (tmpPointer != dp.end() && tmpPointer->second >= newSecond)
            {
                dp.erase(newElement);
            }
        }

        return ans;
    }
};`