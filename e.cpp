#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool del (char c) {
    return c == ' ';
}

bool ip (char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='%';
}

int pri (char op) {
    return
        op == '+' || op == '-' ? 1 :
        op == '*' || op == '/' || op == '%' ? 2 :
        -1;
}

void pro (vector<int> & st, char op) {
    int r = st.back();  st.pop_back();
    int l = st.back();  st.pop_back();
    switch (op) {
        case '+':  st.push_back (l + r);  break;
        case '-':  st.push_back (l - r);  break;
        case '*':  st.push_back (l * r);  break;
        case '/':  st.push_back (l / r);  break;
        case '%':  st.push_back (l % r);  break;
    }
}

int calc (string & s) {
    vector<int> st;
    vector<char> op;
    for (size_t i=0; i<s.length(); ++i)
        if (!del (s[i]))
            if (s[i] == '(')
                op.push_back ('(');
            else if (s[i] == ')') {
                while (op.back() != '(')
                    pro (st, op.back()),  op.pop_back();
                op.pop_back();
            }
            else if (ip (s[i])) {
                char curop = s[i];
                while (!op.empty() && pri(op.back()) >= pri(s[i]))
                    pro (st, op.back()),  op.pop_back();
                op.push_back (curop);
            }
            else {
                string oper;
                while (i < s.length() && isalnum (s[i]))
                    oper += s[i++];
                --i;
                if (isdigit (oper[0]))
                    st.push_back (atoi (oper.c_str()));
                else
                    st.push_back (oper[0]);
            }
    while (!op.empty())
        pro (st, op.back()),  op.pop_back();
    return st.back();
}

int main()
{
    string line;
    getline(cin, line);
    cout << calc(line) << endl;
}