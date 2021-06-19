#include <iostream>
using namespace std;
#include<map>
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
#define iminHeap priority_queue<ll,vector<ll>,greater<ll>>
#define imaxHeap priority_queue<ll>
#define iMap map<ll,ll> 
#define iuMap unordered_map<ll, ll>
#define piMap map<pair<ll,ll>,ll> 

#define sz(a) a.size()
#define tc(t) ll t; cin>>t; while(t--)
#define debArr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";  cout<<endl; 
#define si cout<<"YES"<<endl;
#define nada cout<<"NO"<<endl;
// ll upperBound(ll a[],ll n,ll val) {return upper_bound(a,a+n,val)-a;}
// ll lowerBound(ll a[],ll n,ll val) {return lower_bound(a,a+n,val)-a;}
// bool persqr(int a) { return (int(sqrt(a))*int(sqrt(a))==a)?1:0; }
int gcd(int a,int b) { return (a?gcd(b%a,a):b);}
// bool powerOf2(int a)   {   return !(a&(a-1));}
ll abs(ll n1,ll n2){    return n1>n2?n1-n2:n2-n1;}
// ll highestPowerof2(ll n) { return pow(2,(ll)log2(n)); }

ll t,n,k,W,L[MAX6],H[MAX6],AL,BL,CL,DL,AH,BH,CH,DH,prevpos,ans,peri,length,height,MOD=1000000007;
iMap h,tot;

ll calc(){
    REP(i,k,n)  L[i]=(((AL*L[i-2])%DL + (BL*L[i-1])%DL + CL)%DL)+1;
    REP(i,k,n)  H[i]=(((AH*H[i-2])%DH + (BH*H[i-1])%DH + CH)%DH)+1;
    return 0;
}

ll calcparam(ll ind1,ll ind2){
    
    REP(i,L[ind1],L[ind1]+W+1)  tot[i]=h[i]=H[ind1];
    
    REP(i,ind1,ind2+1){
        length = L[i]-L[ind1]+W;
        
        ll j=L[i]+W;
        while(j>L[i] and h[j]<H[i]){
            h[j]=H[i];
            j--;
        }
        height=(tot[j]+labs(h[j]-H[i])+H[i])%MOD;   
        if(h[j]<H[i])   h[j]=H[i];
        j++;
        while(j<=(L[i]+W)){
            tot[j]=(height-H[i]+MOD)%MOD;
            j++;
        }
        ans=(ans*(((2*length)%MOD+(height+peri)%MOD)%MOD))%MOD;
    }
    peri = ((2*length)%MOD+(height+peri)%MOD)%MOD;
    return 0;
}

int main(){
    help;
    cin>>t;
    REP(cnt,1,t+1){
        ans=1;
        peri=0;
        h.clear();
        tot.clear();
        cin>>n>>k>>W;
        REP(i,0,k)  cin>>L[i];
        cin>>AL>>BL>>CL>>DL;
        REP(i,0,k)  cin>>H[i];
        cin>>AH>>BH>>CH>>DH;
        calc();
        // debArr(L,n);
        // debArr(H,n);
        prevpos=-1;
        ll ip=0;
        while(ip<n){
            if(prevpos==-1) prevpos=ip;
            ip++;
            while(ip<n and L[ip]<=L[ip-1]+W)   ip++;
            calcparam(prevpos,ip-1);
            prevpos=-1;
        }

        cout<<"Case #"<<cnt<<": "<<ans<<endl;
    }
    return 0;
}
