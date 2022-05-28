//滑动窗口 双指针

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int cur_len = 0;
        int front = -1;
        int end = -1;
        bool visit[200];
        memset(visit, 0, sizeof(visit));
        int n = s.size();

        while(front != n - 1)
        {
            if(!visit[s[front + 1]])
            {
                ++front;
                visit[s[front]] = true;
                ++cur_len;
            }
            else
            {
                while(visit[s[front + 1]])
                {
                    ++end;
                    visit[s[end]] = false;
                    --cur_len;
                }

            }
            cout<<front<<" "<<end<<" "<<cur_len<<endl;
            ans = max(ans, cur_len);
        }

        return ans;
    }
};