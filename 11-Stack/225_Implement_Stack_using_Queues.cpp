/*
Implement the following operations of a stack using queues.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:
You must use only standard operations of a queue -- which means only push to
back, peek/pop from front, size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may
simulate a queue by using a list or deque (double-ended queue), as long as you
use only standard operations of a queue.

You may assume that all operations are valid (for example, no pop or top
operations will be called on an empty stack).
*/

class MyStack {
private:
    queue<int> q1, q2;
    queue<int> *data, *help;

public:
    /** Initialize your data structure here. */
    MyStack() {
        data = &q1;
        help = &q2;
    }

    /** Push element x onto stack. */
    void push(int x) {
        data->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = data->size();
        for (int i = 0; i < n - 1; ++i) {
            int temp = data->front();
            data->pop();
            help->push(temp);
        }
        int ans = data->front();
        data->pop();
        swap(data, help);
        return ans;
    }

    /** Get the top element. */
    int top() {
        int n = data->size();
        int ans;
        for (int i = 0; i < n; ++i) {
            ans = data->front();
            data->pop();
            help->push(ans);
        }
        swap(data, help);
        return ans;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
