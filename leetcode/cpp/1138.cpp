class Solution {
public:
    string alphabetBoardPath(string target) {

        int x = 0;
        int y = 0;
        string ans;
        for(char c : target)
        {
            int idx = c - 'a';
            int tx = idx % 5;
            int ty = idx / 5;
            printf("%d %d\n", tx, ty);

            if(y == 5)
            {
                while(y != ty)
                {
                    if(y < ty)
                    {
                        ++y;
                        ans.push_back('D');
                    }
                    else
                    {
                        --y;
                        ans.push_back('U');
                    }
                }
                while(x != tx)
                {
                    if(x < tx)
                    {
                        ++x;
                        ans.push_back('R');
                    }
                    else
                    {
                        --x;
                        ans.push_back('L');
                    }
                }
            }
            else
            {
                while(x != tx)
                {
                    if(x < tx)
                    {
                        ++x;
                        ans.push_back('R');
                    }
                    else
                    {
                        --x;
                        ans.push_back('L');
                    }
                }
                while(y != ty)
                {
                    if(y < ty)
                    {
                        ++y;
                        ans.push_back('D');
                    }
                    else
                    {
                        --y;
                        ans.push_back('U');
                    }
                }
            }
            ans.push_back('!');
        }

        return ans;
    }
};