class SmallestInfiniteSet {
private:
    int curr_smallest = 1;
    set<int> added_back;
public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if(!added_back.empty()){
            int smallest = *added_back.begin();
            added_back.erase(added_back.begin());
            return smallest;
        }
        return curr_smallest++;
    }
    
    void addBack(int num) {
        if(num < curr_smallest){
            added_back.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */