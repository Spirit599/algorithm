#include<bits/stdc++.h>
using namespace std;


//hash邻接表
//BFS 最大连通图
typedef long long ll;
const int MAX_USERSIZE = 100005;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		vector<int> user_relationship[MAX_USERSIZE];
		cin >> n;
		while(n--)
		{
			int user1, user2;
			cin >> user1 >> user2;
			user_relationship[user1].push_back(user2);
			user_relationship[user2].push_back(user1);
		}

		bool visit[MAX_USERSIZE];
		memset(visit,0,sizeof(visit));
		int ans = 0;

		for (int user = 1; user <= MAX_USERSIZE; ++user)
		{
			if(!visit[user])
			{
				int cur_sum = 1;
				queue<int> que;
				que.push(user);
				visit[user] = true;
				while(!que.empty())
				{
					int cur_user = que.front();
					for (auto know_user : user_relationship[cur_user])
					{
						if(!visit[know_user])
						{
							++cur_sum;
							visit[know_user] = true;
							que.push(know_user);
						}
					}
					que.pop();
				}
				ans = max(ans, cur_sum);
			}
		}

		cout<<ans<<endl;

	}
	return 0;
}

