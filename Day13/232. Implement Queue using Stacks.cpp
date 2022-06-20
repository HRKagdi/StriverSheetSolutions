//https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
public:
    stack<int> s1,s2; int size; 
    MyQueue() {
        size=0;
    }
    
    void push(int x) {
        s1.push(x); size++; 
    }
    
    int pop() {
        if(size==0)return -1;
        while(s1.size()>1){
            s2.push(s1.top()); s1.pop();
        }
        int ans=s1.top(); s1.pop();
        while(s2.size()>0){
            s1.push(s2.top()); s2.pop();
        }
        size--;
        return ans;
    }
    
    int peek() {
        if(size==0)return -1;
        while(s1.size()>1){
            s2.push(s1.top()); s1.pop();
        }
        int ans=s1.top();
        while(s2.size()>0){
            s1.push(s2.top()); s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return (size==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
