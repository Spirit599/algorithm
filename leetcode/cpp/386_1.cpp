class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ans(n);

        int num = 1;

        int cnt = 0;
        while(cnt != n)
        {
            ans[cnt] = num;
            if(num * 10 <= n)
            {
                num = num * 10;
            }
            else
            {
                while(num % 10 == 9 || num + 1 > n)
                    num = num / 10;
                ++num;
            }
            ++cnt;
        }

        return ans;
    }
};