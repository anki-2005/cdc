class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
       vector<int>temp(n);
       for(auto &it:bank){
        int cnt=0;
         for(auto &i:it){
            if(i=='1') cnt++;
         }
         temp.push_back(cnt);
       } 
       int ans=0;
       stack<int>st;
       for(auto it:temp){
         if(st.empty()){
             st.push(it);
         }
         else if(it!=0){
            ans+=st.top()*it;
            st.push(it);
         }
       }
       return ans;
    }
};