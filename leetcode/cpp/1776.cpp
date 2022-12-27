class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();
        vector<double> ans(n);
        

        vector<int> upStk;

        for(int i = n - 1; i >= 0; --i)
        {
            int speed = cars[i][1];
            int pos = cars[i][0];
            while(!upStk.empty())
            {
                int preIdx = upStk.back();
                int preSpeed = cars[preIdx][1];
                double prePos = cars[preIdx][0];
                if(speed <= preSpeed)
                    upStk.pop_back();
                else
                {
                    if(ans[preIdx] < 0)
                        break;

                    double t = (prePos - pos) / (speed - preSpeed);

                    if(t < ans[preIdx])
                        break;
                    else
                        upStk.pop_back();
                }
            }

            if(upStk.empty())
                ans[i] = -1;
            else
            {
                int preIdx = upStk.back();
                int preSpeed = cars[preIdx][1];
                double prePos = cars[preIdx][0];
                ans[i] = (prePos - pos) / (speed - preSpeed);
            }
            upStk.emplace_back(i);
        }


        return ans;
    }
};