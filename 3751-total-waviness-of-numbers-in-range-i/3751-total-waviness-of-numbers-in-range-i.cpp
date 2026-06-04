class Solution {
public:
     
     int wavi(int k ){
        string s= to_string(k);
        int n=s.size();
        if(n<3) return 0;
        int peak=0;
        int valley=0;
        for(int i=1;i<n-1;i++){
            if(s[i-1] < s[i] && s[i]> s[i+1]) peak++;
            else if(s[i-1] > s[i] && s[i] < s[i+1] ) valley++;
        }
        return peak+valley;
    }
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int i=num1 ;i<=num2;i++){
            sum+=wavi(i);
        }
        return sum;
    }
};