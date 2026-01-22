class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        // base cases
        if(n == 1) return arr[0];
        
        stack<int> st;
        st.push(0);
        int maxarea = 0;
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = arr[element]*(nse-pse-1);
                maxarea = max(maxarea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int area = arr[element]*(nse-pse-1);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> arr(cols, 0);

        int maxarea = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == '1'){
                    if(arr[j] == 0){
                        arr[j] = 1;
                    }
                    else{
                        arr[j]++;
                    }
                }
                else{
                    arr[j] = 0;
                }
            }
        maxarea = max(largestRectangleArea(arr), maxarea);
        }
        return maxarea;
    }
};