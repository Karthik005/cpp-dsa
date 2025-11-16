#include <stack>
#include <iostream>

using namespace std;

void move_disc(stack<int>& one, stack<int>& two) {
    two.push(one.top());
    one.pop();
}

void move_ndiscs(stack<int> &start, stack<int> &mid, stack<int> &end, int cur_dsc);

void execute_toh(stack<int> &start, stack<int> &mid, stack<int> &end, int n)
{
    for (int i = 1; i <= n; ++i) {
        move_ndiscs(start, mid, end, i);
    }
}

void move_ndiscs(stack<int> &start, stack<int> &mid, stack<int> &end, int cur_dsc)
{
    if (cur_dsc == 0) return;
    else if (cur_dsc == 1) {
        move_disc(start, end);
        return;
    }
    move_disc(start, mid);
    execute_toh(end, mid, start, cur_dsc-1);
    move_disc(mid, end);
    execute_toh(start, mid, end, cur_dsc-1);

}

int main() {
    stack<int> start, mid, end;
    for (int i = 10; i >= 1; --i) {
        start.push(i);
    }
    execute_toh(start, mid, end, start.size());
    while(!end.empty()) {
        cout << end.top() <<" ";
        end.pop();
    }
    cout <<endl;
}