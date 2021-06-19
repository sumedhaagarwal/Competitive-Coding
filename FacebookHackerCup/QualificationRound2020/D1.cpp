#include <iostream>
using namespace std;
#include <math.h>
#include<deque>
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
#define ipair pair<ll,ll> 
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
bool persqr(int a) { return (int(sqrt(a))*int(sqrt(a))==a)?1:0; }
int gcd(int a,int b) { return (a?gcd(b%a,a):b);}
bool powerOf2(int a)   {   return !(a&(a-1));}
ll abs(ll n1,ll n2){    return n1>n2?n1-n2:n2-n1;}
ll highestPowerof2(ll n) { return pow(2,(ll)log2(n)); }

deque<ipair> dq;
ll n,m,a[MAX6],ans,tot;
int main(){
    help;
    int cnt=0;
    tc(tt){
        ans=0;
        cnt++;
        cin>>n>>m;
        REP(i,0,n)  cin>>a[i];
        if(m>=n-1){
            cout<<"Case #"<<cnt<<": "<<ans<<endl;
            continue;
        }
        REP(i,0,m+1){
            if(a[i]==0) continue;
            while(!dq.empty() and dq.front().f>=a[i])    dq.pop_front();
            dq.push_front(mp(a[i],i));
        }
        REP(i,m+1,n){
            if(a[i]==0) continue;
            while(!dq.empty() and dq.back().ii<i-m) dq.pop_back();
            tot=a[i];
            if(!dq.empty())   tot+=dq.back().f;
            else if(dq.empty() and i>m)    {
                ans=-1;
                break;
            }
            while(!dq.empty() and dq.front().f>=tot)    dq.pop_front();
            dq.push_front(mp(tot,i));
            // for (std::deque<ipair>::iterator it = dq.begin(); it!=dq.end(); ++it)
            //     std::cout <<  " (" << (it->f)<<","<<(it->ii)<<")";
            // cout<<endl;
        }
        if(ans!=-1)  ans=dq.back().f;
        cout<<"Case #"<<cnt<<": "<<ans<<endl;
        while(!dq.empty())  dq.pop_front();
    }
    return 0;
}
