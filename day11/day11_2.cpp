#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll long long

using namespace std;

bool checkIndex(ll x, ll y)
{
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

void checkAndIncrease(vector<vector<ll> > &octopii, ll x, ll y)
{
    if(checkIndex(x, y))
        ++octopii[x][y];
}

ll countFlashes(vector<vector<ll> > &octopii, vector<vector<bool> > &flashed)
{
    ll flashes = 0;
    for(ll i = 0; i < 10; ++i)
    {
        for(ll j = 0; j < 10; ++j)
        {
            if(octopii[i][j] >= 10 && !flashed[i][j]) // flash
            {
                checkAndIncrease(octopii, i - 1, j);
                checkAndIncrease(octopii, i - 1, j - 1);
                checkAndIncrease(octopii, i - 1, j + 1);
                checkAndIncrease(octopii, i, j - 1);
                checkAndIncrease(octopii, i, j + 1);
                checkAndIncrease(octopii, i + 1, j);
                checkAndIncrease(octopii, i + 1, j - 1);
                checkAndIncrease(octopii, i + 1, j + 1);
                flashed[i][j] = true;
                ++flashes;
                flashes += countFlashes(octopii, flashed); // check again with increased
            }
        }
    }

    return flashes;
}

int main()
{
    vector<vector<ll> > octopii(10);
    for(ll i = 0; i < 10; ++i)
        for(ll j = 0; j < 10; ++j)
        {
            char x; cin >> x;
            octopii[i].push_back(x - '0');
        }

    ll flashes = 0;
    ll step = 1;
    while(true)
    {
        vector<vector <bool> > flashed (10);

        for(ll i = 0; i < 10; ++i)
            for(ll j = 0; j < 10; ++j)
            {
                ++octopii[i][j];
                flashed[i].push_back(false);
            }

        if(countFlashes(octopii, flashed) == 100)
            break;


        for(ll i = 0; i < 10; ++i)
            for(ll j = 0; j < 10; ++j)
                if(flashed[i][j])
                    octopii[i][j] = 0;

        // cout << "---------\nAFTER STEP " << step << endl;
        // for(auto row: octopii)
        // {
        //     for(auto oct: row)
        //         cout << oct << " ";
        //     cout << endl;
        // }

        ++step;
    }



    cout << "finished step: " << step << endl;;
    return 0;
}