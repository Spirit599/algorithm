//1001 · 小行星的碰撞

class Solution {
public:
    /**
     * @param asteroids: a list of integers
     * @return: return a list of integers
     */
    vector<int> asteroidCollision(vector<int> &asteroids) {
        
        
        vector<int> ans;
        stack<int> to_right;

        for(int num : asteroids)
        {
            if(num < 0)
            {
                while(!to_right.empty() && to_right.top() < -(num))
                    to_right.pop();

                if(to_right.empty())
                    ans.push_back(num);
                else if(to_right.top() == -(num))
                    to_right.pop();
                
            }
            else if(num > 0)
            {
                to_right.push(num);
            }
        }

        int k = ans.size();

        while(!to_right.empty())
        {
            ans.push_back(to_right.top());
            to_right.pop();
        }

        reverse(ans.begin() + k, ans.end());

        return ans;

    }
};