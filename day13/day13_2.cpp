#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll long long

using namespace std;

void tokenize(const std::string &s, const char delim,
            std::vector<std::string> &out)
{
    std::string::size_type beg = 0;
    for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end)
    {
        out.push_back(s.substr(beg, end - beg));
        beg = end + 1;
    }

    out.push_back(s.substr(beg));
}

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

bool isBelow(point p, ll y)
{
    return p.y > y;
}

bool isRight(point p, ll x)
{
    return p.x > x;
}

ll getMirror(ll x, ll val)
{
    return val - (x - val);
}

int main()
{
    map<point, bool> marked;
    ll highestX = 0, highestY = 0;
    while(true)
    {
        string line;
        getline(cin, line);
        if(line == "")
            break;
        vector<string> out;
        tokenize(line, ',', out);
        marked[point(atoi(out[0].c_str()), atoi(out[1].c_str()))] = true;
    }
    // cout << "----" << endl;
    // for(auto p: marked)
    // {
    //     cout << p.first.x << ", " << p.first.y << endl;
    // }
    // just once for now

    while(true)
    {
        string waste; char tmp, dir; ll val;
        cin >> waste;
        if(waste == "end")
            break;
        cin >> waste;
        cin >> dir >> tmp >> val;
        if(dir == 'x')
        {
            map<point, bool> temp;
            for(auto p: marked)
            {
                if(!p.second)
                    continue;

                if(isRight(p.first, val))
                {
                    temp[p.first] = false;
                    ll calc = getMirror(p.first.x, val);
                    temp[point(calc, p.first.y)] = true;
                }
                else
                    temp[p.first] = true;
            }
            marked = temp;
        }
        else
        {
            map<point, bool> temp;
            for(auto p: marked)
            {
                if(!p.second)
                    continue;

                if(isBelow(p.first, val))
                {
                    temp[p.first] = false;
                    ll calc = getMirror(p.first.y, val);

                    temp[point(p.first.x, calc)] = true;
                }
                else
                    temp[p.first] = true;
            }
            marked = temp;
        }
    }

    ll count = 0;
    for(auto p: marked)
        if(p.second)
            cout << p.first.x << " " << p.first.y << endl;


    cout << count << endl;
    return 0;
}