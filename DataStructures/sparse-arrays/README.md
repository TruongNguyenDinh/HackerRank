# Topic [Hacker Rank]([Sparse Arrays | HackerRank](https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true)) <- Click to here

## 1.Ý tưởng

Sử dụng `map` để ánh xạ số lần xuất hiện của chuỗi.

Đẩy số lần xuất hiện và `res`

## 2.Mã tham khảo

```cpp
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    map<string,int> mp;
    for(auto x:stringList){
        mp[x]++;
    }
    vector<int> res;
    for(auto x: queries){
        res.push_back(mp[x]);
    }
    return res;
}
```
