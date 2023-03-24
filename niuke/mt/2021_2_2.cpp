#include <bits/stdc++.h>
using namespace std;

int check(int x, int y)
{
    string sx = to_string(x);
    // string sy = to_string(y);
    reverse(sx.begin(), sx.end());
    // if(x == 219978)
    //     cout<<sx<<" "<<sy<<endl;
    int nx = stoi(sx);
    if(nx == y)
        return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ans;
    for(int i = 1; i * 4 <= n; ++i)
    {
        if(check(i, 4 * i))
            ans.emplace_back(i, 4 * i);
    }
    cout<<ans.size()<<endl;
    for(auto& [x, y] : ans)
        cout<<x<<" "<<y<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")