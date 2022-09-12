class Solution {
public:
    struct frequent
    {
        int f;
        int k;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {


        unordered_map<int, int> memo;
        for(int num : nums)
            memo[num]++;
        vector<frequent> fk;
        for(auto& kav : memo)
            fk.push_back({kav.second, kav.first});

        int start = 0;
        int end = fk.size() - 1;

        while(1) {
            int index = partition(fk, start, end);
            if(index > k - 1)
            {
                end = index - 1;
            } else if(index < k - 1)
            {
                start = index + 1;
            } else {
                break;
            }
        }

        vector<int> ans(k);
        for(int i = 0; i < k; ++i)
            ans[i] = fk[i].k;

        return ans;


    }

    int partition(vector<frequent>& arr, int start, int end) {

        int left = start;
        int right = end;

        cout<<left<<" "<<right<<endl;

        while(left < right)
        {
            while(left < right && arr[right].f <= arr[start].f)
                --right;
            while(left < right && arr[left].f >= arr[start].f)
                ++left;
            swap(arr[left], arr[right]);
        }

        swap(arr[left], arr[start]);
        return left;
    }
};