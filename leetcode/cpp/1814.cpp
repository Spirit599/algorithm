class Solution {
public:
	long long rev(int val) {

		string num = to_string(val);
		reverse(num.begin(), num.end());
		return stoll(num);
	}
    int countNicePairs(vector<int>& nums) {

    	unordered_map<long long, int> memo;
    	long long ans = 0;
    	int mod = 1e9 + 7;
    	for(int num : nums)
    	{
    		int ret = memo[num - rev(num)]++;
    		ans += ret;
    		ans %= mod;
    	}
    	return ans;
    }
};