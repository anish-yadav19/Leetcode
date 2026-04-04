class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string s:ops) {
            if(s != "C" && s != "D" && s != "+") {
                st.push(stoi(s));
            } else if(s == "+") {
                int temp1  = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1+temp2);
            } else if(s == "D") {
                int temp = st.top();
                st.push(2*temp);
            } else {
                st.pop();
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};