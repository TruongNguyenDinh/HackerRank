# Topic:[Hacker Rank](https://www.hackerrank.com/challenges/operator-overloading/problem?isFullScreen=true) <- click here

## 1.Mã tham khảo

```cpp
class Matrix{
    public:
    vector<vector<int>> a;
    int sum; 
    Matrix():sum(0){};
    Matrix operator+(Matrix& other) const{
        Matrix result;
        int n = a.size();
        int m = a[0].size();
        result.a.assign(n,vector<int>(m,0));
        result.sum = 0;
        
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                result.a[i][j] = a[i][j]+other.a[i][j];
                result.sum += result.a[i][j];
            }
        }
        return result;
    }  
};
```

## 2.Giải thích

`Matrix():sum(0){};` : Khởi tạo một `constructor` mặc định với phần tử con `sum = 0` 

nó tương tự với khởi tạo như này.

```cpp
Matrix(){
    sum = 0;
}
```

`Matrix operator+(Matrix& other) const` : hàm tạo toán tử `+` cho lớp `Matrix` được tham chiếu bằng `const` (hằng) để đảm bảo không thay đổi đối tượng hiện tại

có thể truyền một kiểu khác như

```cpp
Matrix operator+(const Matrix& other) const
```

thì `const Matrix& other` để đảm bảo `other` không thể thay đổi.

```cpp
int n = a.size();
int m = a[0].size();
```

Vì ma trận có `n cột` nên kích thước của `vector a` đại diện cho số cột. Trong đó mỗi phần tử của `a` có `m` hàng nên lấy kích thước của một phần tử trong `a` bất kì để lấy số cột.

```cpp
result.a.assign(n,vector<int>(m,0));
```

 tạo ` một vector có n cột và m hàng với các phần tử = 0`

$\begin{matrix}
0 & 0 & ... & n\\\
... & ... & ... & ...\end{matrix}$

```cpp
for(int i = 0;i<n;i++){
  for(int j=0;j<m;j++){
        result.a[i][j] = a[i][j]+other.a[i][j];
        result.sum += result.a[i][j];
    }
}
```

Tính toán ma phép cộng.
