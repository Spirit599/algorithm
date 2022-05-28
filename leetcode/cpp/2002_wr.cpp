#include<iostream>
using namespace std;
#include<vector>
#include<cstring>


class Solution {
private:
    int sub1_start;
    int sub1_end;
    int sub1;
    int sub2;
    int sub2_start;
    int sub2_end; 
    int ret;
    int vp_size;
    int s_size;
public:
    void dfs_sub1(int& sub1_start, int& sub1_end, int& sub1, 
        vector<pair<int, int>>& vp, bool visit_vp[], bool visit[])
    {

        for (int i = 0; i < vp_size; ++i)
        {
            if(vp[i].first > sub1_start && vp[i].second < sub1_end && !visit_vp[i])
            {
                int temp_start = sub1_start;
                int temp_end = sub1_end;
                sub1_start = vp[i].first;
                sub1_end = vp[i].second;
                sub1 += 2;
                visit_vp[i] = true;
                visit[sub1_start] = true;
                visit[sub1_end] = true;
                //cout<<i<<" "<<sub1_start<<" "<<sub1_end<<" "<<sub1<<endl;
                dfs_sub1(sub1_start, sub1_end, sub1, vp, visit_vp, visit);
                visit_vp[i] = false;
                visit[sub1_start] = false;
                visit[sub1_end] = false;
                sub1 -= 2;
                sub1_start = temp_start;
                sub1_end = temp_end;

            }
            else
            {
                if(i == vp_size - 1)
                {
                    sub2 = 0;
                    sub2_start = -1;
                    sub2_end = s_size; 
                    //cout<<"start"<<endl;
                    dfs_sub2(sub2_start, sub2_end, sub2, vp, visit_vp, visit);
                    //cout<<"over"<<endl;
                }
            }         
        }

    }

    inline int check_space(int& sub1_start, int& sub1_end, 
                            int& sub2_start, int& sub2_end, 
                            bool visit[])
    {
        // if(sub1 == 4 && sub2 == 4)
        //     cout<<sub1_start<<sub1_end<<sub2_start<<sub2_end<<endl;
        int space1 = 0;
        int space2 = 0;
        int index_i = 0;
        int index_j = 0;
        //cout<<sub1_start<<sub1_end<<sub2_start<<sub2_end<<endl;
        for (int i = sub1_start + 1; i < sub1_end; ++i)
        {
            /* code */
            if(visit[i])
            {
                index_i = i;
                space1++;
            }
        }
        for (int i = sub2_start + 1; i < sub2_end; ++i)
        {
            /* code */
            if(visit[i])
            {   
                index_j = i;
                space2++;
            }
        }

        if(space1 == 0 && space2 == 0)
            return 0;
        else if(space1 == 1 && space2 == 1)
        {
            if(index_j == index_i)
                return 4;//
            else
                return 3;
        }
        else if(space1 == 0)
            return 2;
        else if(space2 == 0)
            return 1;
        else
            return 3;
    }

    void dfs_sub2(int& sub2_start, int& sub2_end, int& sub2, 
        vector<pair<int, int>>& vp, bool visit_vp[], bool visit[])
    {

        int action = check_space(sub1_start, sub1_end, sub2_start, sub2_end, visit);

        int cur = 0;
        if(action == 0)
            cur = sub1 * sub2;
        else if(action == 1)
            cur = (sub1 + 1) * sub2;
        else if(action == 2)
            cur = (sub2 + 1) * sub1;
        else if(action == 3)
            cur = (sub1 + 1) * (sub2 + 1);
        else
            cur = (min(sub1, sub2) + 1) * max(sub1, sub2);

        if(ret < cur)
        {
            ret = cur;
            cout<<ret<<endl;
        }
        for (int i = 0; i < vp_size; ++i)
        {
            if(vp[i].first > sub2_start && vp[i].second < sub2_end && !visit_vp[i])
            {
                int temp_start = sub2_start;
                int temp_end = sub2_end;
                sub2_start = vp[i].first;
                sub2_end = vp[i].second;
                sub2 += 2;
                visit_vp[i] = true;
                visit[sub2_start] = true;
                visit[sub2_end] = true;
                //cout<<i<<" "<<sub2_start<<" "<<sub2_end<<" "<<sub2<<endl;
                dfs_sub2(sub2_start, sub2_end, sub2, vp, visit_vp, visit);
                visit_vp[i] = false;
                visit[sub2_start] = false;
                visit[sub2_end] = false;
                sub2 -= 2;
                sub2_start = temp_start;
                sub2_end = temp_end;

            }       
        }
    }

    int maxProduct(string s) {
        
        s_size = s.size();
        vector<pair<int, int>> vp;

        ret = 0;

        bool visit[s_size];
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < s_size - 1; ++i)
        {
            for (int j = s_size - 1; j >= i + 1; --j)
            {
                if(s[i] == s[j] && !visit[i] && !visit[j])
                {
                    visit[i] = true;
                    visit[j] = true;
                    vp.push_back({i, j});
                }
            }
        }

        for (auto& i : vp)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }

        vp_size = vp.size();
        if(vp_size >= 2)
        {
            sub1 = 0;
            sub1_start = -1;
            sub1_end = s_size;

            bool visit_vp[vp_size];
            memset(visit_vp, 0, sizeof(visit_vp));
            memset(visit, 0, sizeof(visit));
            dfs_sub1(sub1_start, sub1_end, sub1, vp, visit_vp, visit);           
        }
        else if(vp_size == 1)
        {
            if(vp[0].first + 1 == vp[0].second)
            {
                if(s_size > 2)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                if(s_size > 3)
                {
                    return 3;
                }
                else
                {
                    return 2;
                }
            }
        }
        else
        {
            return 1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.maxProduct("accbcaxxcxx");
    //sol.maxProduct("abcddcfebfea");
    return 0;
}