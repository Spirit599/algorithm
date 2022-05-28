//不连续 子串 第k小
//set

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
	int index;
	char ch;
};

bool cmp(const node& n1, const node& n2)
{
	return n1.index < n2.index;
}

void dfs(string& kk, int index, string str, set<string>& candidate_str)
{
	if(index == (int)kk.size())
	{
		candidate_str.insert(str);
		return ;
	}

	dfs(kk, index + 1, str + kk[index], candidate_str);
	dfs(kk, index + 1, str, candidate_str);
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	int t;
	cin >> t;

	if(str == "")
	{
		cout<<""<<endl;
		return -1;
	}

	int str_len = str.size();
	vector<node> nodes;
	for (int j = 0; j < 7; ++j)
	{
		if(str_len <= (int)nodes.size())
			break;

		char minc = 'z' + 1;
		int minc_index = 0;
		for (int i = 0; i < str_len; ++i)
		{
			if(str[i] < minc)
			{
				minc = str[i];
				minc_index = i;
			}
		}
		str[minc_index] = 'z' + 1;
		node tmp;
		tmp.ch = minc;
		tmp.index = minc_index;
		nodes.push_back(tmp);
	}
	sort(nodes.begin(), nodes.end(), cmp);

	string kk;
	for(auto n : nodes)
		kk += n.ch;

	cout<<kk<<endl;

	set<string> candidate_str;
	dfs(kk, 0, "", candidate_str);

	//cout<<candidate_str.size()<<endl;

	// for(auto item : candidate_str)
	// 	cout<<item<<endl;

	auto it = candidate_str.begin();
	++it;
	for (int i = 2; i <= t; ++i)
	{
		++it;
	}
	cout<<(*it)<<endl;




	return 0;
}

