#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));

	int n1, n2;
	cin >> n1 >> n2;

	map<int, int> num;
	vector<int> v1(n1), v2(n2);

	int sum1 = 0, sum2 = 0;

	cout << "Perviy vector: ";
	for (int& a : v1)
	{
		a = rand() % 201 - 100;
		sum1 += a;

		cout << a << ' ';
	}

	cout << "\nVtoroi vector: ";
	for (int& a : v2)
	{
		a = rand() % 201 - 100;
		sum2 += a;

		if (find(v1.begin(), v1.end(), a) != v1.end()) num[a]++;
		cout << a << ' ';
	}

	cout << "\n\nSrednee pervogo: " << (float)sum1 / n1;
	cout << "\nSrednee vtorogo: " << (float)sum2 / n2;

	cout << "\n\nPeresekayshie elementi: ";
	for (pair<int, int> p : num)
		cout << p.first << ' ';
}
