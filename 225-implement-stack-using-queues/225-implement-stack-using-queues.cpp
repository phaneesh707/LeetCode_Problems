class MyStack {
public:
    queue<int> a;
    queue<int> b;
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int popi = a.back();
        while(popi!=a.front()){
            b.push(a.front());
            a.pop();
        }
        a.pop();
        b.swap(a);
        return popi;
    }
    
    int top() {
        return a.back();
    }
    
    bool empty() {
        return a.empty();
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