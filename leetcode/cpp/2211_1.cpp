class Solution {
public:
    int countCollisions(string directions) {
        
        
        int directions_len = directions.size();

        int left_stop = directions_len;
        int right_stop = -1;
        int ans = 0;

        for(int i = 0; i < directions_len; ++i)
        {
            if(directions[i] != 'L')
            {
                left_stop = i;
                break;
            }
        }

        for(int i = directions_len - 1; i >= 0; --i)
        {
            if(directions[i] != 'R')
            {
                right_stop = i;
                break;
            }
        }

        for(int i = 0; i < directions_len; ++i)
        {
            if(directions[i] == 'L')
            {
                if(i > left_stop)
                {
                    ++ans;
                }
            }
            else if(directions[i] == 'R')
            {
                if(i < right_stop)
                {
                    ++ans;
                }
            }
        }

        return ans;
    }
};