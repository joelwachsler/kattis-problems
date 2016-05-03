/*
 * Date:    2015-04-05
 * Author:  Joel Wachsler
 * File:    portaler.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rec(int f, int t, vector<int> &ways)
{
    int jumps = 0;
    vector<int> steps {};

    while (true)
    {
        jumps++;
        // Found a match!!!
        if (ways[f-1] == t)
            break;
        // In a loop, abort
        if (find(steps.begin(), steps.end(), ways[f-1])!=steps.end())
        {
            jumps = -1;
            break;
        }

        steps.push_back(f);
        f = ways[f-1];
    }
    cout << jumps << endl;
}

int main()
{
    int portals, temp, temp2;
    cin >> portals;

    vector<int> ways {};

    for (int i = 0; i < portals; i++) {
        cin >> temp;
        ways.push_back(temp);
    }

    int portal_jumps;
    cin >> portal_jumps;

    // From-to
    vector<vector<int>> f_t;

    for (int i = 0; i < portal_jumps; i++) {
        cin >> temp;
        cin >> temp2;

        f_t.push_back({temp, temp2});
    }

    for (int i = 0; i < portal_jumps; i++)
        rec(f_t[i][0], f_t[i][1], ways);
}
