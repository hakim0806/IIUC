#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else {
        return -1;
    }
}
string Infix_to_Postfix(string s)
{
    stack<char> st;
    string postfix;
    for(int i = 0; i<s.size(); i++)
    {
        if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <='Z'))
        {
            postfix += s[i];
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while(!st.empty() && st.top() !='(')
            {
                postfix+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        postfix +=st.top();
        st.top();
    }
    return postfix;
}
int main()
{
    string s; 
    cin>>s;
    if(s[0] != '(')
    {
        s.insert(s.begin(),'(');
    }
    if(s[s.size()-1] != ')')
    {
        s.insert(s.end(),')');
    }
   cout<<s<<endl<<endl;
    cout<<Infix_to_Postfix(s)<<endl;
}