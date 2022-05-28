class Solution {
public:
    vector<int> quickchoose(vector<int>& arr, int k, int start, int end)
    {
        int left = start;
        int right = end;

        while(left < right)
        {
            while(left < right && arr[right] >= arr[start])
                --right;
            while(left < right && arr[left] <= arr[start])
                ++left;
            swap(arr[left], arr[right]);
        }

        swap(arr[left], arr[start]);
        if(left > k)
            return quickchoose(arr, k, start, left - 1);
        else if(left < k)
            return quickchoose(arr, k, left + 1, end);

        return {arr.begin(), arr.begin() + k};
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        // vector<int> ans;
        // priority_queue<int, vector<int>, greater<int>> pq = {arr.begin(), arr.end()};
        // while(k--)
        // {
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // return ans;
        if(arr.size() <= k)
            return arr;
        return quickchoose(arr, k, 0, arr.size() - 1);
    }
};