#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll long long

using namespace std;

struct cell
{
    ll value;
    bool marked;
    cell(ll x, bool b)
    {
        value = x;
        marked = b;
    }
};

bool checkWinner(vector<vector<cell> > grid)
{
    // rows
    for(auto row: grid)
    {
        bool flag = true;
        for(auto x: row)
        {
            if(!x.marked)
            {
                flag = false;
                break;
            }
        }

        if(flag)
            return true;
    }

    // cols
    for(ll i = 0; i < 5; ++i)
    {
        bool flag = true;
        for(ll j = 0; j < 5; ++j)
        {
            if(!grid[j][i].marked)
            {
                flag = false;
                break;
            }
        }

        if(flag)
            return true;
    }

    // diag 1
    // if(grid[0][0].marked && grid[1][1].marked && grid[2][2].marked && grid[3][3].marked && grid[4][4].marked)
    //     return true;

    // // diag 2
    // if(grid[4][0].marked && grid[3][1].marked && grid[2][2].marked && grid[1][3].marked && grid[0][4].marked)
    //     return true;

    return false;
}

ll calcSum(vector<vector<cell> > grid)
{
    ll total = 0;
    for(auto row: grid)
        for(auto c: row)
            if(!c.marked)
                total += c.value;
    return total;
}

void markNum(vector<vector<cell> > &grid, ll x)
{
    for(ll i = 0; i < 5; ++i)
        for(ll j = 0; j < 5; ++j)
            if(grid[i][j].value == x)
            {
                grid[i][j].marked = true;
                return;
            }
}


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

void inputGrids(vector<vector<vector<cell> > > &grids)
{
    while(true)
    {
        vector< vector<cell> > grid(5);

        bool getOut = false;
        for(ll i = 0; i < 5; ++i)
            for(ll j = 0; j < 5; ++j)
            {
                ll x; cin >> x;
                if(x == -1)
                    return;

                grid[i].push_back(cell(x, false));
            }

        grids.push_back(grid);

    }
}

int main()
{
    string numsString;
    getline(cin, numsString);
    vector<ll> nums;
    divideString(numsString, nums);

    ll minTurn = nums.size() + 1;
    ll score = 0;
    vector<vector<vector<cell> > > grids;
    inputGrids(grids);

    set<ll> alreadyWon;
    ll boardsLeft = grids.size();
    for(auto x: nums)
    {
        for(ll i = 0; i < grids.size(); ++i)
        {
            if(alreadyWon.count(i))
                continue;

            markNum(grids[i], x);
            if(checkWinner(grids[i]))
            {
                if(boardsLeft == 1)
                {
                    cout << calcSum(grids[i]) * x << endl;
                    return 0;
                }

                alreadyWon.insert(i);

                --boardsLeft;
            }
        }
    }

    cout << "here\n" << endl;

    return 0;
}
