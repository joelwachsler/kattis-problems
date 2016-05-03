/*
 * Date:    2015-03-16
 * Author:  Joel Wachsler
 * File:    sjusovare.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int personer, temp1, temp2, temp3, temp4;
    cin >> personer;
    vector<vector<int>> data;

    for (int i = 0; i < personer; i++) {
        cin >> temp1 >> temp2 >> temp3 >> temp4;
        data.push_back({temp1, temp2, temp3, temp4});
    }

    int position = 1;
    for (auto &x : data)
    {
        x[1] += x[2] * x[3];
        x[0] += x[1] / 60;
        x[1] = x[1] % 60;
        if (x[0] > 6)
            cout << position << " ";
        position++;
    }

    return 0;
}
