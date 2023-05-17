#include <iostream>
#include <stack> 
using namespace std;

int main(int argc, char const *argv[])
{
	
	string input;
	cin >> input;
	int n = input.size();

	stack<string> strStk;
	strStk.push("");

	stack<int> numStk;

	for(int i = 0; i < n; ++i)
	{
		if(isdigit(input[i]))
		{
			int num = 0;
			while(isdigit(input[i]) && i < n)
			{
				num = 10 * num + input[i] - '0';
				++i;
			}
			numStk.push(num);
			--i;
		}
		else if(isalpha(input[i]))
		{
			string str;
			while(isalpha(input[i]) && i < n)
			{
				str.push_back(input[i]);
				++i;
			}
			strStk.top() += str;
			--i;
		}
		else if(input[i] == '[')
		{
			strStk.push("");
		}
		else if(input[i] == ']')
		{
			string kbase;
			int k = numStk.top();
			string base = strStk.top();
			numStk.pop();
			strStk.pop();
			for(int i = 0; i < k; ++i)
				kbase.append(base);
			strStk.top() += kbase;
		}
	}

	cout << strStk.top() << endl;

	return 0;
}