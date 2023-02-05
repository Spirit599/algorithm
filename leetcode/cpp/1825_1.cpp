// 线段树上二分

const int maxn = 1e5 + 5;

class MKAverage {
private:
    long long sum[4 * maxn];
    int sz[4 * maxn];
    int nums[maxn];
    int idx = 0;
    int m;
    int k;
    int n;
public:
    MKAverage(int mm, int kk)
    {
        m = mm;
        k = kk;
        n = m - 2 * k;
        memset(sum, 0, sizeof(sum));
        memset(sz, 0, sizeof(sz));
        memset(nums, 0, sizeof(nums));
    }

    void addElement(int num) {

        nums[++idx] = num;
        update(0, 0, maxn, num, 1);
        if(idx > m)
            update(0, 0, maxn, nums[idx - m], -1);
    }

    int calculateMKAverage() {
        
        if(idx < m)
            return -1;
        long long a = query(0, 0, maxn, k);
        long long b = query(0, 0, maxn, m - k);
        return (b - a) / (m - k - k);
    }

    void update(int treeIdx, int left, int right, int idx, int add)
    {
        if(left == right && left == idx)
        {
            sum[treeIdx] += add * idx;
            sz[treeIdx] += add;
            return ;
        }
        else if(left > idx || right < idx)
            return ;

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIdx + 1;
        int treeRight = 2 * treeIdx + 2;
        update(treeLeft, left, mid, idx, add);
        update(treeRight, mid + 1, right, idx, add);
        sum[treeIdx] = sum[treeLeft] + sum[treeRight];
        sz[treeIdx] = sz[treeLeft] + sz[treeRight];
    }

    long long query(int treeIdx, int left, int right, int size)
    {
        if(sz[treeIdx] <= size)
            return sum[treeIdx];
        if(left == right)
            return (long long)size * left;

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIdx + 1;
        int treeRight = 2 * treeIdx + 2;
        long long ret = query(treeLeft, left, mid, size);
        if(sz[treeLeft] < size)
            ret += query(treeRight, mid + 1, right, size - sz[treeLeft]);
        return ret;
    }
};

