/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
 */
 int Solution::evalRPN(vector<string> &A) {
    if( A.size() == 0) return 0;
    stack<int> st;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int operand1 = 0;
            int operand2 = 0;
            if(!st.empty()){
                operand2 = st.top();
                st.pop();
            }
            if(!st.empty()){
                operand1 = st.top();
                st.pop();
            }
            
            int res = 0;
            if(A[i] == "+"){
                res = operand1 + operand2;
            } else if(A[i] == "-"){
                res = operand1 - operand2;
            } else if(A[i] == "*"){
                res = operand1*operand2;
            } else if(A[i] == "/"){
                res = operand1/operand2;
            }
            st.push(res);
        } else {
            st.push(stoi(A[i]));
        }
    }
    
    return st.top();
}
