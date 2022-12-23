class Solution {
public:

    int closestToTarget(vector<int>& arr, int target) {

        
        int n = arr.size();
        int ans = abs(target - arr[0]);
        vector<int> pre({arr[0]});

        for(int num : arr)
        {
            vector<int> npre({num});
            ans = min(ans, abs(target - num));
            for(int p : pre)
            {
                int np = num & p;
                ans = min(ans, abs(target - np));
                npre.emplace_back(np);
            }
            npre.erase(unique(npre.begin(), npre.end()), npre.end());
            pre = npre;
        }

        return ans;

    }
};