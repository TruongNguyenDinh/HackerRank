Đề bài [Hacker Rank]([Repeated String | HackerRank](https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true))

Tiếng Việt: Cho chuỗi s, và số nguyên n. Tìm số lần kí tự `a` được lặp lại tại n kí tự đầu của chuỗi, biết chuỗi này có thể lặp vô hạn.

### Cách giải:

- Bước 1: Tính số kí tự `a` có mặt trong chuỗi gốc.

- Bước 2: Tính số nguyên lần kí tự a lặp trong `n/s.size()` 

- Bước 3 : Duyệt chuỗi `s` từ 0 đến phần dư còn lại sau `n/size()` lần lặp lại  
