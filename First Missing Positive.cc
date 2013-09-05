class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++)
          for (; 1 <= A[i] && A[i] <= n && A[A[i] - 1] != A[i]; swap(A[A[i] -1], A[i]));
       int ans = 1;
       for (; ans <= n && A[ans - 1] == ans; ans++);
       return ans;
    }
};
