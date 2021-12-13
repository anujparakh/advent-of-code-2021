#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll long long

using namespace std;

int main()
{
    ll width, height;
    cin >> width >> height;
    vector<vector<ll> > table(height);
    for(ll i = 0; i < height; ++i)
        table[i] = vector<ll>(width);

    while(true)
    {
        ll x, y;
        cin >> x;
        if(x == -1)
            break;
        cin >> y;
        table[y][x] = 1;
    }

    for(auto row: table)
    {
        for(auto cell: row)
            if(cell)
                cout << "##";
            else
                cout << "  ";
        cout << endl;
    }
    return 0;
}