//二分
class Solution {
public:
    int minArray(vector<int>& numbers) {

        int high = numbers.size() - 1;
        int low = 0;

        while(low != high)
        {
            int mid = (high - low) / 2 + low;
            //cout<<low<<mid<<high<<endl;
            if(numbers[mid] < numbers[high])
            {
                high = mid;
            }
            else if(numbers[mid] > numbers[high])
            {
                low = mid + 1;
            }
            else
            {
                --high;
            }
        }

        return numbers[low];
    }
};