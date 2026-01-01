class Solution {
public:
    long long Mod = 1e9+7;
    void NextSmallerElement(vector<int>& arr, vector<int>& nse){
        int n = arr.size();
        stack<int> st;
        nse[n-1] = n;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void PreviousSmallerOrEqualElement(vector<int>& arr, vector<int>& pse){
        int n = arr.size();
        stack<int> st;
        pse[0] = -1;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, 0);
        vector<int> pse(n, 0);
        NextSmallerElement(arr, nse);
        PreviousSmallerOrEqualElement(arr, pse);

        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = nse[i]-i;
            long long right = i-pse[i];
            ans = (ans + (((left*right)%Mod) *1ll*arr[i])%Mod) %Mod;
        }
        return (int)ans;
    }
};