// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

0000000000134c90


#include <bits/stdc++.h>
using namespace std;

int T,n,num_rows,num_cols,trace,a[1000][1000];
map<int,int> m;

void refresh(){
    trace=0;
    num_rows=0;
    num_cols=0;
}

void findRow(){
    for(int i=0;i<n;i++){
        m.clear();
        for(int j=0;j<n;j++){
            if(m[a[i][j]]!=0){
                num_rows++;
                break;
            }
            m[a[i][j]]=1;
        }
    }
}

void findCol(){
    for(int i=0;i<n;i++){
        m.clear();
        for(int j=0;j<n;j++){
            if(m[a[j][i]]!=0){
                num_cols++;
                break;
            }
            m[a[j][i]]=1;
        }
    }
}


void findSol(){
    findRow();
    findCol();
}

int main() {
	cin>>T;
	for(int t=1;t<=T;t++){
	    refresh();
	    cin>>n;
	    for(int i=0;i<n;i++)    {
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	            if(i==j)    trace+=a[i][j];
	        }
	    }
	    findSol();
	    cout<<"Case #"<<t<<": "<<trace<<" "<<num_rows<<" "<<num_cols<<endl;
	} 
}
