#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    
    int n;
    cin >> n;
    int ans1 = 0;
    int ans2 = 0;
    int x,y;
    while(n--)
    {
        cin >> x >> y;
        if(x > y)
        {
            ans2 += x - y;
            ans1 += x;
        }
        else
        {
            ans1 += y;
        }
        // cout<<ans1<<" "<<ans2<<endl;
    }
    cout<<ans1<<" "<<ans2<<endl;
    
    return 0;
}
// 64 位输出请用 printf("%lld")