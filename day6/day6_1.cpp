#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll long long

using namespace std;

void divideString(string numsString, vector<ll>  &result)
{
    stringstream ss(numsString.c_str());
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, ',' );
        result.push_back( atoi(substr.c_str()) );
    }
}

int main()
{
    string numsString;
    getline(cin, numsString);
    vector<ll> timers;
    divideString(numsString, timers);
    ll total = 0;

    map<ll, ll> existing; // days left -> population map

    for(auto x: timers) // current state
    {
        ++existing[x + 1];
    }

    ll daysLeft = 80;
    // Go through days left in steps of 7
    while(daysLeft > 7)
    {
        // Update in temp map
        map<ll, ll> temp;
        temp[2] = existing[2] + existing[9]; // 9 - 7 = 2
        temp[1] = existing[1] + existing[8]; // 8 - 7 = 1
        existing[9] = 0; existing[8] = 0; // 9s and 8s wiped away
        // update the others
        for(ll i = 9; i >= 3; --i)
        {
            temp[i] = existing[i] + existing[i - 9 + 7];
        }

        daysLeft -= 7;
        existing = temp;

        // cout << "left: " << daysLeft << " and ";
        // for(auto const &ex: existing)
        //     cout << ex.first << ": " << ex.second << ", ";
        // cout << endl;
    }

    // Do reproductions upto 7
    for(ll i = 1; i <= daysLeft; ++i)
            existing[i] *= 2;

    // Total them up
    for(auto const &ex: existing)
        total += ex.second;

    cout << total << endl;

    return 0;
}
