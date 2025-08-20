# Topic [Hacker Rank]([Minimum Distances | HackerRank](https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true)) <- Click to here

## Ý tưởng:

Sử dụng `unordered_map` để nhớ vị trí trước đó của từng phần tử và tính khoản cách sau đó

## Mã tham khảo

```cpp
int minimumDistances(vector<int> a) {
    int distance = INT_MAX; // result
    unordered_map<int,int> lastIndex; // map để nhớ vị trí

    for (int i = 0; i < a.size(); i++) {
        if (lastIndex.find(a[i]) != lastIndex.end()) { // Tìm vị a[i]
            distance = min(distance, i - lastIndex[a[i]]);
        }
        lastIndex[a[i]] = i;// Lưu vị trí xuất hiện sau cùng
    }

    return (distance == INT_MAX) ? -1 : distance;
}


```

## Giải thích

- Sử dụng `unordered_map` giúp cho việc `map` sẽ không tự sắp xếp lại vị trí các cặp `key-value`.
