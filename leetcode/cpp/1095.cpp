/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
// 山脉二分
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        int low = 0;
        int high = n - 1;

        while(low != high)
        {
            int mid = (low + high) >> 1;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        int ll = 0;
        int rr = low;
        while(ll <= rr)
        {
            int mid = (ll + rr) >> 1;
            int val = mountainArr.get(mid);
            if(val == target)
                return mid;
            else if(val < target)
                ll = mid + 1;
            else
                rr = mid - 1;
        }

        ll = low;
        rr = n - 1;
        while(ll <= rr)
        {
            int mid = (ll + rr) >> 1;
            int val = mountainArr.get(mid);
            if(val == target)
                return mid;
            else if(val > target)
                ll = mid + 1;
            else
                rr = mid - 1;
        }

        return -1;
    }
};