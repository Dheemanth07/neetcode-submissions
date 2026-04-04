class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
        for(string &s:tokens){
            if(s=="+" || s== "-" || s=="*" || s=="/"){
                long first=st.top(); st.pop();
                long second=st.top();st.pop();
                if(s=="+") st.push(second+first);
                else if(s=="-") st.push(second-first);
                else if(s=="*") st.push(second*first);
                else if(s=="/") st.push(second/first);          
            }
            else
                st.push(stol(s)); 
        }
        return (int)st.top();
    }
};
