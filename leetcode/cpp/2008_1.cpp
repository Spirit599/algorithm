bool cmp(const vector<int>& v1,
        const vector<int>& v2)
{
    if(v1[1] != v2[1])
        return v1[1] < v2[1];
    else
        return v1[0] < v2[0];
}

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        auto rides_size = rides.size();
        vector<int> all_pre(n + 1, -1);
        vector<int> pre(rides_size);
        sort(rides.begin(), rides.end(), cmp);

        int cur = 0;
        int i = 1;
        for (int i = 0; i < rides_size; ++i)
        {
            all_pre[rides[i][1]] = i;
        }
        int temp = -1;
        for (int i = 1; i <= n; ++i)
        {
            if(all_pre[i] != -1)
            {
                temp = all_pre[i];
            }
            else
            {
                all_pre[i] = temp;
            }
        }


        for(auto& i : all_pre)
            cout<<i<<endl;
        return 0;



    }
};