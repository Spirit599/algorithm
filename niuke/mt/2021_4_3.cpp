#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));

	int choose[n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cin >> choose[j];
		for(int j = 0; j < n; ++j)
		{
			// printf("%d\n", choose[]);
			if(!vis[choose[j]])
			{
				vis[choose[j]] = true;
				cout<<choose[j]<<" ";
				break;
			}
		}
	}
	return 0;
}