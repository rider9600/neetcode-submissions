class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            mn=val;
            st.push(val);
        }else if(val<mn)
        {
            st.push(2LL*val-mn);
            mn=val;
        }else{
            st.push(val);
        }
    }
    
    void pop() {
     long long  t=st.top();
     st.pop();
     if(t<mn)
     {
        mn=2*mn-t;
     }        
    }
    
    int top() {
        long long t=st.top();
        return (t<mn)?mn:t;
    }
    
    int getMin() {
        return mn;
    }
};
