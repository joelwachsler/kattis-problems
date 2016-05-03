/*
 * Date:    2015-03-18
 * Author:  Joel Wachsler
 * File:    votes.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int candidates, input, votes_to_buy, our;
    vector<int> votes;
    cin >> candidates >> our;
    
    for (int i = 0; i < candidates - 1; i++) {
        cin >> input;
        votes.push_back(input);
    }

    votes_to_buy = 0;
    sort(votes.begin(), votes.end());
    if (votes.size() != 0)
        while(our <= votes.back())
        {
            votes.back()--;
            our++;
            sort(votes.begin(), votes.end());
            votes_to_buy++;
        }

    cout << votes_to_buy;

    return 0;
}
