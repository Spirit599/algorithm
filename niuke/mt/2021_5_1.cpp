#include <bits/stdc++.h>
using namespace std;


int xxxor(int num)
{
    int yu = num % 4;
    if(yu == 0)
        return num;
    else if(yu == 3)
        return 0;
    else if(yu == 1)
        return 1;
    else
        return num + 1;
}

int main() {
    
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int yu = n % i;
        int cnt = n / i;

        if(cnt % 2 == 0)
        {
            ans ^= xxxor(yu);
        }
        else
        {
            ans ^= xxxor(yu) ^ xxxor(i - 1);
        }
    }
    int num;
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        ans = ans ^ num;
    }
    cout<<ans<<endl;

    return 0;
}
