// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <bits/stdc++.h>
using namespace std;

int ans,x,y,pre,T,n;
string str,word;
char a,b;

void refresh(){
    ans=0;
    word="";
}

void findSol(){
    for(int i=0;i<n;i++)
        if(str[i]!='?') word+=str[i];
    
    for(int i=1;i<word.length();i++){
        a=word[i-1];
        b=word[i];
        if(a=='C' and b=='J')   ans+=x;
        if(a=='J' and b=='C')   ans+=y;
    }
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
