// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <bits/stdc++.h>
using namespace std;

int ans,x,y,pre,T,n;
string str;
map<pair<int,char>,int> mem;

void refresh(){
    ans=INT_MAX;
    mem.clear();
}

int checkCost(char a,char b){
    if(a==b)    return 0;
    if(a=='C' and b=='J')   return x;
    return y;
}

int dp(int ind,char pre,int cost){
    if(ind==n){
        ans=min(ans,cost);
        return cost;
    }
    
    if(mem.find({ind,pre})!=mem.end()){
        ans=min(ans,mem[{ind,pre}]+cost);
        return mem[{ind,pre}]+cost;
    }
    
    int p=INT_MAX;
    if(str[ind]=='?'){
        p=min(p,dp(ind+1,'C',cost+checkCost(pre,'C')));
        p=min(p,dp(ind+1,'J',cost+checkCost(pre,'J')));
    }
    else
        p=min(p,dp(ind+1,str[ind],cost+checkCost(pre,str[ind])));
    
    
    mem[{ind,pre}]=p-cost;
    
    return p;
}

void findSol(){
    if(str[0]=='?'){
        dp(1,'C',0);
        dp(1,'J',0);
    }
    else    dp(1,str[0],0);
}

int main() {
	cin>>T;
	for(int t=1;t<=T;t++){
	    refresh();
	    cin>>x>>y>>str;
	    n=str.length();
	    findSol();
	    cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
