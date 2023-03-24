#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	string str;
	cin >> str;

	// assert(str[0] == 'M');
	// assert(str[n - 1] == 'T');
	
	int i = 0;
	while(i < n && str[i] != 'M')
		++i;
	while(i < n && str[i] != 'T')
		++i;
	int j = n - 1;
	while(j >= 0 && str[j] != 'T')
		--j;
	while(j >= 0 && str[j] != 'M')
		--j;
	for(int k = i + 1; k <= j - 1; ++k)
		cout<<str[k];
	return 0;
}