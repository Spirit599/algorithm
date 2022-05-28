#include<bits/stdc++.h>
using namespace std;
#define MAX_SCORE (1001)

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		string desk;
		cin >> desk;

		int m;
		cin >> m;
		string people;
		cin >> people;
		//cout<<people;
		int i = 0;
		while(i != m)
		{
			char cur_p = people[i];
			if(cur_p == 'M')
			{
				int find = 0;
				for (int j = 0; j < n; ++j)
				{
					if(desk[j] == '1')
					{
						desk[j] = '2';
						find = j + 1;
						break;
					}
				}
				if(find)
				{
					cout<<find<<endl;
					++i;
					continue;
				}
				for (int j = 0; j < n; ++j)
				{
					if(desk[j] == '0')
					{
						desk[j] = '1';
						find = j + 1;
						break;
					}
				}
				if(find)
				{
					cout<<find<<endl;
					++i;
					continue;
				}
			}
			else
			{
				int find = 0;
				for (int j = 0; j < n; ++j)
				{
					if(desk[j] == '0')
					{
						desk[j] = '1';
						find = j + 1;
						break;
					}
				}
				if(find)
				{
					cout<<find<<endl;
					++i;
					continue;
				}
				for (int j = 0; j < n; ++j)
				{
					if(desk[j] == '1')
					{
						desk[j] = '2';
						find = j + 1;
						break;
					}
				}
				if(find)
				{
					cout<<find<<endl;
					++i;
					continue;
				}
			}
		}
	}

	return 0;
}