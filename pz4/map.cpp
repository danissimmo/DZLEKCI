#include <iostream>
#include <string>
#include <map>
using namespace std;


void main()
{
	map<string, int> dict;
	string c;

	while (cin >> c)
	{
		if (c == "/exit") break;
		dict[c]++;
	}

	cout << endl;
	for (pair<string, int> m : dict) cout << m.second << ' ' << m.first << endl;
}

