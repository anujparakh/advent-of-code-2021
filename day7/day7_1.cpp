#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <fstream>

#define ll long long

using namespace std;

int main()
{
    vector<ll> nums;
    ll total = 0;
    ifstream infile("input.txt");
    while(!infile.eof())
    {
        ll x; infile >> x;
        char c; infile >> c;
        nums.push_back(x);
        total += x;
        cout << "working " << x << endl;
    }
    cout << "finished input \n";
    ll avg = ceil(total / (double) (nums.size()));

    sort(nums.begin(), nums.end());
    // Median would work too
    ll start = avg;
    ll lastCost = -1;
    map<ll, ll> costs;
    // precalculate costs
    for(ll i = 1; i < nums[nums.size() - 1]; ++i)
    {
        costs[i] = i;
    }

    for(ll i = avg; i >= nums[0]; --i)
    {
        ll cost = 0;
        for(auto x: nums)
        {
            cost += costs[abs(x - i)];
        }

        if(lastCost == -1) // first
            lastCost = cost;
        else if(cost > lastCost)
            break;
        else
            lastCost = cost;
    }

    cout << lastCost << endl;

    return 0;
}