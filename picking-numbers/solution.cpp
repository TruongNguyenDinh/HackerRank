//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
int pickingNumbers(vector<int> a) {
    sort(a.begin(),a.end());
    int i = 1;
    int maxAr = 0;
    while(i<a.size()){
        int currentAr =0;
        int pivot = a[i-1];
        while((a[i]-a[i-1])<=1 && a[i]-pivot<=1){
            currentAr++;
            i++;
        }
        maxAr = max(maxAr,currentAr);
        i++;
    }
    return maxAr+1;
}
int main() {
    freopen("input.txt","r",stdin);
    vector<int> a{4,6,5,3,3,1};
    cout<< pickingNumbers(a);
    return 0;
}
/*
- Tìm ra dãy lớn nhất mà hiệu bất kì của các phần tử trong dãy phải <=1
ví dụ 1 1 1 2 2 3 3 4 4 5 5
Thì đáp án là 
1 1 1 2 2 => 5
- Phương pháp giải
+ sắp xếp mảng a
+ cho i = 1, maxAr = 0
+ while(i< n)
	+ currentAr = 0;
	+ pivot = a[i-1] // Đánh dấu phần tử đầu mảng
	while( a[i] - a[i-1] <=1 && a[i] - pivot <=1)
		+ currentAr ++;
		+ i++;
	+ maxAr = max(maxAr,currentAr)
	+ i++
+ return i
*/