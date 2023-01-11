class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int first = -1;
        int last = -1;
        int pre = -1;
        int ans = 0;
        int n = seats.size();

        for(int i = 0; i < n; ++i)
        {
            if(seats[i] == 1)
            {
                if(first == -1)
                    first = i;
                last = i;

                if(pre != -1)
                    ans = max(ans, (i - pre) >> 1);
                pre = i;
            }
        }

        return max({ans, first, n - 1 - last});
    }
};