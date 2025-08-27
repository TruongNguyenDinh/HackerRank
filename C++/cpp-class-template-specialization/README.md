# Topic [Hacker Rank](https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem?isFullScreen=true) <- click here

## 1.Mã tham khảo

```cpp
#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
template<>
struct Traits<Color>{
    static string name(int index){
        switch (index){
            case 0: return "red";
            case 1: return "green";
            case 2: return "orange";
            default: return "unknown";
        }
    }
};
template<>
struct Traits<Fruit>{
    static string name(int index){
        switch (index){
            case 0: return "apple";
            case 1: return "orange";
            case 2: return "pear";
            default:return "unknown"; 
        }
    }
};
// 
```

## 2.Giải thích

Đầu tiên ta định nghĩa 2 `enum class` là `Fruit` và `Color`. Sau đó tạo một `template` và `struct Traits`. Mục đích là khai báo cho `complier` biết là vừa định nghĩa một `template Traits`.

```cpp
template <>
```

sử dụng lệnh này để khai báo riêng biệt kiểu dữ liệu có thể được truyền vào `Traits` 

Như vậy khi có 2 `enum` ta khai báo hai chuyên biệt hóa cho `Traits`. 

```cpp
struct Traits<Color>
struct Traits<Fruit>
```

Sau đó ta xử lý theo yêu cầu bài ra.
