class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        int c=0;
        int i=1;
        while(i<intervals.size()){
            if(v[c][1]>=intervals[i][0]) {
                 v[c][1]=max(v[c][1],intervals[i][1]);
                i++;
            }
            else{
                v.push_back(intervals[i]);
                c++;
                i++;
            }
        }
        return v;
    }
};