class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return NULL;
        if (needle[0] =='\0') return haystack;        
        vector<int> next;
        CalculateNext(needle, next);        
        int k = -1;        
        for (int i = 0; haystack[i] != '\0'; i++) {
            for (; k != -1 && needle[k + 1] != haystack[i]; k = next[k]); 
            if (needle[k + 1] == haystack[i]) k++;
            if (needle[k + 1] == '\0')
                return haystack + i - strlen(needle) + 1;
        }
        return NULL;
    }
private:    
    void CalculateNext(const char *s, vector<int> &next) {        
        int k = -1;
        next.push_back(k);
        if (s[0] == '\0') return;
        for (int i = 1; s[i] != '\0'; i++) {
            for (; k != -1 && s[k + 1] != s[i]; k = next[k]); 
            if (s[k + 1] == s[i]) k++;
            next.push_back(k);                
        }
    }
};