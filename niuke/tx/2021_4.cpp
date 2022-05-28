#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int  MAX_SIZE1  = 100005;

int que[MAX_SIZE1];
int start = 0;
int end1 = 0;

int que_size()
{
	//cout<<(end1 - start + MAX_SIZE1) % MAX_SIZE1<<endl;
	return (end1 - start + MAX_SIZE1) % MAX_SIZE1;
}

void que_clear()
{
	end1 = start;
}

void que_push(int x)
{
	if(que_size() != MAX_SIZE1)
	{
		que[end1++] = x;
	}
}

int que_pop()
{
	if(que_size() != 0)
	{
		++start;
		return 0;
	}
	else
	{
		return -1;
	}
}

int que_top()
{
	if(que_size() != 0)
	{
		return que[start];
	}
	else
	{
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	
	int t;
	cin >> t;
	while(t--)
	{
		start = 0;
		end1 = 0;
		int n;
		cin >> n;
		while(n--)
		{
			string str;
			cin >> str;
			if(str == "PUSH")
			{
				int x;
				cin >> x;
				que_push(x);
			}
			else if(str == "POP")
			{
				if(-1 == que_pop())
					cout<<-1<<endl;
			}
			else if(str == "TOP")
			{
				cout<<que_top()<<endl;
			}
			else if(str == "SIZE")
			{
				cout<<que_size()<<endl;
			}
			else if(str == "CLEAR")
			{
				que_clear();
			}
		}
	}

	return 0;
}

