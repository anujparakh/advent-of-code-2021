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
    ll horizontal = 0, depth = 0;
    while(true)
    {
        string dir; cin >> dir;
        if(dir == "end")
            break;

        ll x; cin >> x;
        if(dir == "forward")
            horizontal += x;
        else if(dir == "down")
            depth += x;
        else if(dir == "up")
            depth -= x;
    }

    cout << horizontal * depth << endl;
    return 0;
}