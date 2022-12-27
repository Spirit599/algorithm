
class Solution {
public:
     int helper(int preIdx, int preHeight, int reIdx, int reHeight) {

        int dif = reIdx - preIdx - 1;
        int sub = abs(reHeight - preHeight);
        int add = dif - sub;
        add = (add + 1) / 2;
        return max(reHeight, preHeight) + add;
        

    }
    int maxBuilding(int n, vector<vector<int>>& re) {

        int preIdx = 1;
        int preHeight = 0;


        re.emplace_back(vector<int>({n, INT_MAX}));
        re.emplace_back(vector<int>({1, 0}));
        sort(re.begin(), re.end());
        
        int reSize = re.size();


        for(int i = 1; i < reSize; ++i)
        {
            int& preIdx = re[i - 1][0];
            int& preHeight = re[i - 1][1];
            int& reIdx = re[i][0];
            int& reHeight = re[i][1];
            int dif = reIdx - preIdx;
            
            if(reHeight > dif + preHeight)
                reHeight = dif + preHeight;
        }

        for(int i = reSize - 2; i >= 0; --i)
        {
            int& preIdx = re[i + 1][0];
            int& preHeight = re[i + 1][1];
            int& reIdx = re[i][0];
            int& reHeight = re[i][1];
            int dif = preIdx - reIdx;
            if(reHeight > dif + preHeight)
                reHeight = dif + preHeight;
        }

        int ans = 0;
        for(int i = 1; i < reSize; ++i)
        {
            ans = max(ans, helper(re[i - 1][0], re[i - 1][1], re[i][0], re[i][1]));
        }


        return ans;

    }
};