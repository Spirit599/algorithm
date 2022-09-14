# 1.滑动窗口
主要是对于一个状态，要有二维性。
要么向左，要么向右。
## 1.1
### 3. 无重复字符的最长子串 高频 medium

### 32 · 最小子串覆盖
source = "adobecodebanc"
target = "abc"
ans = "banc"

### 406 · 和大于S的最小子数组

### 1375 · 至少K个不同字符的子串
```
while(right < n)
{
    if(memo.size() < k)
    {
        ++right;
        ++memo[s[right]];
    }
    else
    {
        ans += n - right;
        ++left;
        if(--memo[s[left]] == 0)
            memo.erase(s[left]);
    }
}
```

### 992. K 个不同整数的子数组
```
//至多K个不同字符的子串
while(right < n)
{
	if(memo.size() <= k)
	{
		ans += right - left;
		++right;
		if(right < n)
			++memo[nums[right]];
	}
	else
	{
		
		++left;
		if(--memo[nums[left]] == 0)
			memo.erase(nums[left]);
	}
}
```
```
// 求正好K个
// 可以转化成 至多K个 - 至多K-1个
//           至少K个 - 至少K+1个
return subarraysNoMoreThanK(nums, k) - subarraysNoMoreThanK(nums, k - 1);
return subarraysNoLessThanK(nums, k) - subarraysNoLessThanK(nums, k + 1);
```

# 2.树
## 2.1 BST

### 1561 · BST节点距离 lintcode
建树,然后用father[i]去判断距离
## 2.2 一般树
### 94 · 二叉树中的最大路径和
```
int singlePathSum(TreeNode* root)
{
	if(root == nullptr)
		return 0;      
	int left = max(singlePathSum(root->left), 0);
	int right = max(singlePathSum(root->right), 0);
	ans = max(ans, left + right + root->val);
	return max(left, right) + root->val;
}
```
### 651 · 二叉树垂直遍历
先把right 和 left 找出来
```
vector<vector<int>> ans(right + left + 1);
queue<pair<TreeNode*, int>> que;
que.push(make_pair(root, left));
while(!que.empty())
{
    pair<TreeNode*, int> cur = que.front();
    que.pop();
    ans[cur.second].push_back(cur.first->val);
    if(cur.first->left)
        que.push(make_pair(cur.first->left, cur.second - 1));
    if(cur.first->right)
        que.push(make_pair(cur.first->right, cur.second + 1));

}
```
# 3.分治
## 3.1
### 1261 · 字符至少出现K次的最长子串 lintcode

### 53. 最大子数组和
```
kindOfSum get(vector<int>& nums, int left, int right)
{
    if(left == right)
        return {nums[left], nums[left], nums[left], nums[left]};

    int split = (left + right) >> 1;
    kindOfSum lsum = get(nums, left, split);
    kindOfSum rsum = get(nums, split + 1, right);

    return accumulate(lsum, rsum);
}
kindOfSum accumulate(kindOfSum lsum, kindOfSum rsum)
{
    return { lsum.allSum + rsum.allSum,
            max(lsum.leftSum, lsum.allSum + rsum.leftSum),
            max(rsum.rightSum, rsum.allSum + lsum.rightSum),
            max({lsum.conSum, rsum.conSum, lsum.rightSum + rsum.leftSum})
    };
}
```
### 23. 合并K个升序链表
```
ListNode* merge(vector<ListNode*>& lists, int left, int right)
{
    if(left == right)
        return lists[left];
    int mid = (right - left) / 2 + left;

    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
}
```

## 3.2 归并排序模板
### 剑指 Offer 51. 数组中的逆序对

# 4.链表
## 4.1 单链表
### 102 · 带环链表
快慢指针是否相遇

### 23. 合并K个升序链表
```
ListNode* merge(vector<ListNode*>& lists, int left, int right)
{
    if(left == right)
        return lists[left];
    int mid = (right - left) / 2 + left;

    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
}
```
## 4.2 循环链表
### offer2·29 · 排序的循环链表插入
```
//先判断head是否为空
p = head->next;
while(p != head)
if(p->val <= insertVal && insertVal <= p->next->val) break;
if(p->val > p->next->val && (insertVal >= p->val || insertVal <= p->next->val)) break;
//否则就插在最后一个节点后
```

# 5.动态规划

## 5.1 记忆化DFS
### 1259 · 整数替换 lintcode
偶数/2，奇数+1或者-1，到达1的最小步数。BFS或者DFS+DP记忆化

### 576 · 出界的路径数
```
记忆化DFS 自顶向下
if(curRow < 0 || curRow >= m || curColumn < 0 || curColumn >= n)
    return 1;
if(curMove == 0)
    return 0;
if(dp[curRow][curColumn][curMove] != -1)
    return dp[curRow][curColumn][curMove];
或者 
直接DP 从小到大
由步数小到大DP，不过会有一些无用的信息。
```

### 535 · 打劫房屋 III
```
int val = p->val;
if(p->left)
	val += dfs(p->left->left) + dfs(p->left->right);
if(p->right)
	val += dfs(p->right->left) + dfs(p->right->right);
return memo[p] = max(val, dfs(p->left) + dfs(p->right));
```
## 5.2 数学动态规划
### 982 · 等差切片
```
if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
{
    dp[i] = dp[i - 1] + 1;
    ans += dp[i];
}
```
### 76 · 最长上升子序列
```
dp[i] = 1;
for(int j = 1; j < i; ++j)
{
	if(nums[i - 1] > nums[j - 1])
		dp[i] = max(dp[i], dp[j] + 1);
	ans = max(ans, dp[i]);
}
```
### 1322 · 乘积为B 困难
```
//arr中的乘积为B所需的最小步数，一步可以是++arr[i] --arr[i]
//dp[i][j] 前i个数中，到factor[i]的最小步数
if(i == 0)
{
	dp[0][j] = abs(a[i] - factor[j]);
	continue;
}
for(int k = 0; k <= j; ++k)
{
	if(factor[j] % factor[k] == 0)
	{
	dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - factor[j] / factor[k]));
	}
}
```

### 984 · 等差切片 II - 子序列
```
for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < i; ++j)
    {
        long long diff = 1ll * a[i] - a[j];
        auto it = dp[j].find(diff);
        int cnt = 0;
        if(it == dp[j].end())
            cnt = 0;
        else
            cnt = dp[j][diff];

        ans += cnt;
        dp[i][diff] += cnt + 1;
    }
}
```
## 5.3 一般动态规划
### 392 · 打劫房屋
```
dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
或者
// 如果不抢第 i 个，取前 i - 1 个位置 dp 较大值
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
// 如果抢第 i 个，前一个不抢，考虑从前 i - 2 个位置的dp值转移
dp[i][1] = A[i] + dp[i - 1][0];
```

### 309. 最佳买卖股票时机含冷冻期
```
dp[0][0] = -prices[0];
for(int i = 1; i < n; ++i)
{
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][2] = dp[i - 1][0] + prices[i];
}
```

### 151 · 买卖股票的最佳时机 III
1.状态转移
```
int b1 = -prices[0];
int b2 = -prices[0];
int s1 = 0;
int s2 = 0;


for(int i = 1; i < n; ++i)
{
	b1 = max(b1, -prices[i]);
	s1 = max(s1, b1 + prices[i]);
	b2 = max(b2, s1 - prices[i]);
	s2 = max(s2, b2 + prices[i]);
}
```
2.可以操作两次
分成两部分
pre[k] 是 [0,k]
suf[k] 是 [k, n - 1]
ans = max(ans, pre[i] + suf[i])

### 188. 买卖股票的最佳时机 IV
```
for(int i = 0; i < k; ++i)
	buy[i] = -prices[0];

for(int i = 1; i < n; ++i)
{
	buy[0] = max(buy[0], -prices[i]);
	sell[0] = max(sell[0], buy[0] + prices[i]);
	for(int j = 1; j < k; ++j)
	{
		buy[j] = max(buy[j], sell[j - 1] - prices[i]);
		sell[j] = max(sell[j], buy[j] + prices[i]);
	}
}
```

### 125 · 背包问题（二）
```
if(w[i] <= j)
	dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);	
else
	dp[i + 1][j] = dp[i][j];
```

### 515 · 房屋染色
```
dp[i + 1][0] = costs[i][0] + min(dp[i][1], dp[i][2]);
dp[i + 1][1] = costs[i][1] + min(dp[i][0], dp[i][2]);
dp[i + 1][2] = costs[i][2] + min(dp[i][1], dp[i][0]);

return min({dp[n][0], dp[n][1], dp[n][2]});
```

### 1147 · 工作安排
```
dp[i + 1][0] = max({dp[i][0], dp[i][1], dp[i][2]}) + low[i];
dp[i + 1][1] = dp[i][2] + high[i];
dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]});
```
### 512 · 解码方法
```
for(int i = 2; i < n; ++i)
{
    int num1 = s[i] - '0';
    int num2 = (s[i - 1] - '0') * 10 + s[i] - '0';
    dp[i] = 0;
    if(num1 >= 1 && num1 <= 9)
        dp[i] += dp[i - 1];
    if(num2 >= 10 && num2 <= 26)
        dp[i] += dp[i - 2];
}
```

### 32. 最长有效括号
```
for(int i = 1; i < n; ++i)
{
	if(s[i] == ')')
	{
		if(s[i - 1] == '(')
		{
			dp[i + 1] = dp[i - 1] + 2;
		}
		else if(s[i - 1] == ')')
		{
			if(i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
			{
				dp[i + 1] = dp[i] + dp[i - dp[i] - 1] + 2;
			}
			
		}
	}
	ans = max(ans, dp[i + 1]);
}
```

### 629. K个逆序对数组
```
if(j < i)
    dp[i][j] = pre[i - 1][j];
else
    dp[i][j] = (pre[i - 1][j] - pre[i - 1][j - i] + MOD) % MOD;
if(j != 0)
    pre[i][j] = (pre[i][j - 1] + dp[i][j]) % MOD;
else
    pre[i][j] = dp[i][j];
```

### 1251 · 拆分子数组
```
dp[0][0] = 0;
for(int i = 1; i <= n; ++i)
{
	for(int j = 1; j <= min(i, m); ++j)
	{
		for(int k = 0; k < i; ++k)
		{
			dp[i][j] = min(dp[i][j] ,max(dp[k][j - 1], pre[i] - pre[k]));;
		}
	}
}
```

### 322. 零钱兑换
```
for(int i = 1; i <= amount; ++i)
{
	for(int coin : coins)
	{
		if(i - coin >= 0)
		{
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
}
```
## 5.3 区间DP
### 476 · 石子归并
```
//题意类似哈夫曼树 不过只有相邻的石子能够合并
for(int length = 2; length <= n; ++length)
{
    for(int start = 0; start + length - 1 < n; ++start)
    {
        int end = start + length - 1;
        for(int splice = start; splice < end; ++splice)
        {
            dp[start][end] = min(dp[start][end], dp[start][splice]  + dp[splice + 1][end] +
                                                    pre_sum[end] - pre_sum[start] + a[start]);
        }
    }
}
```

### 312. 戳气球
```
for(int length = 1; length <= n; ++length)
{
    for(int start = 1; start + length - 1 <= n; ++start)
    {
        int end = start + length - 1;
        for(int split = start; split <= end; ++split)
        {
            int sum = nums[split] * nums[start - 1] * nums[end + 1];
            dp[start][end] = max(dp[start][end], sum + dp[start][split - 1] + dp[split + 1][end]);
        }
    }
}
```

## 5.4 路径DP
### 1711 · 下降路径最小和
```
for(int i = 1; i < m; ++i)
{
    for(int j = 0; j < n; ++j)
    {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
        if(j != 0)
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
        if(j != n - 1)
            dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
    }
}
```

## 状态压缩DP
### 1891 · 旅行计划
```
dp[0][1] = 0;
for(int S = 1; S < S_size; ++S)
{
    for(int i = 0; i < n; ++i)
    {
        if(S & (1 << i))
        {
            for (int j = 0; j < n; ++j)
            {
                if(!(S & (1 << j)))
                {
                    dp[j][S | (1 << j)] = min(dp[j][S | (1 << j)], dp[i][S] + arr[i][j]);
                }
            }
        }
    }
}
```

### 1827 · 停在原地的方案数2
```
for(int i = 1; i <= steps; ++i)
{
    for(int j = 0; j < n; ++j)
    {
        dp[i][j] = dp[i - 1][j];
        if(j > 0)
            dp[i][j] += dp[i - 1][j - 1];
        if(j < n - 1)
            dp[i][j] += dp[i - 1][j + 1];

        dp[i][j] %= MOD;
    }  
}
```

## 字符串DP
### 10. 正则表达式匹配
```
dp[0][0] = true;
for(int j = 0; j < n; ++j)
    if(j >= 1 && p[j] == '*')
        dp[0][j + 1] = dp[0][j - 1];

for(int i = 0; i < m; ++i)
{
    for(int j = 0; j < n; ++j)
    {
        if(s[i] == p[j] || p[j] == '.')
        {
            dp[i + 1][j + 1] = dp[i][j];
        }
        else if(p[j] == '*')
        {
            bool flag;
            if(j > 0 && (p[j - 1] == s[i] || p[j - 1] == '.'))
                flag = dp[i][j + 1];
            else
                flag = false;
            dp[i + 1][j + 1] = flag || dp[i + 1][j - 1]; //|| dp[i + 1][j];
        }
        else
        {
            dp[i + 1][j + 1] = false;
        }
        cout<<i + 1<<" "<<j + 1<<" "<<dp[i + 1][j + 1]<<endl;
    }
}
```
### 139.单词拆分
先逆序word
```
for(int i = 1; i <= n; ++i)
{
    string cur;
    for(int j = i - 1; j >= 0; --j)
    {
        cur.push_back(s[j]);
        if(dp[j] && memo.count(cur))
        {
            dp[i] = true;
            break;
        }
    }
}
```

# 6.二分查找
## 6.1
### 964 · 食物集合
题目简介
两堆食物，每种食物有两种属性，分别从一堆中选中一种。
使得 美食度>T的情况下，热度最小。
对堆B按照美食度递增排序。再维护一个min_heat热度递减序列，由后向前生成。
对堆A的每个食物，二分查找B的index，再加上min_heat[index]

### 76 · 最长上升子序列
维护一个最长上升子序列，每增加一个数，就二分查找它的位置。
最后返回它的长度。
1，3，2，5，1，6
1
1，3
1，2
1，2，5
1，1，5
1，1，5，6
找到第一个大于等于num的数

### 617 · 子数组的最大平均值 II
大于等于K的子数组中最大平均值
在最大值和最小值之前二分 eps 1e-5
check函数O(n)，判断结果是否合法。
具体地，前缀和且需要减去ave。
则pre_sum[i] - minn > 0返回真。
其中minn = pre_sum[j]  0<=j<=i - k + 1

### 1219 · 加热器
一堆房子 一堆加热器 最小发热半径
对加热器排序 二分查找每个房子 取房子旁边两个加热器的最小值
最后取满足每个房子的最大值。

### 4. 寻找两个正序数组的中位数
```
while(1)
{
    if(index1 == m)
        return nums2[index2 + k - 1];
    if(index2 == n)
        return nums1[index1 + k - 1];
    if(k == 1)
        return min(nums1[index1], nums2[index2]);

    int new_index1 = min(index1 + k / 2 - 1, m - 1);
    int new_index2 = min(index2 + k / 2 - 1, n - 1);
    if(nums1[new_index1] < nums2[new_index2])
    {
        k -= new_index1 - index1 + 1;
        index1 = new_index1 + 1;
    }
    else
    {
        k -= new_index2 - index2 + 1;
        index2 = new_index2 + 1;
    }
}
```

### 1251 · 拆分子数组
给定一个由非负整数组成的数组和一个整数 m，我们要把数组拆分为 m 个非空连续子数组，使得这 m 个数组和的最大值在所有拆分方案中最小。
```
bool check(vector<int>& nums, int m, long long mid)
{
	int cnt = 1;
	long long sum = 0;

	for(int num : nums)
	{
		sum += num;
		if(sum > mid)
		{
			++cnt;
			if(cnt > m)
				return false;
			sum = num;
		}
	}
	return true;
}
```

# 7.排序相关
## 7.1
### 544 · 前K大数
```
while(left < right)
{
	while(left < right && arr[right] <= arr[start])
        --right;
    while(left < right && arr[left] >= arr[start])
		++left;
    swap(arr[left], arr[right]);
}
swap(arr[left], arr[start]);
```



# 8.设计题
## 8.1
### 545 · 前K大数 II
维护一个大小为K  红黑树或者小根堆

### 526 · 负载均衡器
add() remove() rand_pick()都是O(1)
一个vector存储数据
一个unordered_map记录下标 
删除时与最后一个元素交换 这样remove可以达到O(1)

### 134 · LRU缓存策略



# 9.深度优先搜索
## 9.1
### 18 · 子集 II
```
if(i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])
	continue;
```
### 因数分解
```
for(int i = bigger_factor; i <= max_factor; ++i)
{
    if(n % i == 0)
    {
        ret.push_back(i);
        dfs(ans, ret, i, n / i);
        ret.pop_back();
    }
}
```

# 10.贪心
## 10.1
### 391 · 数飞机 时间区间
```
找出重叠最多的时间段
开始时间，和结束时间都加入arr 再排序
遇到开始时间+1，结束时间-1 即可
```

### 406. 根据身高重建队列
```
//身高递减 名次递增
sort(people.begin(), people.end(), cmp);

vector<vector<int>> ans;
for(auto& v : people)
{
	ans.insert(ans.begin() + v[1], std::move(v));
}
```
# 11.博弈论
## 11.1
### 394 · 硬币排成线
有 n 个不同价值的硬币排成一条线。两个参赛者轮流从 左边 依次拿走 1 或 2 个硬币，直到没有硬币为止。计算两个人分别拿到的硬币总价值，价值高的人获胜。
```
	return (n % 3) != 0;
```

### 395 · 硬币排成线 II
有 n 个不同价值的硬币排成一条线。两个参赛者轮流从 左边 依次拿走 1 或 2 个硬币，直到没有硬币为止。计算两个人分别拿到的硬币总价值，价值高的人获胜。
```
//从后往前dp，模拟决策过程
//offensive 表现先手获得的价值
//dp[i] 表示后手获得的价值
offensive = max(dp[i + 1] + values[i], dp[i + 2] + values[i] + values[i + 1]);
sum += values[i];
dp[i] = sum - offensive;
```

# 12.栈
## 12.1单调栈
### 1852 · 最终优惠价
```
for(int i = n - 1; i >= 0; --i)
{
    while(!sta.empty() && sta.top() > prices[i])
    {
        sta.pop();
    }
    int k = prices[i];
    if(!sta.empty())
        k = k - sta.top();
    ans[i] = k;
    sta.push(prices[i]);
}
```

## 普通栈
### 32. 最长有效括号
```
sta.push(-1);
for(int i = 0; i < n; ++i)
{
    if(s[i] == ')')
    {
        sta.pop();
        if(sta.empty())
            sta.push(i);
        else
            ans = max(ans, i - sta.top());
    }
    else // s[i] == '('
    {
        sta.push(i);
    }
}
```
### 394. 字符串解码
```
for(char c : str)
{
    if(isalpha(c))
        tmp.push_back(c);
    else if(isdigit(c))
        num = 10 * num + c - '0';
    else if(c == '[')
    {
        if(num == 0)
            num = 1;
        staInt.push(num);
        staString.push(tmp);
        num = 0;
        tmp = "";
    }
    else
    {
        int num = staInt.top();
        staInt.pop();
        string pre = staString.top();
        staString.pop();
        string kk;
        while(num--)
            kk += tmp;
        tmp = pre + kk;
    }
}
```
# 13.其他
## 13.1 前缀和+hash
### 1844 · 子数组和为K II
没有负数的话 直接滑动窗口
有负数 用 前缀和+hash

## 13.2 前缀和+划分+dp
### 1850 · 捡苹果
不难 就是麻烦
一个数组，A需要连续捡m个，B需要连续捡n个。
两个人捡的不重合，求最大值。

## 13.3 线段树
### 840 · 可变范围求和

### 315. 计算右侧小于当前元素的个数
先离散化ranked，再上线段树

## 13.4 差分数组
### 2381. 字母移位 II
```
for(auto& shift : shifts)
{
    int add = 2 * shift[2] - 1;
    diff[shift[0]] += add;
    diff[shift[1] + 1] -= add;
}
```

# 14.宽度优先搜索
## 14.1
### 1832 · 最小步数
从第一格移动到最后一格所需要的步数。
1. i + 1 
2. i - 1
3. 颜色相同。
注意记录同种颜色的vector只遍历一遍。  

### 1565 · 飞行棋 I
从第一格移动到最后一格所需要的步数。
1. 前进 1，2，3，4，5，6 步 代价 + 1
2. 直接跳跃                           没有代价

外部bfs
内部bfs或者dfs

# 15.TRICK
## 15.1
### 1310 · 数组除了自身的乘积
不使用除法，O(n), 你可以用常数空间复杂度来解决这个问题吗？（注意：出于空间复杂度分析的目的，输出数组不算作额外空间。
```
int cur = 1;
for(int i = 1; i < n; ++i)
{
    cur *= nums[i - 1];
    arr[i] = cur;
}
cur = 1;
for(int i = n - 2; i >= 0; --i)
{
    cur *= nums[i + 1];
    arr[i] = arr[i] * cur;
}
```

### 2380. 二进制字符串重新安排顺序需要的时间
```
for(int i = 0; i < slen; ++i)
{
    if(s[i] == '0')
        ++cnt0;
    else if(cnt0 > 0)
        ans = max(ans + 1, cnt0);
}
```

### 287. 寻找重复数
```
int slow = 0;
int fast = 0;

while(1){
    slow = nums[slow];
    fast = nums[nums[fast]];
    if(slow == fast)
        break;
}

slow = 0;
while(1) {
    slow = nums[slow];
    fast = nums[fast];
    if(slow == fast)
        return fast;
}
```

# 16.图相关
## 16.1
### 178 · 图是否是树
```
int edges_num = edges.size();
if(edges_num != n - 1)
	return false;
return check_connected(n, edges);
```