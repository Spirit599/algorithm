const int MOD = 1000000007;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> bits;
        while(n) {
            if(n & 1)
                bits.push_back(1);
            else
                bits.push_back(0);
            n = n >> 1;
        }
        vector<int> arr;
        int k = 1;
        for(int bit : bits)
        {
            if(bit == 1)
                arr.push_back(k);
            k = k << 1;
        }
        for(int num : arr)
            printf("%d\n", num);

        vector<int> ans;
        for(auto& query : queries)
        {
            long long tmp = 1;
            for(int i = query[0]; i <= query[1]; ++i)
                tmp = (tmp * num[i]) % MOD;
            ans.push_back(tmp); 
        }
        return ans;
    }
};