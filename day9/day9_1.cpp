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

bool checkIndex(ll  x, ll y, ll width, ll height)
{
    return !(x >= width || x < 0 || y < 0 || y >= height);
}

bool isLowPoint(const vector<vector<ll> > &heightmap, ll x, ll y)
{
    ll width = heightmap[0].size();
    ll height = heightmap.size();
    if(!checkIndex(x, y, width, height))
        return false;

    // cout << "checking " << x << " and " << y << endl;
    // UP
    if(checkIndex(x, y - 1, width, height))
        if(heightmap[y - 1][x] <= heightmap[y][x])
            return false;

    // DOWN
    if(checkIndex(x, y + 1, width, height))
        if(heightmap[y + 1][x] <= heightmap[y][x])
            return false;


    // RIGHT
    if(checkIndex(x + 1, y, width, height))
        if(heightmap[y][x + 1] <= heightmap[y][x])
            return false;

    // LEFT
    if(checkIndex(x - 1, y, width, height))
        if(heightmap[y][x - 1] <= heightmap[y][x])
            return false;

    return true;

}

ll countBasins(const vector<vector<ll> > &heightmap, ll x, ll y, vector<vector<bool> > &marked)
{
    if(marked[y][x]) // count only once
        return 0;
    marked[y][x] = true;
    ll total = 1;
    ll width = heightmap[0].size();
    ll height = heightmap.size();
    if(!checkIndex(x, y, width, height))
        return false;

    // UP
    if(checkIndex(x, y - 1, width, height))
        if(heightmap[y - 1][x] != 9)
            if(heightmap[y - 1][x] > heightmap[y][x])
                total += countBasins(heightmap, x, y - 1, marked);

    // DOWN
    if(checkIndex(x, y + 1, width, height))
        if(heightmap[y + 1][x] != 9)
            if(heightmap[y + 1][x] > heightmap[y][x])
                total += countBasins(heightmap, x, y + 1, marked);


    // RIGHT
    if(checkIndex(x + 1, y, width, height))
        if(heightmap[y][x + 1] != 9)
            if(heightmap[y][x + 1] > heightmap[y][x])
                total += countBasins(heightmap, x + 1, y, marked);

    // LEFT
    if(checkIndex(x - 1, y, width, height))
        if(heightmap[y][x - 1] != 9)
            if(heightmap[y][x - 1] > heightmap[y][x])
                total += countBasins(heightmap, x - 1, y, marked);

    return total;
}

int main()
{
    vector<vector<ll> > heightmap;
    ifstream infile("input.txt");

    while(!infile.eof())
    {
        string line; infile >> line;
        vector<ll> lineMap;
        for(auto c: line)
        {
            lineMap.push_back((ll)(c - '0'));
        }
        heightmap.push_back(lineMap);
    }

    ll width = heightmap[0].size();
    ll height = heightmap.size();
    vector<ll> basinCounts;
    for(ll y = 0; y < height; ++y)
    {
        for(ll x = 0; x < width; ++x)
        {
            if(isLowPoint(heightmap, x, y))
            {
                vector<vector<bool> > marked;
                for(ll i = 0; i < height; ++i)
                    marked.push_back(vector<bool> (width));

                basinCounts.push_back(countBasins(heightmap, x, y, marked));
            }
        }
    }

    sort(basinCounts.begin(), basinCounts.end());
    ll end = basinCounts.size() - 1;
    cout << basinCounts[end] * basinCounts[end - 1] * basinCounts[end - 2] << endl;


    return 0;
}