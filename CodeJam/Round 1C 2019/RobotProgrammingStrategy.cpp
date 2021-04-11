#include <bits/stdc++.h>
using namespace std;

int T,n,reqMoves,rock,paper,scissors;
vector<string> moves;
unordered_map<int,int> dead;
string str,ans;

void defeat(int ind, char C){
    for(int i=0;i<n;i++){
        // cout<<i<<" "<<moves[ind%moves[i].length()]<<endl;
        if(dead[i]!=1 and moves[i][ind%moves[i].length()]==C)   
            dead[i]=1;
    }
}

int findMove(int ind){
    rock=0;
    paper=0;
    scissors=0;
    for(int i=0;i<n;i++){
        if(dead[i]!=1){
            int moveIndex=ind%moves[i].length();
            // cout<<i<<" "<<moveIndex<<" "<<moves[i][moveIndex]<<endl;
            if(moves[i][moveIndex]=='R')  rock=1;
            if(moves[i][moveIndex]=='P')  paper=1;
            if(moves[i][moveIndex]=='S')  scissors=1;
        }
    }
    // cout<<rock<<" "<<paper<<" "<<scissors<<endl; 
    if(rock==1 and paper==1 and scissors==1)    return 0;
    else if(rock==1 and scissors==1){
        ans+='R';
        defeat(ind,'S');
    }
    else if(rock==1 and paper==1){
        ans+='P';
        defeat(ind,'R');
    }
    else if(paper==1 and scissors==1){
        ans+='S';
        defeat(ind,'P');
    }
    else if(rock==1){
        ans+='P';
        defeat(ind,'R');
    }
    else if(paper==1){
        ans+='S';
        defeat(ind,'P');
    }
    else if(scissors==1){
        ans+='R';
        defeat(ind,'S');
    }
    return 1;
}

int checkAllDead(){
    for(int i=0;i<n;i++){
        if(dead[i]==0)  return 0;
    }
    return 1;
}

int findSol(){
    int i=0;
    while(1){
        if(!findMove(i)) {
            ans="IMPOSSIBLE";
            return 0;
        }
        i++;
        if(checkAllDead()) return 0;
    }
   
}

void refresh(){
    dead.clear();
    reqMoves=0;
    ans.clear();
    moves.clear();
}

int main() {
	cin>>T;
	for(int t=1;t<=T;t++){
	    refresh();
	    cin>>n;
	    for(int i=0;i<n;i++)    {
	        cin>>str;
	        int sj=str.size();
	        moves.push_back(str);
	        reqMoves=max(reqMoves,sj);
	    }
	    findSol();
	    cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
