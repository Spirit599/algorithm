class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int last = nums1.size() - 1;
        --m;
        --n;
        while(m != -1 && n != -1)
        {
            cout<<nums1[m]<<" "<<nums2[n]<<endl;
            if(nums1[m] > nums2[n])
            {
                nums1[last--] = nums1[m--];
            }
            else
            {
                nums1[last--] = nums2[n--];
            }
        }

        while(n != -1)
        {
            nums1[last--] = nums2[n--];   
        }

        return;
    }
};