class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if((tokens[i]!="+") && (tokens[i]!="-") && (tokens[i]!="*") && (tokens[i]!="/")){
                st.push(stoi(tokens[i]));
            }
            else if(st.size()>=2 && tokens[i]=="+"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2+t1);
            }
            else if(st.size()>=2 && tokens[i]=="-"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2-t1);
            }
            else if(st.size()>=2 && tokens[i]=="*"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2*t1);
            }
            else{
                if(st.size()>=2 && tokens[i]=="/"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2/t1);
            }
            }
        }
        return st.top();
    }
};
