// wrong ans

typedef pair<int, int> pii;

class Solution {
public:
    int querySum(int* segMentTree, int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(queryLeft > right || queryRight < left)
            return 0;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int ret = querySum(segMentTree ,leftIndex, left, mid, queryLeft, queryRight);
        ret += querySum(segMentTree ,rightIndex, mid + 1, right, queryLeft, queryRight);
        return ret;

    }
    void updateTree(int* segMentTree, int treeIndex, int left, int right, int index, int val)
    {
        if(left == right && left == index)
        {
            segMentTree[treeIndex] = val;
            return ;
        }
        else if(left > index || right < index)
            return ;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        updateTree(segMentTree ,leftIndex, left, mid, index, val);
        updateTree(segMentTree ,rightIndex, mid + 1, right, index, val);
        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        int n1 = nums1.size();
        int* segMentTree1 = (int*)malloc(sizeof(int) * 4 * (n1 + 1));
        memset(segMentTree1, 0, sizeof(int) * 4 * n1);
        int n2 = nums2.size();
        int* segMentTree2 = (int*)malloc(sizeof(int) * 4 * (n2 + 1));
        memset(segMentTree2, 0, sizeof(int) * 4 * n2);

        int vis1[n1];
        memset(vis1, 0, sizeof(vis1));
        int vis2[n2];
        memset(vis2, 0, sizeof(vis2));

        priority_queue<pii> pq1;
        for(int i = 0; i < n1; ++i)
            pq1.push(make_pair(nums1[i], -i));
        priority_queue<pii> pq2;
        for(int i = 0; i < n2; ++i)
            pq2.push(make_pair(nums2[i], -i));

        int remain1 = n1;
        int remain2 = n2;
        int left1 = 0;
        int left2 = 0;

        while(k)
        {
            int index1 = -1;
            if(!pq1.empty())
                index1 = -pq1.top().second;
            while(!pq1.empty() && vis1[index1] == -1)
            {
                pq1.pop();
                index1 = -pq1.top().second;
            }

            int index2 = -1;
            if(!pq2.empty())
                index2 = -pq2.top().second;
            while(!pq2.empty() && vis2[index2] == -1)
            {
                pq2.pop();
                index2 = -pq2.top().second;
            }

            printf("%d %d\n", index1, index2);
            if(index2 == -1 || (index1 != -1 && nums1[index1] > nums2[index2]))
            {
                printf("nums1[index1] = %d\n", nums1[index1]);
                pq1.pop();
                vis1[index1] = 1;
                int afterPut = querySum(segMentTree1, 0, 0, n1, index1 + 1, n1);
                printf("afterPut = %d\n", afterPut);
                afterPut = (n1 - index1 - 1) - afterPut;
                printf("afterPut = %d\n", afterPut);
                updateTree(segMentTree1, 0, 0, n1, index1, 1);
                if(afterPut + remain2 >= k)
                {
                    for(int i = left1; i < index1; ++i)
                    {
                        printf("clear1 %d\n", i);
                        vis1[i] = -1;
                        --remain1;
                    }
                    left1 = index1 + 1;
                }
                --k;
                --remain1;
            }
            else
            {
                printf("nums2[index2] = %d\n", nums2[index2]);
                pq2.pop();
                vis2[index2] = 1;
                
                int afterPut = querySum(segMentTree2, 0, 0, n2, index2 + 1, n2);
                afterPut = (n2 - index2 - 1) - afterPut;
                updateTree(segMentTree2, 0, 0, n2, index2, 1);
                if(afterPut + remain1 >= k)
                {
                    for(int i = left2; i < index2; ++i)
                    {
                        printf("clear2 %d\n", i);
                        vis2[i] = -1;
                        --remain2;
                    }
                    left2 = index2 + 1;
                }
                --k;
                --remain1;
            }
        }
        printf("over\n");

        vector<int> ret;
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2)
        {
            printf("%d %d\n",i,j );
            while(i < n1 && vis1[i] != 1)
                ++i;
            while(j < n2 && vis2[j] != 1)
                ++j;

            if(nums1[i] > nums2[j])
            {
                printf("%d\n", vis1[i]);
                ret.push_back(nums1[i++]);
            }
            else
            {
                printf("%d\n", vis2[j]);
                ret.push_back(nums2[j++]);
            }
        }
        while(i < n1)
        {
            if(vis1[i] == 1)
                ret.push_back(nums1[i]);
            ++i;
        }
        while(j < n2)
        {
            if(vis2[j] == 1)
                ret.push_back(nums2[j]);
            ++j;
        }


        return ret;

    }
};