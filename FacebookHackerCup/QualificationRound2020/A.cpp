#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define NREP(i,a,b) for(int i=a;i>=b;i--)
#define clr(a) memset(a,0,sizeof a)
#define CLR(a,t) memset(a,t,sizeof a)
#define help ios::sync_with_stdio(0)
#define SORTV(a,n) sort(a.begin(),a.begin()+n)
#define SORTA(a,n) sort(a,a+n)
#define f first
#define ii second
#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef long double ld;
#define vip vector<pair<ll,ll>>
#define vv vector<vector<ll>>
#define vi vector<ll>
#define FORS(it,m) for(set<int>::iterator it=m.begin();it!=m.end();it++)
#define FORM(it,m) for(map<ll,ll>::iterator it=m.begin();it!=m.end();it++)
#define FORV(it,m) for(vector<ll>::iterator it=m.begin();it!=m.end();it++)
#define FORL(it,l) for(list<int> :: iterator it=l.begin();it!=l.end();it++)
#define MAX6 1000000
#define MAX5 100000
#define MAX4 10000
#define ipair pair<int,int> 
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define minHeap priority_queue<ipair,vector<ipair>,greater<ipair>>
#define maxHeap priority_queue<ipair>
#define iMap map<ipair,ll> 
#define piMap map<pair<ll,ll>,ll> 
#define MOD 998244353
#define iMax INT_MAX
#define llMax LONG_MAX
#define sz(a) a.size()
#define tc(t) ll t; cin>>t; while(t--)
#define debArr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";  cout<<endl; 
// bool persqr(int a) { return (int(sqrt(a))*int(sqrt(a))==a)?1:0; }
// int gcd(int a,int b) { return (a?gcd(b%a,a):b);}
// bool powerOf2(int a)   {   return !(a&(a-1));}
// ll abs(ll n1,ll n2){    return n1>n2?n1-n2:n2-n1;}
// ll highestPowerof2(ll n) { return pow(2,(ll)log2(n)); }

char ans[100][100],a[100],b[100];
ll n;

int main(){
    help;
    int cnt=0;
    tc(tt){
        cnt++;
        cin>>n;
        REP(i,0,n)  cin>>a[i];
        REP(i,0,n)  cin>>b[i];
        REP(i,0,n){
            REP(j,i,n){
                if(i==j)    ans[i][j]='Y';
                else if(b[i]=='N' or a[j]=='N')   ans[i][j]='N';
                else if(b[j-1]=='Y') ans[i][j]=ans[i][j-1];
                else ans[i][j]='N';
            }
            NREP(j,i-1,0){
                if(b[i]=='N' or a[j]=='N')   ans[i][j]='N';
                else if(b[j+1]=='Y') ans[i][j]=ans[i][j+1];
                else    ans[i][j]='N';
            }
        }
        cout<<"Case #"<<cnt<<": "<<endl;
        REP(i,0,n){
            REP(j,0,n)  cout<<ans[i][j];
            cout<<endl;
        }
    }
    return 0;
}
