class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> sta;
        vector<int> ans;
        for(int asteroid : asteroids)
        {
            if(asteroid < 0)
            {
                int flag = false;
                while(!sta.empty() && sta.top() <= -asteroid)
                {
                    int k = sta.top();
                    sta.pop();
                    if(k == -asteroid)
                    {
                        flag = true;
                        break;
                    }
                    
                }
                if(sta.empty() && !flag)
                    ans.push_back(asteroid);
            }
            else
            {
                sta.push(asteroid);
            }
        }
        int curN = ans.size();
        while(!sta.empty())
        {
            ans.push_back(sta.top());
            sta.pop();
        }
        reverse(ans.begin() + curN, ans.end());

        return ans;
    }
};