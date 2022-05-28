#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;

typedef unsigned int uint;

int ans = 0;

int main(int argc, char const *argv[])
{
	
	int start, end;
	cin >> start >> end;

	for (int i = start; i <= end; ++i)
	{
		int copy_i = i;
		bool visit[10];
		memset(visit, 0, sizeof(visit));
		vector<int> candidate;

		int f = copy_i % 10;
		copy_i = copy_i / 10;
		candidate.push_back(f);
		visit[f] = true;

		int e = copy_i % 10;
		copy_i = copy_i / 10;
		if(visit[e])
			continue;
		candidate.push_back(e);
		visit[e] = true;

		int d = copy_i % 10;
		copy_i = copy_i / 10;
		if(visit[d])
			continue;
		candidate.push_back(d);
		visit[d] = true;

		int c = copy_i % 10;
		copy_i = copy_i / 10;
		if(visit[c])
			continue;
		candidate.push_back(c);
		visit[c] = true;

		int b = copy_i % 10;
		copy_i = copy_i / 10;
		if(visit[b])
			continue;
		candidate.push_back(b);
		visit[b] = true;

		int a = copy_i % 10;
		if(visit[a])
			continue;
		candidate.push_back(a);
		visit[a] = true;


		if(a * 10 + b + c * 10 + d == e * 10 + f)
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}

