/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
*/
string Solution::simplifyPath(string A) {
    if(A.length() == 0) return "";
    stack<string> st;
    string res ="";
    string token;
    string s = A.substr(1);
    int len = s.length();
    int i = 0;
    while(i < len){
        token = "";
        while(i < len && s[i] != '/'){
            token += s[i];
            i++;
        }
        if(s[i] == '/') i++;
        if(token == ".") continue;
        if(token == ".."){
            if(!st.empty()){
                st.pop();
            }
            continue;
        }
        if(token[0] == ' ') continue;
        if(token == "") continue;
        
        st.push(token);
    }
    bool first = true;
    if(st.empty()) return "/";
    while(!st.empty()){
        string temp = st.top();
        reverse(temp.begin(),temp.end());
        res += temp;
        res += '/';
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
