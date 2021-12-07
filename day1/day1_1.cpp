#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll count = 0;
    // before
    ll x; cin >> x;
    while(true)
    {
        // after
        ll y; cin >> y;
        if(y == 0) // end
            break;
        // check increase
        if(y > x)
        {
            ++count;
        }
        // update before
        x = y;
    }
    cout << count << endl;
    return 0;
}

// Answer is 1832 for input