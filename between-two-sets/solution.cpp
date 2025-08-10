//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return  b==0 ? a : gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int main() {
    vector<int> a{2,4};
    vector<int> b{16,32,96};
    int lcmA = a[0];
    for(int i=1;i<a.size();i++){
    	lcmA = lcm(lcmA,a[i]);
    }
    int gcdB = b[0];
    for(int j=1;j<b.size();j++){
    	gcdB = gcd(gcdB,b[j]);
    }
    int cnt = 0;
    for(int i=lcmA;i<=gcdB;i+=lcmA){
    	if(gcdB%i==0){
    		cnt++;
    	}
    }
    cout<<cnt;
    return 0;
}