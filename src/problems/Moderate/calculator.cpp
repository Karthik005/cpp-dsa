#include <stack>
#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <string>

using namespace std;

const char INV = '~';
const unordered_map<char,int> OP_PREC {
    {'/', 4},
    {'*', 3},
    {'+', 2},
    {'-', 1}
};

float do_op(const float& a, const float& b, const char& op) {
    switch (op)
    {
    case '/':
        return b/a;
    case '*':
        return a*b;
    case '+':
        return a+b;
    case '-':
        return b-a;
    default:
        throw invalid_argument("Unknown operation:" + op);
    }
}

float get_num(const string& expr, int& start_ind) {
    int digit_ind = start_ind;
    while (digit_ind < expr.length() &&
        expr[digit_ind] >= '0' &&
        expr[digit_ind] <= '9') {
            digit_ind++;
    }
    float ret_val = stof(expr.substr(start_ind, digit_ind-start_ind));
    start_ind = digit_ind;
    return ret_val;
}

char check_get_op(const string& expr, int& start_ind) {
    if (start_ind >= expr.length()) return INV;
    return expr[start_ind++];
}

void do_stack_op(stack<float>& lit_stack, stack<char>& op_stack) {
    float lit1 = lit_stack.top(); lit_stack.pop();
    float lit2 = lit_stack.top(); lit_stack.pop();
    char op = op_stack.top(); op_stack.pop();
    lit_stack.push(do_op(lit1,lit2,op)); 
}

float evaluate(const string& expr) {
    stack<float> lit_stack;
    stack<char> op_stack;
    cout <<"Enters here" << endl;
    if(expr.length() == 0) throw invalid_argument("Empty expression");
    int start_ind = 0;
    lit_stack.push(get_num(expr, start_ind));
    char next_op = check_get_op(expr, start_ind);
    if 
        (next_op != INV) op_stack.push(next_op);
    else
        return lit_stack.top();

    lit_stack.push(get_num(expr, start_ind));
    next_op = check_get_op(expr, start_ind);

    while(!op_stack.empty()) {
        cout << op_stack.top()<<endl;
        if (next_op == INV) {
            do_stack_op(lit_stack, op_stack);
        } else {
            if(OP_PREC.at(next_op) > OP_PREC.at(op_stack.top())) {
                op_stack.push(next_op);
                lit_stack.push(get_num(expr, start_ind));
                next_op = check_get_op(expr, start_ind);
            } else {
                do_stack_op(lit_stack, op_stack);
                if (op_stack.empty()){
                    op_stack.push(next_op);
                    lit_stack.push(get_num(expr, start_ind));
                    next_op = check_get_op(expr, start_ind);
                }
            }
        }
    }

    return lit_stack.top();
}

int main() {
    cout << evaluate("2*3+5/6*3+15") << endl;
}