#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

vector<string> parse(string& str)
{
	vector<string> ret;
	string cur;
	str.push_back(',');

	for(char c : str)
	{
		if(c == ',')
		{
			ret.push_back(cur);
			cur.clear();
		}
		else
		{
			cur.push_back(c);
		}
	}
	return ret;
}

typedef pair<int, int> pii;

pii parseStr(string& str)
{
	vector<int> nums;
	str.push_back('-');
	int cur = 0;
	for(char c : str)
	{
		if(c == '-')
		{
			nums.push_back(cur);
			cur = 0;
		}
		else
		{
			cur = 10 * cur + c - '0';
		}
	}

	if(nums.size() == 1)
		return make_pair(nums[0], nums[0]);
	else
		return make_pair(nums[0], nums[1]);

}

int main(int argc, char const *argv[])
{
	string firstLine;
	cin >> firstLine;
	vector<string> ret = parse(firstLine);

	set<pii> memo;

	for(string& str : ret)
	{
		// cout << str << endl;
		auto [f1, f2] = parseStr(str);
		// cout << f1 << " " << f2 << endl;
		memo.insert(make_pair(f2, f1));
	}

	int rm;
	cin >> rm;

	auto it = memo.lower_bound(make_pair(rm, -1));
	if(it != memo.end())
	{
		auto [end, start] = *it;
		// cout << f1 << " " << f2 << endl;
		memo.erase(it);
		int s1 = start;
		int e1 = rm - 1;
		int s2 = rm + 1;
		int e2 = end;
		if(s1 <= e1)
			memo.insert(make_pair(e1, s1));
		if(s2 <= e2)
			memo.insert(make_pair(e2, s2));
	}

	string ans;
	for(auto& [end, start] : memo)
	{
		if(start != end)
			ans.append(to_string(start) + "-" + to_string(end) + ",");
		else
			ans.append(to_string(start) + ",");
	}
	ans.pop_back();
	cout <<  ans << endl;

	return 0;
}