#include "iostream"
#include "string"
#include "fstream"
#include "stack"
using namespace std;
bool delimitersOK(const string &expression)
{
    stack<char>delimiterStack;
    for (char ch:expression)
    {
        if(ch=='(' || ch=='[' || ch=='{')
        {
            delimiterStack.push(ch);
        }
        else if(ch==')' || ch==']' || ch=='}')
        {
            if (delimiterStack.empty() || (ch==')' && delimiterStack.top()!='(')|| (ch== ']'&& delimiterStack.top() != '[' ) || (ch=='}' && delimiterStack.top() !='{')) 
          {
            return false;
          }  
          else
          {
            delimiterStack.pop();
          }

        }
    }
    return delimiterStack.empty();
}
int main()
{
    ifstream inputmyFile ("inputmy.txt");
    if(!inputmyFile.is_open())
    {
        cerr <<"file creation failed"<< endl;
        return 1;
    }
    int nExpression;
    inputmyFile>>nExpression;
    // cout<<nExpression<<endl;
    inputmyFile.ignore();
    for(int i=0; i<nExpression; i++)
    {
        string e;
        getline(inputmyFile,e);
        
            if(delimitersOK(e))
            {
                cout<<"valid"<<endl;
            }
            else
            {
                cout<<"invalid"<<endl;
            }
        
    }
    inputmyFile.close();
    return 0;
}