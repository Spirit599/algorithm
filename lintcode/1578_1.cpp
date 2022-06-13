//二分模板

class Solution {
public:
    /**
     * @param s: the given string
     * @return: the number of A
     */
    int find_first_A(string &s)
    {
        int low = 0;
        int high = s.size() - 1;

        while(low < high)
        {
            int mid = (high - low) / 2 + low;
            if(s[mid] == 'B')
            {
                low = mid + 1;
            }
            else //s[mid] == 'C' || s[mid] == 'D' || s[mid] == 'A'
            {
                high = mid;
            }
        }

        return low;
    }
    int find_last_A(string &s)
    {
        int low = 0;
        int high = s.size() - 1;

        while(low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if(s[mid] == 'B' || s[mid] == 'A')
            {
                low = mid;
            }
            else //s[mid] == 'C' || s[mid] == 'D'
            {
                high = mid - 1;
            }
        }

        return low;
    }

    int countA(string &s) {
        
        int start = find_first_A(s);
        if(s[start] != 'A')
            return 0;
        int end = find_last_A(s);

        return end - start + 1;
    }
};