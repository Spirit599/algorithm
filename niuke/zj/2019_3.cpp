#include<bits/stdc++.h>
using namespace std;

//麻将
//深度优先

typedef long long ll;
const double eps = 1e-8;

bool success = false;

void dfs(map<int, int>& um, int card_num, int jiang)
{
	// cout<<"-------------------"<<endl;
	// for(auto kav : um)
	// 	cout<<kav.first<<" "<<kav.second<<endl;

	if(card_num == 0)
	{
		success = true;
		return;
	}

	int key;
	for(auto kav : um)
	{
		if(kav.second != 0)
		{
			key = kav.first;
			break;
		}
	}
	//cout<<"key:"<<key<<endl;
	//杠
	if(um[key] >= 3)
	{
		um[key] = um[key] - 3;

		dfs(um, card_num - 3, jiang);

		um[key] += 3;
	}
	//对子只能有一个
	if(um[key] >= 2 && jiang == 0)
	{
		um[key] = um[key] - 2;
		jiang = 1;
		dfs(um, card_num - 2, jiang);
		jiang = 0;
		um[key] += 2;
	}
	//顺子
	if(um[key] >= 1)
	{	
		if(um.count(key + 1) && um.count(key + 2) && um[key + 1] >= 1 && um[key + 2] >= 1)
		{
			--um[key];
			--um[key + 1];
			--um[key + 2];
			dfs(um, card_num - 3, jiang);
			++um[key];
			++um[key + 1];
			++um[key + 2];
		}
	}

}


int main(int argc, char const *argv[])
{
	int n = 13;
	map<int, int> um;

	for (int i = 1; i <= 9; ++i)
		um[i] = 0;

	while(n--)
	{
		int i;
		cin >> i;
		++um[i];
	}



	vector<int> candidate;

	for(int i = 1; i <= 9; ++i)
		if(um[i] < 4)
			candidate.push_back(i);


	vector<int> ans;
	for(auto i : candidate)
	{
		//cout<<i<<endl;
		success = false;
		++um[i];
		dfs(um, 14, 0);
		--um[i];
		if(success)
			ans.push_back(i);
	}

	for(auto i : ans)
		cout<<i<<" ";
	if(ans.size() == 0)
		cout<<0;

	return 0;
}

