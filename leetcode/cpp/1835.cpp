class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {

        // int xorSum1 = 0;
        // for(int num : arr1)
        //     xorSum1 ^= num;
        int xorSum2 = 0;
        for(int num : arr2)
            xorSum2 ^= num;

        int ans = 0;
        for(int num : arr1)
            ans ^= num & xorSum2;
        // for(int num : arr2)
        //     ans ^= num & xorSum1;
        return ans;
    }
};