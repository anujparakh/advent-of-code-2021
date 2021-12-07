#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll count = 0;
    // Input one sequence
    ll first; cin >> first;
    ll second; cin >> second;
    ll third; cin >> third;
    while(true)
    {
        // Fourth (for 2nd sequence)
        ll next; cin >> next;
        if(next == 0)
            break;
        // Check sequence of three
        if((first + second + third) < (second + third + next))
            ++count;

        // Update old
        first = second;
        second = third;
        third = next;
    }

    cout << count << endl;
    return 0;
}

// Answer is 1858 for input
