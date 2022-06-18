// 544 · 前K大数

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        
        int start = 0;
        int end = nums.size() - 1;

        while(1)
        {
        	int index = partition(nums, start, end);
        	if(index < k - 1)
        		start = index + 1;
        	else if(index > k - 1)
        		end = index - 1;
        	else
        		break;
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
        	ans.push_back(nums[i]);
        }

        sort(ans.begin(), ans.end(), greater<int>());

        return ans;
    }

    int partition(vector<int>& arr, int start, int end)
    {

    	int rand_index = rand() % (end - start + 1) + start;
    	swap(arr[rand_index], arr[start]);

    	int left = start;
    	int right = end;

    	while(left < right)
    	{
    		while(left < right && arr[right] <= arr[start])
    			--right;
    		while(left < right && arr[left] >= arr[start])
    			++left;
    		swap(arr[left], arr[right]);
    	}
    	swap(arr[left], arr[start]);

    	return left;
    }
};