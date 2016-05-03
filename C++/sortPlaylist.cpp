#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int temp {}, jumps = 0, tal = 0;
	vector<int> my_vec {};

	cin >> tal;

	int temp_insert {};
	for (int i = 0; i < tal; ++i)
		cin >> temp_insert,
		my_vec.push_back(temp_insert);

	for(auto& x : my_vec)
		for (auto i = my_vec.begin(); i+1 != my_vec.end(); ++i)
			if (*i > *(i+1))
				temp = *i,
				*i = *(i+1),
				*(i+1) = temp,
				jumps++;

	cout << jumps;

}