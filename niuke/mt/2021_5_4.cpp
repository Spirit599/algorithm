#include <bits/stdc++.h>
using namespace std;


bool check(vector<int>& arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int n = arr.size();
    printf("n = %d\n", n);
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    // if(n == 1 && nums[0] == 1)
    //     return true;

    vis[0] = true;
    vector<int> nums({arr[0] - 1});
    printf("arr[0] - 1 = %d\n", arr[0] - 1);


    function<bool(int)> dfs = [&](int cnt, int depth) -> bool {



        if(nums.empty())
        {
            if(cnt == n)
                return true;
            return false;
        }

        int cur = nums.back();
        printf("cur = %d\n", cur);
        // nums.pop_back();
        // bool ret = false;
        for(int i = 1; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(!vis[i] && arr[i] + arr[j] <= cur && !vis[j])
                {
                    // printf("%d %d\n", i,j);
                    vis[i] = true;
                    vis[j] = true;
                    int k = 0;
                    if(arr[i] - 1 != 0)
                    {
                        ++k;
                        nums.push_back(arr[i] - 1);
                    }
                    if(arr[j] - 1 != 0)
                    {
                        ++k;
                        nums.push_back(arr[j] - 1);
                    }
                    if(cur - arr[i] - arr[j] != 0)
                    {
                        ++k;
                        nums.push_back(cur - arr[i] - arr[j]);
                    }
                    if(dfs())
                        return true;
                    while(k--)
                        nums.pop_back();
                    vis[i] = false;
                    vis[j] = true;
                }
            }
        }
        return false;
    };
    
    
    return dfs(0);

}

int main() {
    
    int n;
    while(cin >> n)
    {
        // printf("n = %d\n", n);
        vector<int> arr(n);
        // printf("n = %d\n", n);
        for(int i = 0; i < n; ++i)
        {
            // printf("i = %d\n", i);
            cin >> arr[i];
            // scanf("%d",&arr[i]);
            // printf("arr[i] = %d\n", arr[i]);
        }
        printf("n = %d\n", n);
        if(check(arr))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
// 64 位输出请用 printf("%lld")