class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int ret = 0;
        for (auto& str : operations)
        {
            if(str == "++X" || str == "X++")
            {
                ret++;
            }
            else
            {
                ret--;
            }
        }

        return ret;
    }
};