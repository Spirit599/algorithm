#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;




int main(int argc, char const *argv[])
{
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	char cmap[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >>cmap[i][j];
		}
	}

	string dire;
	cin >> dire;

	int i = 0;
	int j = 0;

	for (int k = 0; k < n; ++k)
	{
		for (int l = 0; l < m; ++l)
		{
			if(cmap[k][l] == 'S')
			{
				i = k;
				j = l;
				break;
			}
		}
	}


	long long ans = 0;
	for(auto ch : dire)
	{
		
		//cout<<i<<" "<<j<<endl;
		char cur = cmap[i][j];
		if(cur == 'X')
		{
			ans = ans - q;
			cmap[i][j] = '+';

		}
		else if(cur == 'O')
		{
			ans = ans + p;
			cmap[i][j] = '+';
		}
		else
		{
			;
		}

		if(ch == 'S')
		{
			if(i + 1 < n && cmap[i + 1][j] != '#')
			{
				++i;
			}
		}
		else if(ch == 'W')
		{
			if(i - 1 >= 0 && cmap[i - 1][j] != '#')
			{
				--i;
			}
		}
		else if(ch == 'D')
		{
			if(j + 1 < m && cmap[i][j + 1] != '#')
			{
				++j;
			}
		}
		else if(ch == 'A')
		{
			if(j - 1 >= 0 && cmap[i][j - 1] != '#')
			{
				--j;
			}
		}
	}

	char cur = cmap[i][j];
	if(cur == 'X')
	{
		ans = ans - q;
		cmap[i][j] = '+';
	}
	else if(cur == 'O')
	{
		ans = ans + p;
		cmap[i][j] = '+';
	}
	else
	{
		;
	}

	cout<<ans<<endl;
	return 0;
}

