/*
 * Date:    2015-03-16
 * Author:  Joel Wachsler
 * File:    chocolate.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int boxes, before, observations, temp_read;
    before = 0;
    boxes = 0;
    vector<unsigned int> observe;

    cin >> observations;
    for (unsigned int i = 0; i < observations; i++)
    {
        cin >> temp_read;
        observe.push_back(temp_read);
    }

    auto it = observe.begin();
    before = *it;
    it++;
    while (it != observe.end())
    {
        if (*it > before)
            boxes++;
        before = *it;
        it++;
    }

    cout << boxes;

    return 0;
}
