class Solution {
public:
    string getPermutation(int n, int k) {                
        if (n == 0) return "1";
        string ans(n, '1');        
        int fact = 1;
        for (int i = 1; i < n; i++, fact *= i) {
            ans[i] = '1' + i;    		
        }		        
        k--;    fact /= n;                
        for (int i = 0; i < n - 1 && k > 0; i++) {
			char cur = ans[i + k / fact];			
			move(ans.begin() + i, ans.begin() + i + k / fact, ans.begin() + i +1);			
            ans[i] = cur;			
            k %= fact;            
            fact /= (n - i - 1);           
        }
        return ans;    
    }
};