#include<bits/stdc++.h>
using namespace std;

//重构中序遍历
//树状dp

const double eps = 1e-8;
//32位
const int MAX_INT = 0x7fffffff;

const int maxn = 305;

int dp[maxn][maxn][maxn];
int value[maxn];

int dfs(int left, int right, int father)
{
    if(left > right)
        return 0;
    if(dp[left][right][father] != -1)
        return dp[left][right][father];

    int ret = MAX_INT;
    for (int i = left; i <= right; ++i)
    {
        int left_num = dfs(left, i - 1, i);
        int right_num = dfs(i + 1, right, i);
        ret = min(ret, left_num + right_num + value[father] * value[i]);
    }

    return dp[left][right][father] = ret;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    value[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> value[i];
    memset(dp, -1, sizeof(dp));
    cout<< dfs(1, n, 0) << endl;
    return 0;
}

