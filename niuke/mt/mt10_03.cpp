#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		vector<set<int>> vec(3);

		int n;
		cin >> n;

		string desk;
		cin >> desk;

		int m;
		cin >> m;

		string people;
		cin >> people;

		for (int i = 0; i < n; ++i)
		{
			vec[desk[i] - '0'].insert(i);
		}

		int i = 0;
		while(i != m)
		{

			char cur_p = people[i];
			if(cur_p == 'M')
			{
				if(vec[1].size() != 0)
				{
					auto it = vec[1].begin();
					vec[2].insert(*it);
					cout<<(*it) + 1<<endl;
					vec[1].erase(*it);
					++i;
					continue;
				}
				if(vec[0].size() != 0)
				{
					auto it = vec[0].begin();
					vec[1].insert(*it);
					cout<<(*it) + 1<<endl;
					vec[0].erase(*it);
					++i;
					continue;
				}
			}
			else
			{

				if(vec[0].size() != 0)
				{
					auto it = vec[0].begin();
					vec[1].insert(*it);
					cout<<(*it) + 1<<endl;
					vec[0].erase(*it);
					++i;
					continue;
				}
				if(vec[1].size() != 0)
				{
					auto it = vec[1].begin();
					vec[2].insert(*it);
					cout<<(*it) + 1<<endl;
					vec[1].erase(*it);
					++i;
					continue;
				}
			}
		}

	}

	return 0;
}