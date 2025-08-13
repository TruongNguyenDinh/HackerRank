# Topic [Hacker Rank]([Climbing the Leaderboard | HackerRank](https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true)) <- click to here

Ý tưởng:

Làm gọn mảng ranked bằng cách xóa các điểm trùng lặp

Cú pháp:

```cpp
vector<int> v;
v.erase(unique(v.begin(),v.end()),v.end());
```

Sau khi loại bỏ các điểm trùng lặp thì sau đó so sánh các điểm trong `player` và `ranked` để tìm vị trí. Duyệt từ cuối bảng `ranked` để tìm

Mã tham khảo:

```cpp
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Xóa các điểm trùng lặp
    ranked.erase(unique(ranked.begin(),ranked.end()),ranked.end());
    // Vector trả về
    vector<int> res;
    int n = ranked.size();
    int i = n -1;
    for(auto x:player){ // duyệt điểm của player
        while(i>=0 && x>=ranked[i]){
            i--;
        }
         res.push_back(i+2);
    }
    return res;
}
```

Giải thích đoạn

`res.push_back(i+2)`

Có dữ liệu ranked: 100 50 40 20 10 ( n = 5 )

player: 5 25 50 120

ta có bảng sau

| i   | player | ranked | i = n - 1 | x : player  >= ranked[i]           | res add ( i+2 ) |
| --- | ------ | ------ | --------- | ---------------------------------- | --------------- |
|     | 5      | 100    | 4         | x = 5 >= 10 \| false               | 6               |
|     | 25     | 50     | 4         | x = 25 > = 10 \| true              | not run         |
|     | 50     | 40     | 3         | x = 25 >= 20 \| true               | not run         |
|     | 120    | 20     | 2         | x = 25 >= 40 \| false              | 4               |
|     |        | 10     | 2         | x = 50 >= 40 \| true               | not run         |
|     |        |        | 1         | x = 50 >= 50 \| true               | not run         |
|     |        |        | 0         | x = 50 >= 100 \| false             | 2               |
|     |        |        | 0         | x = 120>= 100 \| true              |                 |
|     |        |        | -1        | dont run beacause i canot negative | 1               |


