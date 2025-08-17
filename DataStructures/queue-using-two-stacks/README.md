# Topic: [Hacker Rank]([Queue using Two Stacks | HackerRank](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem?isFullScreen=true)) <- Click to here

## 1.Ý tưởng

Sử dụng `2 stack` để thể hiện việc thêm và đẩy dữ liệu ra

`enqueue` : ngăn xếp để đẩy dữ liệu vào

`dequeue` : ngăn xếp để đẩy dữ liệu ra

## 2. Mã tham khảo

```cpp
#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin>>q;
    stack<int> enqueue,dequeue;
    while(q--){
        int type;cin>>type;
        if(type == 1){
            int x;cin>>x;
            enqueue.push(x);
        }
        else if(type == 2){
            if(dequeue.empty()){
                while(!enqueue.empty()){
                    dequeue.push(enqueue.top());
                    enqueue.pop();
                }
            }
            dequeue.pop();
        }
        else{
            if (dequeue.empty()) {
                while (!enqueue.empty()) {
                    dequeue.push(enqueue.top());
                    enqueue.pop();
                }
            }
            cout << dequeue.top() << '\n';
        }
    }
    //Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

```

Giải thích

Vì stack lưu dữ liệu dang ngăn xếp hay được gọi là `Last in First out  (LIFO)` nên việc muốn pop phần tử đầu tiên được thêm là không thể -> nên ta dùng 2 stack. `enqueue` là stack chịu trách nhiệm đẩy phần tử vào khi đó thứ tự lưu sẽ như sau:

Ví dụ : 1 2 3 4 5 -> Đẩy vào stack ta có được 5 4 3 2 1

Nên khi pop thì số 5 sẽ bị pop chứ không phải 1 

Việc dạo `dequeue` là một stack đảo ngược lại của `enqueue` thì khi đó dữ liệu sẽ theo thứ tự sau: 1 2 3 4 5

Khi đó `pop` sẽ đẩy phần tử `1` khỏi stack.

Việc này giúp nhanh chóng với độ phúc tạp `O(q)` vì mỗi lần thực hiện 1 truy vấn trong q truy vấn chỉ mất thao tác `O(1)` 


