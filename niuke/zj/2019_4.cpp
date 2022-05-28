#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;

	int k;
	pair<int, int> xy;

	while(t--)
	{
		cin >> n;

		int ans = 0;
		map<pair<int, int>, int> mappp;
		map<pair<int, int>, int> prior_mappp;
		while(n--)
		{
			cin >> k;
			for (int i = 0; i < k; ++i)
			{
				cin >> xy.first >> xy.second;

				if(prior_mappp.count(xy))
					mappp[xy] = prior_mappp[xy] + 1;
				else
					mappp[xy] = 1;

				if(mappp[xy] > ans)
					ans = mappp[xy];

			}
			prior_mappp.clear();
			prior_mappp.swap(mappp);

		}
		cout<<ans<<endl;
	}
	return 0;
}

