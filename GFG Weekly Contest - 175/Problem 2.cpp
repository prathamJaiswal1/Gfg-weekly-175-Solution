//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> boundarySum(int n, vector<vector<int>> &m) {
        // code here
        vector<int>ans;
        int left=0,right=n-1,top=0,bottom=n-1;
        while(left<=right && top<=bottom){
            int sum=0;
            for(int i=left; i<=right; i++){
                sum+=m[top][i];
            }
           for(int i=top+1;i<=bottom;i++){
               sum+=m[i][right];
           }
           for(int i=right-1;i>=left;i--){
               sum+=m[bottom][i];
           }
           for(int i=bottom-1;i>top;i--){
               sum+=m[i][left];
           }
           left++;
           top++;
           right--;
           bottom--;
           ans.push_back(sum);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<vector<int>> matrix(n, vector<int>(n));
        Matrix::input(matrix, n, n);

        Solution obj;
        vector<int> res = obj.boundarySum(n, matrix);

        Array::print(res);
    }
}

// } Driver Code Ends