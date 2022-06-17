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


















