class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
       sort(asteroids.begin(),asteroids.end());
       int n =asteroids.size();
       long long weight = 1LL*mass;
       for(int i=0;i<n;i++){
         if(asteroids[i]> weight) return false;
          else {
             weight+=1LL*asteroids[i];
          }
       }
       return true;
        
        
    }
};