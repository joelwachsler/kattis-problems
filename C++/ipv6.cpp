/*
 * Date:    2015-03-16
 * Author:  Joel Wachsler
 * File:    ipv6.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> add_leader(vector<char> addr)
{
    for (int i = addr.size(); i < 4; i++)
        addr.insert(addr.begin(), '0');

    return addr;
}

vector<vector<char>> prepare_input(string input)
{
    vector<char> temp;
    vector<vector<char>> final_holder;
    // Check if there's a double one
    for (auto it = input.begin(); it != input.end();it++)
    {
        if(*it == ':')
        {
            // Add zeros before
            final_holder.push_back(add_leader(temp));
            temp.clear();
            if (*(it + 1) == ':')
            {
                final_holder.push_back({':', ':'});
                it++;
            }
        }
        else
            temp.push_back(*it);
        if (it == input.end() - 1)
            final_holder.push_back(add_leader(temp));
    }

    return final_holder;
}

int main()
{

    string input;
    cin >> input;

    vector<vector<char>> ipv_addr = prepare_input(input);
    vector<vector<char>> final_holder;
    // Check for doubles

    vector<char> checker {':', ':'};

    int counter = 0;
    for(auto it = ipv_addr.begin(); it != ipv_addr.end(); it++)
    {
        if (*it == checker)
        {
            // Got a match!

            // Remove the holder
            ipv_addr.erase(it);
            // Count steps untill the end
            for(auto steps_left_it = it;steps_left_it != ipv_addr.end(); steps_left_it++)
                counter++;

            vector<vector<char>> holder(ipv_addr.begin(), it);
            for(int i = counter; i < 8; i++)
                holder.push_back({'0', '0', '0', '0'});

            while(it != ipv_addr.end())
            {
                holder.push_back(*it);
                it++;
            }

            ipv_addr = holder;

            break;
        }
        counter++;
    }

    for(auto it = ipv_addr.begin(); it != ipv_addr.end(); it++)
    {
        for (auto &y : *it)
            cout << y;
        if (it != ipv_addr.end() - 1)
            cout << ':';
    }

    return 0;
}
