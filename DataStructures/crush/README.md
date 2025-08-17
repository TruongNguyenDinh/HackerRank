# Topic [Hacker Rank](https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true) <- Click to here

## 1.Ý tưởng

Sử dụng prefix sum để tính toán:

- Tính điểm bắt đầu và điểm kết thúc tại `queries[i]` với  `foreach x: queries` :
  
  - `left = x[0]-1` . Điểm bắt đầu
  
  - `right = x[1]-1` . Điểm kết thúc
  
  - `k = x[2]` . Giá trị `k`
  
  - Tính prefix sum: `a[l]+=k`
  
  - Kiểm tra nếu `r+1<n` thì `a[r+1]-=k`

    - Tính vị trí và tìm max

## 2.Tính tay

Ví dụ: n = 5, q = 3

```
queries = [[1, 2, 100], [2, 5, 100], [3, 4, 100]]
```

| queries | left | right | k   | a[left]+=k | r+1 < n   | a[right+1] |
| ------- | ---- | ----- | --- | ---------- | --------- | ---------- |
| 1,2,100 | 0    | 1     | 100 | a[0] =100  | 1 + 1 < 5 | a[2] =-100 |
| 2,5,100 | 1    | 4     | 100 | a[1] = 100 | 4+1<5     | not run    |
| 3,4,100 | 2    | 3     | 100 | a[2]=0     | 3+1<5     | a[4]=-100  |

| i   | a[i] | cur+=a[i] | res |              |
| --- | ---- | --------- | --- | ------------ |
| 0   | 100  | 100       | 100 |              |
| 1   | 100  | 200       | 200 |              |
| 2   | 0    | 200       | 200 |              |
| 3   | 0    | 200       | 200 |              |
| 4   | -100 | 100       | 200 | -> Res = 200 |

## 3.Mã tham khảo

```cpp
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> a(n+1, 0); //Mảng vị trí
    for (auto &x : queries) { // Duyệt các queries
        int l = x[0] - 1;  // Start
        int r = x[1] - 1; // End
        long k = x[2]; // Value

        a[l] += k; // 
        if (r + 1 < n) a[r+1] -= k;
    }

    long m = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];   // prefix sum
        m = max(m, cur);
    }

    return m;
}
```
