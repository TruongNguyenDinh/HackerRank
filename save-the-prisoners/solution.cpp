//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
int saveThePrisoner(int n, int m, int s) {
    return ((s + m - 2) % n) + 1;
}
int main() {
    freopen("input.txt","r",stdin);
    
    return 0;
}

/*
- Đề bài có n tù nhân ngồi thành vòng tròn 
- Phát m viên kẹo bắt đầu từ s
- Tìm người tù nhân nhận viên kẹo cuối cùng
- Sử dụng công thức (s + m -1 -1) % n + 1
- Giải thích: 
- (s + m -1) là người nhận viên kẹo cuối cùng
- trừ thêm 1 vì s là người đầu tiên nhận kẹo
- % n là xoay tua vòng
- +1 tính lại theo chỉ số từ  1 đến n thay vì 0 -> n 
*/