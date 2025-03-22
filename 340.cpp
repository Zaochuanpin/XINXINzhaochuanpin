#include<bits/stdc++.h>
using namespace std;
int main(){
	int y,s,i;
	cin>>y>>s>>i;
	if(y+s+i>270){
		cout<<"三好学生"<<endl;
	}
	if(y+s+i>240&&y+s+i<270){
		cout<<"优秀学习标兵"<<endl;
	}else{
		cout<<"什么都评不上"<<endl;
	}
	
	return 0;
}
