Topic :[Hacker Rank](https://www.hackerrank.com/challenges/strange-code/problem?isFullScreen=true)

Phương pháp giải:

Ý tưởng:

- Bộ đếm bắt đầu từ  3, mỗi chu kì thì sẽ giảm đi một đơn vị tối đa là 1, sau đó sẽ tăng gấp đôi

- Ta cần tìm chu kì mà t thuộc về

- Giá trị tại t = value - ( t - cycle_start)

```cpp
long strangeCounter(long t) {
    long cycle_start = 1;
    long value = 3;

    // tìm chu kỳ chứa t
    while (t >= cycle_start + value) {
        cycle_start += value;
        value *= 2;
    }

    return value - (t - cycle_start);
}

```

Tính tay:

Ví dụ t = 8

| Step | cycle_start(1) | value(2) | sum(1+2) ? t |
| ---- | -------------- | -------- | ------------ |
| 0    | 1              | 3        | x            |
| 1    | 1              | 3        | 4 < 8        |
| 2    | 4              | 6        | 10 > 8       |
| x    | x              | x        | x            |

return  value  - (t - cycle_start) = 6 - (8- 4)  = 2

Ví dụ 2 :  t = 17

| Step | cycle_start(1) | value(2) | sum(1+2) ? t |
| ---- | -------------- | -------- | ------------ |
| 0    | 1              | 3        | x            |
| 1    | 1              | 3        | 4 < 17       |
| 2    | 4              | 6        | 10 < 17      |
| 3    | 10             | 12       | 22 > 17      |
| x    | x              | x        | x            |

 return value - (t - cycle_start) = 12 - (17 - 10) = 5
