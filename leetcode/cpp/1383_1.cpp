namespace jiangxy
{
    class priority_queue
    {
    private:
        vector<int> pq_;
        void buildHeap()
        {
            int len = pq_.size();
            for(int i = len / 2; i >= 0; --i)
            {
                modifyHeap(i);
            }
        }
        void modifyHeap(int idx)
        {
            int len = pq_.size();
            while(idx * 2 + 1 < len)
            {
                int ll = idx * 2 + 1;
                int rr = idx * 2 + 2;
                int maxIdx = idx;

                if(pq_[ll] > pq_[maxIdx])
                    maxIdx = ll;
                if(rr < len && pq_[rr] > pq_[maxIdx])
                    maxIdx = rr;
                if(maxIdx != idx)
                {
                    swap(pq_[idx], pq_[maxIdx]);
                    idx = maxIdx;
                }
                else
                    break;
            }
        }
    public:
        priority_queue()
        {}
        priority_queue(vector<int>& arr)
            :   pq_(arr)
        {
            buildHeap();
        }
        int top() const
        {
            return pq_[0];
        }
        void pop()
        {
            int len = pq_.size();
            swap(pq_[0], pq_[len - 1]);
            pq_.pop_back();
            modifyHeap(0);
        }
        void push(int val)
        {
            pq_.push_back(val);
            int len = pq_.size();
            swap(pq_[0], pq_[len - 1]);
            modifyHeap(0);
        }
        bool empty()
        {
            return pq_.empty();
        }
        void print() const
        {
            for(int num : pq_)
                printf("%d ",num);
            printf("\n");
        }
    };
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {


        vector<pair<int, int>> vpii;
        for(int i = 0; i < n; ++i)
            vpii.emplace_back(efficiency[i], speed[i]);
        
        sort(vpii.begin(), vpii.end(), greater<>());
        long long sum = 0;
        long long ans = 0;
        long long eff = 0;
        int mod = 1e9 + 7;
        jiangxy::priority_queue pq;
        for(int i = 0; i < k; ++i)
        {
            eff = vpii[i].first;
            sum += vpii[i].second;
            pq.push(vpii[i].second);
            ans = max(ans, sum * eff);
        }
        // printf("%d %d\n", eff, sum);

        for(int i = k; i < n; ++i)
        {
            int curSpeed = vpii[i].second;
            eff = vpii[i].first;

            int minSpeed = pq.top();
            pq.pop();

            pq.push(curSpeed);
            sum += (curSpeed - minSpeed);
            ans = max(ans, sum * eff);
            // printf("%d %d\n", eff, sum);
        }



        return ans % mod;
    }
};