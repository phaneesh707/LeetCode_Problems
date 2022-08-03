class MyCalendar {
public:
    vector<pair<int,int>> a;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:a){
            if((start>=it.first && start<it.second )|| (end>it.first && end<=it.second)  || (start<it.first && end>it.second))
                return false;
        }
        a.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */