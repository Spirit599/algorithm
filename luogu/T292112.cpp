#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d", &n);

	int clock[1440];
	memset(clock, 0, sizeof(clock));
	clock[0] = 1;

	for(int i = 1; i < 1440; ++i)
	{
		int shi = i / 60;
		int fen = i % 60;

		int a3 = fen / 10;
		int a4 = fen % 10;
		if(shi >= 10)
		{
			int a1 = shi / 10;
			int a2 = shi % 10;
			if(a1 - a2 == a2 - a3 && a2 - a3 == a3 - a4)
			{
				clock[i] = clock[i - 1] + 1;
				// printf("yes %d %d %d %d %d\n", a1,a2,a3,a4,clock[i]);
				
			}
			else
			{
				// printf("no %d %d %d %d\n", a1,a2,a3,a4);
				clock[i] = clock[i - 1];
			}
		}
		else
		{
			int a2 = shi;
			
			if(a2 - a3 == a3 - a4)
			{
				clock[i] = clock[i - 1] + 1;
				// printf("yes %d %d %d %d\n", a2,a3,a4, clock[i]);
				
			}
			else
			{
				// printf("no %d %d %d\n", a2,a3,a4);
				clock[i] = clock[i - 1];
			}
		}
	}

	int k = n / 1440;
	int cur = n % 1440;

	printf("%d",k * clock[1439] + clock[cur]);
	return 0;
}