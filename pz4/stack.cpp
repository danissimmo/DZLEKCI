#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void dth(int fl, vector<vector<int>>& mat)
{
	vector<bool> used(mat.size(), false);
	stack<int> q;

	while (fl != -1)
	{
		if (used[fl] == false)
		{
			used[fl] = true;

			for (int i = 0; i < mat.size(); i++)
				if (mat[fl][i] == 1 && used[i] == false) q.push(i);
		}

		if (q.size() > 0)
		{
			fl = q.top();
			q.pop();
		}
		else fl = -1;
	}

	//print row of attainability
	for (bool a : used) cout << a << ' ';
	cout << endl;
}
		
void main()
{
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, 0));

	int x;
	for (int i = 0; i < N; i++)
	{
		do
		{
			cin >> x;
			if (x != 0) matrix[i][x - 1] = 1;

		} while (cin.peek() != '\n');
	}

	for (int i = 0; i < N; i++) dth(i, matrix);
}
