# Topic:[Hacker Rank]([2D Array - DS | HackerRank](https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true)) <- Click to here

## Cách giải

Cách tính tổng đồng hồ cát

Tạo bước đi cho ma trận theo hình thức sau:

| i,j \| (0,0)   | i,j+1 \| (0,1)   | i,j+2 \| (0,2)   |
| -------------- | ---------------- | ---------------- |
|                | i+1,j+1 \| (1,1) |                  |
| i+2,j \| (1,0) | i+2,j+1 \| (2,1) | i+2,j+2 \| (2,2) |

Từ ma trận biểu diễn trên ta đưa ra các bước đi sau:

```cpp
int dx[]={0,1,2,0,2,0,2};
int dy[]={0,1,2,2,0,1,1};
```

## Mã tham khảo

```cpp
int hourglassSum(vector<vector<int>> arr){
    int dx[]={0,1,2,0,2,0,2}; // Bước đi
    int dy[]={0,1,2,2,0,1,1}; // Bước đi
    int res = - 9999; // Result
    for(int i=0;i<arr.size()-2;i++){ // Từ đi 2 hàng cuối (cột)
        for(int j=0;j<arr.size()-2;j++){ // Trừ đi 2 cột cuối (hàng)
            int x = 0; // Vị trí
            int cmax = 0; // temp
            while(x<7){
                cmax += arr[i+dx[x]][j+dy[x]]; // Tính tổng đồng hồ cát
                x++; // Tăng bước đi
            }
            res = max(cmax,res); // Tìm max
        }
    }
    return res; // trả về kết quả
}
```


