 #include <bits/stdc++.h>
using namespace std;

void fileio()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}



bool ParenValid(string str) {

    stack<char> s;
    char x;

    for (int i = 0; i < str.length() ; ++i) {

        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
            s.push(str[i]);
            continue;
        }

        if(s.empty())
            return false;


        switch (str[i])
        {
            case ')':
                x=s.top();
                s.pop();
                if(x!='(')
                    return false;
                break;


            case '}':
                x=s.top();
                s.pop();
                if(x!='{')
                    return false;
                break;

            case ']':
                x=s.top();
                s.pop();
                if(x!='[')
                    return false;
                break;

        }

    }
    if(s.empty())
        return true;
    else
        return false;
}

int main() {
//  cout<<"GfG!";
    fileio();
//    int t;cin>>t;cout<<t;cerr<<t;

string str;
cin>>str;

if(ParenValid(str))
    cout<<"true"<<endl;
else
    cout<<"false";


    return 0;
}
