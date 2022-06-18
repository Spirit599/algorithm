# 滑动窗口

## 3. 无重复字符的最长子串 高频 medium

# 树

## 1561 · BST节点距离 lintcode

建树,然后用father[i]去判断距离

# 分治

## 1261 · 字符至少出现K次的最长子串 lintcode

# 链表

## offer2·29 · 排序的循环链表插入
```
//先判断head是否为空
p = head->next;
while(p != head)
if(p->val <= insertVal && insertVal <= p->next->val) break;
if(p->val > p->next->val && (insertVal >= p->val || insertVal <= p->next->val)) break;
//否则就插在最后一个节点后
```

# 动态规划

## 记忆化DFS
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
## 数学动态规划
### 982 · 等差切片
```
if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
{
    dp[i] = dp[i - 1] + 1;
    ans += dp[i];
}
```
## 一般动态规划
### 392 · 打劫房屋
```
dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
或者
// 如果不抢第 i 个，取前 i - 1 个位置 dp 较大值
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
// 如果抢第 i 个，前一个不抢，考虑从前 i - 2 个位置的dp值转移
dp[i][1] = A[i] + dp[i - 1][0];
```


# 二分查找
### 964 · 食物集合
题目简介
两堆食物，每种食物有两种属性，分别从一堆中选中一种。
使得 美食度>T的情况下，热度最小。
对堆B按照美食度递增排序。再维护一个min_heat热度递减序列，由后向前生成。
对堆A的每个食物，二分查找B的index，再加上min_heat[index]

# 排序相关
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




