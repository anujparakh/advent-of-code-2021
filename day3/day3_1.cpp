#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h> /* pow */

#define ll long long

using namespace std;

void fillVec(vector<vector<bool> > &nums, string bin)
{
    ll i = 0;
    vector<bool> newNum;
    for (auto c : bin)
    {
        newNum.push_back(c == '1');
    }

    nums.push_back(newNum);
}

ll toInt(vector<bool> bin)
{
    ll power = bin.size() - 1;
    ll toReturn = 0;
    for (auto x : bin)
    {
        if (x)
            toReturn += pow(2, power);
        --power;
    }

    return toReturn;
}

int main()
{
    string binary;
    vector<vector<bool> > nums;
    ll count = 0;
    cout << "Enter: " << endl;
    while (true)
    {
        cin >> binary;
        if (binary == "end")
            break; // end
        fillVec(nums, binary);
        ++count;
    }

    ll i = 0;
    while (nums.size() > 1)
    {
        ll ones = 0;
        for (auto x : nums)
            if (x[i])
                ++ones;

        vector<vector<bool> > temp;
        if (ones < ceil(nums.size() / 2.0))
        {
            for (auto x : nums)
                if (x[i])
                    temp.push_back(x);
        }
        else
        {
            for (auto x : nums)
                if (!x[i])
                    temp.push_back(x);
        }
        nums = temp;
        ++i;
    }

    cout << toInt(nums[0]) << endl;

    return 0;
}