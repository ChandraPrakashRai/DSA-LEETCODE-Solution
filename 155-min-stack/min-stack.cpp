#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {
        minStack.push(INT_MAX); 
    }
    
    void push(int val) {
        mainStack.push(val);
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};