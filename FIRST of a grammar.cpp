///  ~~Bismillah'hir Rah'maanir Rahim~~  ///

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



map<char, string> mp ;
map<char, string> :: iterator it ;
vector<char>v, ans ;


void getFirst(char ch, string s1, int f)
{
    vector<char>v ;
    string s = mp[ch] ;
    char c ;

    v.PB(s[0]) ;                                         // storing the First symbols
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]=='|')
        {
            c = s[i+1] ;
            v.PB(c) ;
        }
    }

    for(int i=0; i<v.size(); i++)
    {
        c = v[i] ;
        if(isupper(c))                // non-terminal
        {
            f=1 ;                               //  derived from non-terminal marks true
            getFirst(c, s1, f) ;
        }
        else
        {
            if(f==1 && c=='#')              // here # = epsilon
            {
                c = s1[1] ;
                 ans.push_back(c) ;             // terminal & is not epsilon
            }
            else
            {
                ans.push_back(c) ;           // terminal
            }
        }
    }
}


int main ()
{
    int t, n, m, i, j, k, x, y, z, l, r, cnt=0 ;
    char ch, St ;
    string s, s1, s2 ;

    cout<<"How many Production rules?\n" ;
    cin>>n ;

    for(i=1; i<=n; i++)
    {
        cin>>St>>ch>>s ;
        mp[St] = s ;
    }
    while(1)
    {
        int f=0 ;
        cout<<"First of ?\n" ;
        cin>>St ;
        if(St=='0')             // end of query
                 break ;

        s = mp[St] ;
        getFirst(St, s, f) ;

        cout<<"{ " ;
        i=0 ;
        for(auto ch : ans)
        {
            i++ ;
            cout<<ch ;
            if(i<ans.size())
                cout<<", " ;
            else cout<<" " ;
        }

        cout<<"}\n" ;

        v.clear() ;
        ans.clear() ;
    }

    return 0 ;
}


/*
Input:
>> 5
E=GaT
G=+TG|#
T=FbU
U=*FU|#
F=id|(E)
*/
