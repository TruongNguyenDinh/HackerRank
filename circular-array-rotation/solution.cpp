//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> res;
    int n = a.size();
    k = k % n;
    for(int i= 0;i<queries.size();i++){
        int q = queries[i];
        res.push_back(a[(q-k+n)%n]);
        
    }
    return res;
}

int main() {
    freopen("input.txt","r",stdin);
    
    return 0;
}

/*
- Cho mảng a và mảng q truy vấn. Xoay mảng sang phải k lần theo cách
- phần tử cuối sẽ lên đầu còn các phần tử sau sẽ dịch sang phải
++ Cách làm
- Bước 1: khởi tạo vector res, lấy độ dài mảng(vector) a
- Bước 2: tránh xoay thừa thì k = k % n vì;
	Giả sử mảng a có 2 phần tử, nếu xoay 2 lần thì vị các phần tử sẽ trở lại ban đầu
- Bước 3: duyệt i = 0 -> i < q.size() , i++
	Sử dụng công thức pos = (q[i] - k + n)%n 
		Giải thích: q[i] là truy vấn tại lần i. 
		Nếu mảng a là 1 2 3 (mảng gốc), sau khi xoay  k = 2 ta có: a = 2 3 1
		Nếu q[i] = 0 thì ta có được (0 - k + 3)%3 = 1 -> a[1] = 2 ( chiếu theo mảng a gốc )
		thêm %n để đảm bảo không có truy vấn nào vượt qua n phần tử 
*/