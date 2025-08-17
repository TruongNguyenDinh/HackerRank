# Topic [Hacker Rank](https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true) <- Click to here

## 1.Phương pháp giải

- Kiểm tra lại vòng lặp xem có lặp lại `n` lần kích thước mảng không ? ( Sử dụng modulo)

- Lặp cho đến khi bằng số lần lặp
  
  - Xóa phần tử đầu
  
  - Đẩy vào phần tử cuối

## 2.Mã tham khảo

### 2.1 Sử dụng ý tưởng trên

```cpp
vector<int> rotateLeft(int d, vector<int> arr) {
    d %=arr.size();
    for(int i = 0;i<d;i++){
        int x = *arr.begin();
        arr.erase(arr.begin());
        arr.push_back(x);
    }
    return arr;
}
```

### 2.2 Sử dụng lệnh có sẵn trong thư viện

```cpp
vector<int> rotateLeft(int d, vector<int> arr) {
    d %= arr.size();
    rotate(arr.begin(), arr.begin() + d, arr.end());
    return arr;
}
```

 
