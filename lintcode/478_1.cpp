class Calculator {
public:
    /**
     * @param a: An integer
     * @param op: A character, +, -, *, /.
     * @param b: An integer
     * @return: The result
     */
    int calculate(int a, char op, int b) {
        
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else if(op == '*')
            return a * b;
        else if(op == '/')
            return a / b;
    }
};