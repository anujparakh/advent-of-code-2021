#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>

#define ll long long

using namespace std;

int main()
{
    ll horizontal = 0, depth = 0, aim = 0;
    while(true)
    {
        string dir; cin >> dir;
        if(dir == "end")
            break;

        ll x; cin >> x;
        if(dir == "forward")
        {
            horizontal += x;
            depth += aim * x;
        }
        else if(dir == "down")
            aim += x;
        else if(dir == "up")
            aim -= x;
    }

    cout << horizontal * depth << endl;
    return 0;
}