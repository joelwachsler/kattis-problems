#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // LOL FIBONACCI
    vector<unsigned int> cache {1, 1};
    unsigned int max, sum, count;
    cin >> max;
    max *= 1000;
    for (unsigned int i = 2; i <= 1000; i++)
        cache.push_back(cache[i-1] + cache[i-2]);

    count = 0;
    sum = 0;
    while (sum < max)
    {
        sum += cache[count];
        count++;
    }

    cout << count-1;
    return 0;
}
