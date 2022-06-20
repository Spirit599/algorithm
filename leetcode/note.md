# 1.滑动窗口
主要是对于一个状态，要有二维性。
要么向左，要么向右。
## 1.1
### 3. 无重复字符的最长子串 高频 medium
### 32 · 最小子串覆盖
source = "adobecodebanc"
target = "abc"
ans = "banc"

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
# 3.分治
## 3.1
### 1261 · 字符至少出现K次的最长子串 lintcode

# 4.链表
## 4.1 单链表
### 102 · 带环链表
快慢指针是否相遇
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

### 617 · 子数组的最大平均值 II
大于等于K的子数组中最大平均值
在最大值和最小值之前二分 eps 1e-5
check函数O(n)，判断结果是否合法。
具体地，前缀和且需要减去ave。
则pre_sum[i] - minn > 0返回真。
其中minn = pre_sum[j]  0<=j<=i - k + 1

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

# 9.深度优先搜索
## 9.1
### 18 · 子集 II
```
if(i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])
	continue;
```
