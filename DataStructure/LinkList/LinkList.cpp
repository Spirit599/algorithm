#include <cstdio>
#include "LinkList.h"

int main(int argc, char const *argv[])
{
	___list::list<int> l;

	int n = 10;
	while(n--)
		l.push_back(n);

	printf("%d\n", l.back());

	return 0;
}