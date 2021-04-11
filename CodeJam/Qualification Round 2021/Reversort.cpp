// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

#include <bits/stdc++.h>
using namespace std;

int T,n,pos,ans,x;
vector<int> a;

void refresh(){
    ans=0;
    a.clear();
}

int findSol(){
    for(int i=0;i<n-1;i++){
        pos=min_element(a.begin()+i,a.end())-a.begin();
        ans+=pos-i+1;
        reverse(a.begin()+i,a.begin()+pos+1);
    }
    return 0;
}


int main() {
	cin>>T;
	for(int t=1;t<=T;t++){
	    refresh();
	    cin>>n;
	    for(int i=0;i<n;i++)    {
	        cin>>x;
	        a.push_back(x);
	    }
	    findSol();
	    cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
