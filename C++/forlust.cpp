#include <iostream>

bool play(int n, int k, double p)
{
	bool play_or_not = false;
	if (n * p >= k)
		play_or_not = true;

	return play_or_not;
}

int main()
{
	// Vinst = n kronor
	// Kostar k kronor att spela
	// Sannolikhet = p kronor

	int n {0}, k {0};
	double p {0.0};
	std::cin >> n >> k >> p;

	if (play(n, k, p))
		std::cout << "Spela inte!\n";
	else
		std::cout << "Spela\n";
}