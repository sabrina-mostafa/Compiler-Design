///  ~~~~~Bismillah'hir Rah'maanir Rahim~~~~~  ///

/*  "  Allah(SWT) blesses with knowledge whom he wants. "   */
/*  " Indeed with Hardship, comes Ease. "    */


///         Originator : Sabrina Mostafa
///         Dept. Of CSE
///         International Islamic University Chittagong


#include<bits/stdc++.h>
using namespace std ;

#define   FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   ULL               unsigned long long
#define   LL                  long long
#define   ST                  string
#define   F                    first
#define   S                    second
#define   PB                 push_back
#define   MP                make_pair
#define   pi                   acos(-1.0)
#define   NL                 "\n"
#define    _                    " "



bool isDelimiter(char ch)       // Seperator
{
    char c ;
    string Del = " ,;(){}[]" ;
    for(auto c : Del)
        if(ch==c)
            return true ;
    return false ;
}

bool isOperator(char ch)
{
    char c ;
    string Op = "+-*/=!<>&|" ;
    for(auto c : Op)
        if(ch==c)
            return true ;
    return false ;
}

bool isKeyword(string s)
{
    string keyword[] =
    {
        "auto", "else", "long", "switch", "break", "register",
        "typedef", "case", "return", "union",  "char", "float", "unsigned",
        "const", "for", "signed", "void", "continue", "goto", "sizeof",
        "default","if", "static", "while", "do", "int", "struct", "double"
    } ;

    for(int i=0; i<(sizeof(keyword)/sizeof(string)); i++)
        if(s==keyword[i])
            return true ;
    return false ;
}

bool isIdentifier(string s)
{
    bool valid = true ;

    if(isKeyword(s))
        valid = false ;
    if(valid)
    {
        if(s[0]>='0' && s[0]<='9')
            valid = false ;
    }
    if(valid)
    {
        for(int i=0; i<s.size(); i++)
        {
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')||
                    (s[i]>='0'&& s[i]<='9') || s[i] == '_')
                continue ;
            else
            {
                valid = false ;
                break ;
            }
        }
    }
    return valid ;
}

bool isNumber(string s)
{
    bool valid = true ;
    for(int i=0; i<s.size(); i++)
    {
        if( (s[i]>='0'&& s[i]<='9') || s[i]=='.')
            continue ;
        else
        {
            valid = false ;
            break ;
        }
    }
    return valid ;
}


void parse(string s)
{
    vector<string>tokens ;               // for storing all the tokens
    string tkn = "", st ;
    for(int i=0; i<s.size(); i++)
    {
        if( isDelimiter(s[i]) )
        {
            if(tkn != "")
                tokens.push_back(tkn) ;
            tkn = "" ;
        }
        else if( isOperator(s[i]) )
        {
            if(tkn != "")
            {
                tokens.push_back(tkn) ;
                tkn = "" ;
            }
            tkn += s[i] ;                               // pushing the operator
            tokens.push_back(tkn) ;
            tkn = "" ;
        }
        else
            tkn += s[i] ;          //  not seperator or operator
    }
    if(tkn != "")       // if no delimiter or operator is found nothing will be pushed previously
    {
        tokens.push_back(tkn) ;             // that's why pushing it now
        tkn = "" ;
    }

    for(auto st : tokens)
    {
        if(isKeyword(st))
            cout<<"Valid Keyword = \""<<st<<"\""<<endl ;
        else if(isIdentifier(st))
            cout<<"Valid Identifier = \""<<st<<"\""<<endl ;
        else if(isNumber(st))
            cout<<"Valid Number = \""<<st<<"\""<<endl ;
        else if(isOperator(st[0]))
            cout<<"Valid Operator = \""<<st[0]<<"\""<<endl ;
        else
            cout<<"Invalid Identifier = \""<<st<<"\""<<endl ;
    }
}



int main ()
{
    ifstream file ;
    string line, file_name ;
    getline(cin, file_name) ;
    file.open(file_name) ;

    cout<<"Tokens :\n" ;
    while(file)
    {
        getline(file, line) ;
        parse(line) ;
    }
    file.close() ;

    return 0 ;
}

/*
programe-Sample.c >>

int main()
{
int a, b, 8c, a_b, num$ ;
c = a+b+80.0 ;
return 0 ;
}

*/
