class MinStack {
    int min;
    vector<int> v;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = -1;
    }
    
    void push(int x) {
        v.push_back(x);
        if(min != -1){
            if(x < v[min])
                min = v.size()-1;
        }else{
            min = v.size()-1;
        }
    }
    
    void pop() {
        v.pop_back();
        if(min >= v.size()){
            if(v.size() == 0){
                min = -1;
            }else{
                int tmp_min = v[0], tmp_index = 0;
                for(int i = 1; i < v.size(); i++){
                    if(v[i] < tmp_min){
                        tmp_min = v[i];
                        tmp_index = i;
                    }
                }
                min = tmp_index;
            }
        }
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return v[min];
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