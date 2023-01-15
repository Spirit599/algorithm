class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();
        int low = 0;
        int high = n;

        auto check = [&](int mid) -> bool {

            int cnt = 0;
            for(int cit : citations)
            {
                if(cit >= mid)
                {
                    ++cnt;
                    if(cnt == mid)
                        return true;
                }
            }
            return false;
        };

        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};