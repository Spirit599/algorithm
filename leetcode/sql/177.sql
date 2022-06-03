CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N := N - 1;
  RETURN (
    select distinct salary
    from Employee 
    order by salary desc
    limit N, 1
  );
END