// 线段树二分

class Solution {
public:

    int* segMentTree = nullptr;
    void updateTree(int treeIndex, int left, int right, int index, int addVal)
    {
        if(left == right && left == index)
        {
            segMentTree[treeIndex] += addVal;
            return ;
        }
        else if(left > index || right < index)
            return ;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        updateTree(leftIndex, left, mid, index, addVal);
        updateTree(rightIndex, mid + 1, right, index, addVal);
        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
    }

    int queryIndex(int treeIndex, int left, int right, int sum)
    {
        if(left == right && segMentTree[treeIndex] >= sum)
            return left;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int leftSum = segMentTree[leftIndex];
        if(leftSum >= sum)
            return queryIndex(leftIndex, left, mid, sum);
        else
            return queryIndex(rightIndex, mid + 1, right, sum - leftSum);
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> numsCp = nums;
        sort(nums.begin(), nums.end());
        int maxRank = 1;
        int rankToNum[n + 1];
        unordered_map<int, int> numToRank;
        rankToNum[maxRank] = nums[0];
        numToRank[nums[0]] = maxRank;

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] != nums[i - 1])
                ++maxRank;
            rankToNum[maxRank] = nums[i];
            numToRank[nums[i]] = maxRank;
        }

        segMentTree = (int*)malloc(sizeof(int) * 4 * (maxRank + 1));
        memset(segMentTree, 0, sizeof(int) * 4 * (maxRank + 1));


        function<double()> queryMid = [&]() -> double {
            
            if(k & 1)
            {
                int kth = (k >> 1) + 1;
                int rank = queryIndex(0, 0, maxRank, kth);
                return rankToNum[rank];
            }
            else
            {
                int kth1 = (k >> 1);
                int rank1 = queryIndex(0, 0, maxRank, kth1);
                int kth2 = (k >> 1) + 1;
                int rank2 = queryIndex(0, 0, maxRank, kth2);
                return (1.0 * rankToNum[rank1] + rankToNum[rank2]) / 2;
            }
            return 0;
        };

        vector<double> ans;
        for(int i = 0; i < k; ++i)
        {
            int rank = numToRank[numsCp[i]];
            updateTree(0, 0, maxRank, rank, 1);
        }
        ans.push_back(queryMid());

        for(int i = k; i < n; ++i)
        {
            int addRank = numToRank[numsCp[i]];
            updateTree(0, 0, maxRank, addRank, 1);
            int delRank = numToRank[numsCp[i - k]];
            updateTree(0, 0, maxRank, delRank, -1);
            ans.push_back(queryMid());
        }

        return ans;

    }
};