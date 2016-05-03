#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

//def loop(wanted_pos, playfield, current_pos, spots_been_on):

bool loop(vector<int> &wanted_pos, vector<vector<bool>> &playfield, vector<int> current_pos, list<vector<int>> &spots_been_on, int &x, int &y)
{
    // Got a match!
    if (wanted_pos == current_pos)
        return true;
    
    if (current_pos[0] < 0 || current_pos[1] < 0 || current_pos[0] > x || current_pos[1] > y)
        return false;

    if (playfield[current_pos[1]][current_pos[0]] == false || find(spots_been_on.begin(), spots_been_on.end(), current_pos)!=spots_been_on.end())
        return false;

    // Add this position to positions we've been on
    spots_been_on.push_back(current_pos);

    // Down right
    if (loop(wanted_pos, playfield, {current_pos[0] + 2, current_pos[1] + 1}, spots_been_on, x, y))
        return true;
    if (loop(wanted_pos, playfield, {current_pos[0] + 1, current_pos[1] + 2}, spots_been_on, x, y))
        return true;
    // Down left
    if (loop(wanted_pos, playfield, {current_pos[0] - 2, current_pos[1] + 1}, spots_been_on, x, y))
        return true;
    if (loop(wanted_pos, playfield, {current_pos[0] - 1, current_pos[1] + 2}, spots_been_on, x, y))
        return true;
    // Up right
    if (loop(wanted_pos, playfield, {current_pos[0] + 2, current_pos[1] - 1}, spots_been_on, x, y))
        return true;
    if (loop(wanted_pos, playfield, {current_pos[0] + 1, current_pos[1] - 2}, spots_been_on, x, y))
        return true;
    // Up left
    if (loop(wanted_pos, playfield, {current_pos[0] - 2, current_pos[1] - 1}, spots_been_on, x, y))
        return true;
    if (loop(wanted_pos, playfield, {current_pos[0] - 1, current_pos[1] - 2}, spots_been_on, x, y))
        return true;

    return false;
}

int main()
{
    int x, y;
    cin >> y >> x;
    vector<int> current_pos = {-1}, wanted_pos = {-1};
    vector<vector<bool>> playfield {};
    list<vector<int>> spots_been_on = {};

    for (int i = 0; i < y; i++)
    {
        vector<bool> temp {};
        for (int z = 0; z < x; z++)
        {
            char temp_char;
            cin >> temp_char;
            if (temp_char == '.')
                temp.push_back(true);
            else if(temp_char == 'H')
            {
                if (current_pos[0] == -1)
                    current_pos = {z, i};
                else
                    wanted_pos = {z, i};
                temp.push_back(true);
            }
            else
            {
                temp.push_back(false);
            }
        }
        playfield.push_back(temp);
    }

    x--;
    y--;

    if (loop(wanted_pos, playfield, current_pos, spots_been_on, x, y))
        cout << "JA" << endl;
    else
        cout << "NEJ" << endl;

    return 0;
}
