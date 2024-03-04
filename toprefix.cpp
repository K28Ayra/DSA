#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class pr
{
private:
    string pref;
    string inf;
    stack<char> st;

    bool isOperator(char c)
    {
        return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
    }
    int prec(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;

        return 0;
    }

public:
    pr()
    {
        inf = "";
        pref = "";
    }

    void input()
    {
        cout << "enter infix=";
        cin >> inf;
    }

    string convert()
    {
        reverse(inf.begin(),inf.end());
        for (char c : inf)
        {
            if (isalnum(c))
            {
                pref += c;
                ;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    pref += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
            }
            else if (isOperator(c))
            {
                while (!st.empty() && prec(st.top()) > prec(c))
                {
                    pref += st.top();
                    st.pop();
                }
                st.push(c);
            }

          
        }
  while (!st.empty())
            {
                pref += st.top();
                st.pop();
            }

   reverse(pref.begin(),pref.end());
    return pref;
    }

void displaying(){

    cout<<"pref="<<pref;
  

}



};

int main()
{
pr ob;
ob.input();
ob.convert();
ob.displaying();


    return 0;
}