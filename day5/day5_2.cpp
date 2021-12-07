#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#define ll long long

using namespace std;

struct point
{
    ll x, y;
    point(ll a, ll b)
    {
        x = a; y = b;
    }

    bool operator==(const point &o) const {
        return x == o.x && y == o.y;
	}

	bool operator<(const point &o)  const {
        return x < o.x || (x == o.x && y < o.y);
	}
};



int main()
{
    char c; string s; // for waste
    map<point, ll> points;
    while(true)
    {
        ll x1, y1, x2, y2;
        cin >> x1;
        if(x1 == -1)
            break;
        cin >> c >> y1 >> s >> x2 >> c >> y2;
        // cout << "here\n";
        // horizontal line
        if(y1 == y2)
        {
            ll first = x1 < x2 ? x1 : x2;
            ll second = x1 < x2 ? x2 : x1;
            for(ll i = first; i <= second; ++i)
            {
                ++points[point(i, y1)];
                // cout << "Adding: " << i << ", " << y1 << "with " << points[point(i, y1)] << endl;
            }
        }

        // vertical line
        else if(x1 == x2)
        {
            ll first = y1 < y2 ? y1 : y2;
            ll second = y1 < y2 ? y2 : y1;
            for(ll i = first; i <= second; ++i)
            {
                ++points[point(x1, i)];
                // cout << "Adding: " << x1 << ", " << i << "with " << points[point(x1, i)] << endl;

            }
        }

        // diagonal
        else
        {
            ll deltaX = (x2 - x1) / abs(x2 - x1);
            ll deltaY = (y2 - y1) / abs(y2 - y1);
            ll startX = x1, startY = y1;
            ll total = abs(x2 - x1) + 1;
            for(ll i = 0; i < total; ++i)
            {
                ++points[point(startX, startY)];
                startX += deltaX; startY += deltaY;
            }
        }

    }

    ll counter = 0;
    for(auto const &x: points)
    {
        if(x.second > 1)
            ++counter;
    }

    cout << counter << endl;


    return 0;
}