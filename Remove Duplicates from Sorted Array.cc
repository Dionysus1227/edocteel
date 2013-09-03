class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0, j = 0;
        while (j < n) {
            A[i++] = A[j++];
            for (; i >= 1 && A[j] == A[i - 1] && j < n; j++);
        }
        return i;        
    }
};