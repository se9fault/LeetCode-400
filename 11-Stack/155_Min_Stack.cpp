/*
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
private:
    stack<int> oriStack, minStack;

public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        oriStack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            int top = minStack.top();
            minStack.push(min(x, top));
        }
    }
    
    void pop() {
        oriStack.pop();
        minStack.pop();
    }
    
    int top() {
        return oriStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
