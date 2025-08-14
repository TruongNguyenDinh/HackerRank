# Topic : [Hacker Rank](https://www.hackerrank.com/challenges/lowest-triangle/problem?isFullScreen=true) <- Click to here

```cpp
int lowestTriangle(int trianglebase, int area) {
    return area*2%trianglebase == 0 ?area*2/trianglebase: area*2/trianglebase+1 ;
}
```

Tính chiều cao tối thiểu bằng cách lấy diện tích chia đáy, nếu không chia hết cho đấy thì lấy diện tích chia đáy rồi cộng thêm 1. 


