/*
 * Date:    2015-03-16
 * Author:  Joel Wachsler
 * File:    vandrarhem.cpp
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    unsigned int users, bedtypes;
    float cost, temp_second, temp_first;
    cost = 0;
    // Read data
    cin >> users >> bedtypes;
    map<float, float> data;
    // Insert into map
    for (unsigned int i = 0; i < bedtypes; i++) {
        cin >> temp_first >> temp_second;
        // Check if key already exists
        if (data.find(temp_first) == data.end())
            data[temp_first] = temp_second;
        else
            data[temp_first] += temp_second;
    }

    auto iterator = data.begin();
    while (users > 0)
    {
        while (iterator->second < 1)
            iterator++;
        cost += iterator->first;
        iterator->second--;
        users--;
    }

    cout << cost;

    return 0;
}
