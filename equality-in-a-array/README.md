Topic : [Hacker Rank](https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true)

Ý tưởng:

- Tìm phần tử được lặp lại nhiều nhất

- Lấy số phần tử của mảng trừ đi số phần tử lặp lại nhiều nhất thì sẽ ra số phần tử cần xóa đi để mảng có các phần tử giống nhau nhiều nhất

Mã tham khảo

```cpp
int equalizeArray(vector<int> arr) {
    map<int,int> mp;
    int m = 0;
// Tìm số phần tử lặp lại nhiều nhất
    for(int i = 0;i<arr.size();i++){
        mp[arr[i]]++;
        if(mp[arr[i]]>m){
            m = mp[arr[i]];
        }
    }
    return arr.size()- m;
}
```
