/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    enum DIRE
    {
        LEFT = 0,
        DOWN = 1,
        RIGHT = 2,
        UP = 3
    };
    int m_;
    int n_;
    bool is_visited(vector<vector<bool>>& visited, int i, int j)
    {
        if(i < 0 || i >= m_ || j < 0 || j >= n_ || visited[i][j])
            return false;
        return true;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        m_ = m;
        n_ = n;
        int nums = m * n;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n));
        ListNode* p = head;

        int cnt = 0;
        int i = 0;
        int j = 0;
        int dire = LEFT;
        while(cnt != nums)
        {
            //printf("%d %d\n",i,j);
            if(p)
            {
                ans[i][j] = p->val;
                p = p->next;
            }
            else
            {
                break;
            }
            ++cnt;
            visited[i][j] = true;

            if(dire == LEFT)
            {
                if(is_visited(visited, i, j + 1))
                {
                    ++j;
                }
                else
                {
                    ++i;
                    dire = DOWN;
                }
            }
            // else if(dire == DOWN)
            // {
            //     if(is_visited(visited, i + 1, j))
            //     {
            //         ++i;
            //     }
            //     else
            //     {
            //         --j;
            //         dire = RIGHT;
            //     }
            // }
            // else if(dire == RIGHT)
            // {
            //     if(is_visited(visited, i, j - 1))
            //     {
            //         --j;
            //     }
            //     else
            //     {
            //         --i;
            //         dire = UP;
            //     }
            // }
            // else if(dire == UP)
            // {
            //     if(is_visited(visited, i - 1, j))
            //     {
            //         --i;
            //     }
            //     else
            //     {
            //         ++j;
            //         dire = LEFT;
            //     }
            // }

        }

        return ans;
    }
};