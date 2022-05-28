// 栈 stack
// 楼层 高度

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {
        // write code here
        int heights_size = heights.size();
        vector<int> ret(heights_size, 1);

        stack<int> prior;
        stack<int> next;


        for (int i = 0; i < heights_size - 1; ++i)
        {
            while(!prior.empty() && prior.top() <= heights[i])
            {
                prior.pop();
            }
            prior.push(heights[i]);
            ret[i + 1] += prior.size();
        }

        for (int i = heights_size - 1; i > 0; --i)
        {
            while(!next.empty() && next.top() <= heights[i])
            {
                next.pop();
            }
            next.push(heights[i]);
            ret[i - 1] += next.size();
        }

        return ret;
    }
};