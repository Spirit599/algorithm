class Solution {
public:
    int minimumPartition(string s, int k) {
        
        long long pre = 0;
        int ans = 0;
        for(char c : s)
        {
            int num = c - '0';
            if(num > k)
                return -1;
            pre = 10 * pre + num;
            printf("%d\n", pre);
            if(pre > k)
            {
                pre = num;
                ++ans;
            }
        }
        return ans + 1;
    }
};