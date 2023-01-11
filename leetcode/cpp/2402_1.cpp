// 2402. 会议室 III
struct meeting_info
{
    int start;
    int end;
    int dif;
};
struct cmp
{
    bool operator() (const meeting_info& lhs, const meeting_info& rhs)
    {
        return lhs.start > rhs.start;
    }
};

class Solution {
public:
    


    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));

        vector<int> rooms(n);
        for(int i = 0; i < n; ++i)
            rooms[i] = i;

        priority_queue<int, vector<int>, greater<int>> free_room(rooms.begin(), rooms.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_room;

        vector<meeting_info> info(meetings.size());
        for(int i = 0; i < info.size(); ++i)
        {
            meeting_info tmp;
            tmp.start = meetings[i][0];
            tmp.end = meetings[i][1];
            tmp.dif = meetings[i][1] - meetings[i][0];
            info[i] = tmp;
        }

        priority_queue<meeting_info, vector<meeting_info>, cmp> pq_meeting(info.begin(), info.end());

        long long cur_time = pq_meeting.top().start;
        while(!pq_meeting.empty())
        {
            meeting_info cur_meeting = pq_meeting.top();
            //cout<<cur_time<<endl;

            while(!busy_room.empty() && busy_room.top().first <= cur_time)
            {
                free_room.push(busy_room.top().second);
                busy_room.pop();  
            }

            if(!free_room.empty())
            {
                int choose = free_room.top();
                free_room.pop();
                busy_room.push(make_pair(cur_time + cur_meeting.dif, choose));
                ++cnt[choose];
                pq_meeting.pop();
                if(!pq_meeting.empty())
                    cur_time = max(cur_time, (long long)pq_meeting.top().start);
            }
            else
            {
                cur_time = busy_room.top().first;
            }
        }

        int maxx = 0;
        int ans = -1;
        for(int i = 0; i < n; ++i)
        {
            //cout<<cnt[i]<<endl;
            if(cnt[i] > maxx)
            {
                maxx = cnt[i];
                ans = i;
            }
        }

        return ans;
    }
};