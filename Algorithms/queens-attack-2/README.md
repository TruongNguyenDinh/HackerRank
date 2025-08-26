# Topic [Hacker Rank](https://www.hackerrank.com/challenges/queens-attack-2/problem?isFullScreen=true) <- Click here

## Mã tham khảo

## 1.Phương án 1 (sử dụng DFS để duyệt)

```cpp
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int cnt = 0;
void dfs(int n,int r,int c,const vector<vector<int>>& obstacles,int direction){
    vector<int> pos = {r,c};
    auto it = find(obstacles.begin(),obstacles.end(),pos);
    if(it== obstacles.end()){
        cnt++;
        int new_r = r+dx[direction];
        int new_c = c+dy[direction];
        if(new_r >=1 && new_c >= 1 && new_r<=n && new_c <=n){
            dfs(n,r+dx[direction],c+dy[direction],obstacles,direction);
        }
        else return;
    }
    else{
        return;    
    }
}
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    for(int i = 0;i<8;i++){
        int new_r = r_q+dx[i];
        int new_c = c_q+dy[i];
        if(new_r >=1 && new_c >= 1 && new_r<=n && new_c <=n){
            dfs(n,r_q+dx[i],c_q+dy[i],obstacles,i);
        }
        
    }
    return cnt;
}
```

### 1.1 Giải thích

Ta duyệt lần lượt 8 hướng đi của quân hậu, với mỗi hướng đi thì dungg DFS để duyệt xâu nhất có thể của mỗi hướng. Mỗi bước đi sẽ tăng một lần biến `cnt`. Nếu gặp vật cản thì sẽ dừng lại,

Tuy nhiên phương pháp trên sẽ dễ dần đến lỗi `Time limit exceeded` vì đệ quy và `find` của vector trong trường hợp xấu nhất.

## 2.Phương án 2

```cpp
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    unordered_set<string> s;
    for(auto &o:obstacles){
        string hash = to_string(o[0])+','+to_string(o[1]);
        s.insert(hash);
    }
    int cnt = 0;
    for(int i = 0;i<8;i++){
        int new_r = r_q+dx[i];
        int new_c = c_q+dy[i];
        while(new_r >=1 && new_c >= 1 && new_r<=n && new_c <=n){
            string tmp = to_string(new_r)+','+to_string(new_c);
            if(s.count(tmp)) break;
            cnt++;
            new_r +=dx[i];
            new_c+=dy[i];
        }
        
    }
    return cnt;
}
```

### 2.2 Giải thích

Ta tìm cách biến cái tọa độ vật cản thành một `id` sao cho nó phải là `độc nhất`. Sau đó ta đưa vào `unordered_set`.

Từ đó duyệt 8 hướng và chạy tới tận cùng 8 hướng để đếm

Mục tiêu đưa vào `set` vì tìm ra vật cản sẽ nhanh hơn gần như `O(1)`.

 
