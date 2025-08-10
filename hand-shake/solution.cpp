//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int handshake(int n) {
    vector<int> v;
        v.push_back(0);
        for(int i =1;i<=n;i++){
            v.push_back(v[i-1]+i-1);
        }    
    
    return v[n];
}
int main() {
    freopen("input.txt","r",stdin);
    
    return 0;
}
/*
- Bài toán bắt tay:
+ Có n người bắt tay với nhau. Tính xem có bao nhiêu cái bắt tay
+ Giả sử n = 3; ta có 12 13 23 => 3 cái bắt tay
- Thuật toán
+ Khởi tạo vector v
+ khởi tạo v[0] = 0
+ Cho i:1->n
cho v[i]  = v[i-1] + (i - 1);
+ ví dụ n = 3
--------------
v[0] = 0
for i : 1 -> n
i = 1 : v[1] = v[0] +(1-1) = 0
i = 2 : v[2] = v[1] +(2-1) = 1
i = 3 : v[3] = v[2] +(3-1) = 3
vậy v[3] = 3
*/