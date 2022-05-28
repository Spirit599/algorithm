// struct cmp
// {
//     bool operator() (const pair<int, int> p1, const pair<int, int> p2)
//     {
//         return p1.first * p2.second > p1.second * p2.first;
//     }
// };

//decltype
//lambda
//多路归并
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n = arr.size();

        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 1; i < n; ++i)
        {
            pq.push({0, i});
        }

        --k;
        while(k--)
        {
            auto cur = pq.top();
            pq.pop();
            cout<<arr[cur.first]<<" "<<arr[cur.second]<<endl;

            if(cur.first + 1< cur.second)
                pq.push({cur.first + 1, cur.second});
        }

        return {arr[pq.top().first], arr[pq.top().second]};

    }
};