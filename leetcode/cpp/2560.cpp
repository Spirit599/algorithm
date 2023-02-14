class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;

        auto check = [&](int mid) -> bool {

            int no = 0;
            int yes = 0;
            
            for(int num : nums)
            {
                int nno = no;
                int nyes = yes;
                if(num <= mid)
                {
                    nyes = no + 1;
                    nno = yes;
                }
                else
                {
                    nyes = yes;
                    nno = yes;
                }
                
                yes = nyes;
                no = nno;

                if(yes >= k)
                    return true;
            }

            return false;       
        };

        while(low != high)
        {
            int mid = (low + high) >> 1;
            if(check(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};