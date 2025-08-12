# Topic: [Hacker Rank](https://www.hackerrank.com/challenges/happy-ladybugs/problem?isFullScreen=true)

## Mã tham khảo

```cpp
string happyLadybugs(string b) {
    map<char,int> fre;
    bool hw = false;
    for(int x = 0;x < b.size();x++){
        fre[b[x]]++; // count the frequency of each element.
        if(b[x] == '_') hw= true; // Check have/haven't way
    }
    // if there was only one ladybug, it would be unhappy
    for(auto it : fre){
            if(it.first != '_' && it.second == 1) return "NO";
    }
    // If there was any way
    if(!hw){
    	//check each case
        if(b.size()==1) return "NO";
        else if (b.size() == 2 && b[0]!=b[1]) return "NO";
        else{
        	char s1 = b[0],s2 = b[1],s3 = b[2];
        	if( s1 != s2 && s2 != s3) return "NO";
        	for(int i = 3;i<b.size();i++){
        		// if there were three different continuous elements, return no
        		s3 = b[i];s2= b[i-1];s1= b[i-2];
        		if( s1 != s2 && s2 != s3) return "NO";
        	}
        }
    }
    return "YES";
}
```

## Giải thích

Ở ta có hai hướng để kiểm tra

- 1 là có dấu `_` mình gọi là đường đi

- 2 là không có dấu `_` 

### Trường hợp có đường đi

Chỉ cần kiểm tra xem có con bọ hay phần tử nào riêng lẻ không ? nếu có thì `return NO`

### Trường hợp không có đường đi

Bước 1 : Kiểm tra xem kích thước của chuỗi nếu :

- `size = 1` thì trả về `NO`

- `size = 2` thì kiểm tra hai phần tử xem có giống nhau không ?

Bước 2 : nếu `size > 2` thì lấy lần lượt 3 phần tử đầu để kiểm tra xem nếu cả 3 khác nhau thì `return NO`. Lặp lại cho đến khi hết chuỗi b

Bước 3: `return YES` nếu các trường hợp trên không chạy
