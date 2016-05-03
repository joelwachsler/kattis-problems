#include <iostream>
#include <vector>

using namespace std;

int difference(int a, int b)	// Från negativt till positivt
{
	int diff {};
	diff = {a-b};
	diff -=5;
	diff *= 2;
	if (diff < 0)
		diff *= -1;
	return diff;
}

int calc(const vector<int>& data)
{
	int total {};
	for(auto i = data.begin(); i+1 != data.end(); ++i)
		total += difference(*i, *(i+1)) + 60;

	return total;
}


int main()
{
	int n {};	// Antalet 100 meter
	cin >> n;
	vector<int> numbs {};	// Sträckan över havet
	int temp {};
	for(int x = 0; x < n + 1; x++)
		cin >> temp,
		numbs.push_back(temp);

	cout << calc(numbs) << "\n";
}