//回文

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	

	string str;
	cin >> str;
	string ans = str;

	int str_len = str.size();


	int mid = str_len / 2;

	int left_index = 0;
	
	for(int i = mid; i < str_len; ++i)
	{
		int left = i;
		int right = i;

		while(left - 1 >= 0 && str[left - 1] == str[i])
			--left;
		while(right + 1 < str_len && str[right + 1] == str[i])
			++right;
		while(left - 1 >= 0 && right + 1 < str_len &&
			str[left - 1] == str[right + 1])
		{
			--left;
			++right;
		}
		if(right == str_len - 1)
		{
			left_index = left;
			break;
		}
	}

	for(int i = left_index - 1; i >= 0; --i)
		ans.push_back(str[i]);

	cout<<ans<<endl;
	return 0;
}