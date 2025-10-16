class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it:asteroids){
            bool alive=true;
            while(alive && !st.empty() && it<0 && st.top()>0){
                if(abs(it)==st.top()){
                    st.pop();
                    alive=false;
                }
                else if(abs(it)>st.top()){
                  st.pop();
                }
                else {
                    alive=false;
                }
            }
            if(alive && it<0)  st.push(it);
            if(it>0) st.push(it);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};