#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, k;
    cin>>n>>k;
    vector<pii> arr;
    arr.emplace_back();
    auto cmp = [&](int p1, int p2) {
        int v1 = arr[p1].first + arr[p1].second * 2;
        int v2 = arr[p2].first + arr[p2].second * 2;
        return v1 > v2 || (v1 == v2 && p1 < p2);
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    int x,y;
    while(n--)
    {
        cin>>x>>y;
        arr.emplace_back(x, y);
        int idx = arr.size() - 1;
        pq.push(idx);
        while(pq.size() == k + 1)
            pq.pop();
    }

    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for(int num : ans)
        cout<<num<<" ";
    return 0;

}
// 64 位输出请用 printf("%lld")