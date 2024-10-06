//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
   long long maximumProduct(int n, vector<int> &arr, int l, int r) {
        
    set<int> st, side;
    for (int i = l - 1; i < r; i++) {
        st.insert(arr[i]);
    }
    for (int i = 0; i < l - 1; i++) {
        side.insert(arr[i]);
    }
    for (int i = r; i < n; i++) {  
        side.insert(arr[i]);
    }

    

  
    long long a = *st.begin();
    long long b = *prev(st.end());
    long long c = *side.begin();
    long long d = *prev(side.end());

   
    long long ans = LLONG_MIN;  
    ans = max(ans, a * c);      
    ans = max(ans, a *d );      
    ans = max(ans, b * c);      
    ans = max(ans, b * d);     
    
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

        vector<int> arr(n);
        Array::input(arr, n);

        int l;
        scanf("%d", &l);

        int r;
        scanf("%d", &r);

        Solution obj;
        long long res = obj.maximumProduct(n, arr, l, r);

        cout << res << endl;
    }
}

// } Driver Code Ends