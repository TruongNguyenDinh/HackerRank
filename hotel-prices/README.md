# Topic [Hacker Rank](https://www.hackerrank.com/challenges/hotel-prices/problem?isFullScreen=true) <- click to here



```cpp
//Author Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    virtual int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

     int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        cout<<room->get_price()<<endl;
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}
```

Vấn đề

Lơp cha `HotelRoom` được tham chiếu nhưng mà hàm `get_price` của lớp cha không được khai báo là `virtual` nên sẽ không đa hình tức là việc gọi hàm `get_price` từ class `HotelApartment` sẽ không được thực hiện vì thế.

```cpp
HotelRoom* room = new HotelApartment(2, 1);
cout << room->get_price();
```

khi gọi `room->get_price()` thì compiler sẽ gọi hàm `HotelRoom::get_price()` chứ không phải `HotelApartment::get_price()` nên sẽ gây ra sai kết quả. 

Nói cách khác khi khai báo `virtual` cho một hàm ở lớp cha thì cho biết hàm đó có thể được ghi đè từ lơp con kế thừa lớp cha. Giống với `@override` trong java hay python.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void sayHello() {
        cout << "Hello from Base\n";
    }
};

class Derived : public Base {
public:
    void sayHello() override { // override không bắt buộc nhưng khuyến khích dùng
        cout << "Hello from Derived\n";
    }
};

int main() {
    Base* obj = new Derived();
    obj->sayHello(); // Gọi Derived::sayHello, quyết định lúc chạy
}

```

Việc khai báo `override` ở lớp con báo cho compiler biết rằng hàm này đang ghi đè một hàm ảo ở lớp cha (giúp tránh lỗi chính tả).
