//优先队列

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> free_server;
        for(int i = 0; i < k; ++i)
            free_server.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_server;
        vector<int> record(k);

        for(int i = 0; i < arrival.size(); ++i)
        {
            int arr_time = arrival[i];
            while(!busy_server.empty() && busy_server.top().first <= arr_time)
            {
                free_server.insert(busy_server.top().second);
                busy_server.pop();
            }

            if(free_server.empty())
            {
                continue;
            }

            auto cur_server = free_server.lower_bound(i % k);
            if(cur_server == free_server.end())
                cur_server = free_server.begin();

            
            ++record[*cur_server];
            busy_server.push(make_pair(arr_time + load[i], *cur_server));
            free_server.erase(cur_server);

        }

        vector<int> ans;
        int maxx = *max_element(record.begin(), record.end());
        for(int i = 0; i < record.size(); ++i)
        {
            if(record[i] == maxx)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};