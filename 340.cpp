#include<bits/stdc++.h>
using namespace std;
int main(){
	int y,s,i;
	cin>>y>>s>>i;
	if(y+s+i>270){
		cout<<"����ѧ��"<<endl;
	}
	if(y+s+i>240&&y+s+i<270){
		cout<<"����ѧϰ���"<<endl;
	}else{
		cout<<"ʲô��������"<<endl;
	}
	
	return 0;
}
