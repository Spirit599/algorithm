class Solution {
public:
    /**
     * @param a: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &a) {
        
        int len = a.size();
        for(int i = len / 2; i >= 0; --i)
        	modify(a, i, len);
    }

    void modify(vector<int>& nums, int index, int len)
    {
    	while((index << 1) + 1 < len)
    	{
    		int left_son = (index << 1) + 1;
    		int right_son = (index << 1) + 2;
    		int max_index = index;

    		if(left_son < len && nums[left_son] < nums[max_index])
    			max_index = left_son;
    		if(right_son < len && nums[right_son] < nums[max_index])
    			max_index = right_son;
    		if(index != max_index)
    		{
    			swap(nums[index], nums[max_index]);
    			index = max_index;
    		}
    		else
    		{
    			break;
    		}
    	}
    }
};