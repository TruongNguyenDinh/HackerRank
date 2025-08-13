# Topic [Hacker Rank]([Cut the sticks | HackerRank](https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true)) <- click to here

Cách giải

Lặp cho đến khi mảng bằng rỗng khi đó cứ xóa dần phần tử nhỏ nhất trong mảng đi. Sau mỗi lần xóa thì thêm kích thước mảng vào một mảng res lưu kết quả

Mã tham khảo

```cpp
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> res;
    while(!arr.empty()){
         // Đẩy kích thước mảng vào mảng kết quả
        res.push_back(arr.size());
        // Tìm phần tử nhỏ nhất trong mảng
        int me = *min_element(arr.begin(),arr.end());
        // Xóa hết các phần tử nhỏ nhất đi
        arr.erase(remove(arr.begin(),arr.end(),me),arr.end());
        
    }
    return res;
}


```

Cách 2 : Nhanh hơn

```cpp
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> res; //Vector lưu kết quả
    sort(arr.begin(),arr.end()); // Sắp xếp theo thứ tự tăng dần
    int n = arr.size(); 
    res.push_back(n);// Thêm kích thước ban đầu của mảng
    for (int i = 1;i<n;i++){
        // Nếu khác nhau thì xóa đi những phần tử đứng trước
        if(arr[i] != arr[i-1]){
            res.push_back(n-i);
        }
    }
    return res;
}
```

cách này được hiểu đơn giản là sắp xếp các phần tử từ bé đến lớn. Kiếm tra xem các phần tử này có khác nhau không ? nếu khác nhau thì xóa đi ví trí của phần tử trước.

Nếu bằng nhau thì i tăng.
