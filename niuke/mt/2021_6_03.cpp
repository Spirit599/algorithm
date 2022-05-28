#include<bits/stdc++.h>
using namespace std;

//误差
const double eps = 1e-8;
//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	int matrix[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	bool split = true;
	int split_index = n / 2;
	while(split)
	{
		for (int i = 0; i < split_index; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(matrix[i][j] != matrix[i + split_index][j])
				{
					split = false;
					break;
				}
			}
			if(!split)
				break;
		}
		//cout<<split<<" "<<split_index<<endl;
		if(split && split_index % 2 == 0)
		{
			split_index = split_index / 2;
		}
		else
		{
			break;
		}
	}
	//cout<<split_index<<endl;
	for (int i = 0; i < split_index; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

