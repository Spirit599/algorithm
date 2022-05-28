//多源BFS

bool cmp(const vector<int>& vec1, const vector<int>& vec2)
{
    return vec1[2] < vec2[2];
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        bool visit[n];
        memset(visit, 0, sizeof(visit));

        vector<int> ans{0};
        visit[0] = true;
        if(!visit[firstPerson])
        {
            visit[firstPerson] = true;
            ans.push_back(firstPerson);
        }

        sort(meetings.begin(), meetings.end(), cmp);
        int meetings_size = meetings.size();

        int i = 0;
        queue<int> que;
        //vector<int> edges[n];
        //vector<vector<int>> edges(n);
        while(i < meetings_size)
        {
            //cout<<"i:"<<i<<endl;
            map<int, vector<int>> edges;
            int p0 = meetings[i][0];
            int p1 = meetings[i][1];

            if(visit[p0] && !visit[p1])
            {
                visit[p1] = true;
                que.push(p1);
            }
            else if(visit[p1] && !visit[p0])
            {
                visit[p0] = true;
                que.push(p0);
            }
            else if(!visit[p1] && !visit[p0])
            {
                edges[p0].push_back(p1);
                edges[p1].push_back(p0);
            }

            while(i + 1 < meetings_size && meetings[i + 1][2] == meetings[i][2])
            {
                ++i;
                int p0 = meetings[i][0];
                int p1 = meetings[i][1];
                if(visit[p0] && !visit[p1])
                {
                    visit[p1] = true;
                    que.push(p1);
                }
                else if(visit[p1] && !visit[p0])
                {
                    visit[p0] = true;
                    que.push(p0);
                }
                else if(!visit[p1] && !visit[p0])
                {
                    edges[p0].push_back(p1);
                    edges[p1].push_back(p0);
                }
            }

            //cout<<"que:"<<que.size()<<endl;
            while(!que.empty())
            {
                int cur = que.front();
                //cout<<"cur"<<cur<<endl;
                ans.push_back(cur);
                que.pop();

                //cout<<"edges[cur].size() "<<edges[cur].size()<<endl;
                for(auto& son : edges[cur])
                {
                    //cout<<"son:"<<son<<endl;
                    if(!visit[son])
                    {
                        visit[son] = true;
                        que.push(son);
                    }
                }
            }
            //edges.clear();
            ++i;
        }

        return ans;

    }
};