select S1.score, count(distinct S2.score) as 'Rank'
from Scores S1
join Scores S2
on S1.score <= S2.score
group by S1.Id
order by `Rank`


SELECT 
Score ,
dense_rank() over (order by Score desc)  as 'Rank'
-- 不指定 partition by 相当于所有行数据一个 partition, 数据进行区内排序
-- dense_rank() 相当于每一行数据一个窗口, 对数据进行比较
FROM Scores;

-- 1.rank() over：排名相同的两名是并列，但是占两个名次，1 1 3 4 4 6这种
-- 2.dense_rank() over：排名相同的两名是并列，共占一个名词，1 1 2 3 3 4这种
-- 3.row_number() over这个函数不需要考虑是否并列，哪怕根据条件查询出来的数值相同也会进行连续排名 1 2 3 4 5
