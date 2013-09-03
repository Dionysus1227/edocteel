class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while (i < n && j < n) {
            for (; j < n && A[j] == elem; j++);
            if (j == n) break;
            A[i++] = A[j++];
        }
        return i;
        
    }
};
