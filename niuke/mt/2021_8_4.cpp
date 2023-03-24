#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int base = 105;

int main(int argc, char const *argv[])
{
	int m,n;
	cin >> m >> n;
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	--sx;--sy;--tx;--ty;
	// int a[m][n];
	vector<vector<int>> a(m, vector<int>(n));
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(m, vector<int>(n));
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> b[i][j];
		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, sx * base + sy);
	int dis[base][base];
	memset(dis, 0x3f, sizeof(dis));
	dis[sx][sy] = 0;

	auto getTime = [&](int x, int y, int time) -> pii {

		int yu = time % (a[x][y] + b[x][y]);
		int cnt = time / (a[x][y] + b[x][y]);
		if(yu < a[x][y])
			return make_pair(time, cnt * (a[x][y] + b[x][y]) + a[x][y]);
		else
			return make_pair((cnt + 1) * (a[x][y] + b[x][y]), time);
	};

	auto check = [&](int x, int y) -> bool {

		if(x < 0 || x >= m || y < 0 || y >= n)
			return false;
		return true;
	};

	while(!pq.empty())
	{
		auto [time, idx] = pq.top();
		pq.pop();
		int y = idx % base;
		int x = idx / base;
		// printf("%d %d %d\n",x,y,time );
		if(dis[x][y] < time)
			continue;
		dis[x][y] = time;

		auto [upDown, leftRight] = getTime(x, y, time);

		if(check(x + 1, y) && upDown + 1 < dis[x + 1][y])
		{
			dis[x + 1][y] = upDown + 1;
			pq.emplace(upDown + 1, (x + 1) * base + y);
		}
		if(check(x - 1, y) && upDown + 1 < dis[x - 1][y])
		{
			dis[x - 1][y] = upDown + 1;
			pq.emplace(upDown + 1, (x - 1) * base + y);
		}
		if(check(x, y + 1) && leftRight + 1 < dis[x][y + 1])
		{
			dis[x][y + 1] = leftRight + 1;
			pq.emplace(leftRight + 1, x  * base + y + 1);
		}
		if(check(x, y - 1) && leftRight + 1 < dis[x][y - 1])
		{
			dis[x][y - 1] = leftRight + 1;
			pq.emplace(leftRight + 1, x  * base + y - 1);
		}
	}

	cout<<dis[tx][ty]<<endl;


	return 0;
}