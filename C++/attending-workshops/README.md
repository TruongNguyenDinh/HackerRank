# Topic [Hacker Rank]([Attending Workshops | HackerRank](https://www.hackerrank.com/challenges/attending-workshops/problem?isFullScreen=true)) <- click here

## 1. Mã tham khảo

```cpp
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops{
    int n;
    Workshops* workshops;
};
Available_Workshops* initialize(int start_time[],int duration[],int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->workshops = new Workshops[n];
    for (int i = 0; i < n; i++) {
        aw->workshops[i].start_time = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end_time = start_time[i] + duration[i];
    }
    return aw;
}
int CalculateMaxWorkshops(Available_Workshops* ptr){
    sort(ptr->workshops, ptr->workshops + ptr->n,
    [](Workshops& a, Workshops& b){
        return a.end_time<b.end_time;
    });
    int cnt = 0;
    int current_end = 0;
    for(int i = 0;i<ptr->n;i++){
        if(ptr->workshops[i].start_time>=current_end){
            cnt++;
            current_end = ptr->workshops[i].end_time;
        }
    }
    return cnt;
}
```

## 2.Giải thích

```cpp
struct Workshops{
    int start_time;
    int duration;
    int end_time;
}
```

Định nghĩa một cấu trúc có tên  `Workshops` 

 Tương tự với `Available_Workshops` 

```cpp
struct Available_Workshops{
    int n;
    Workshops* workshops
};
```

Vì  yêu cầu đề bài là một mảng `workshops` được định nghĩa trong `Available_Workshops` nên ta cần một con trỏ trỏ tới cấu trúc `workshops`.

```cpp
Available_Workshops* initialize(int start_time[],int duration[],int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->workshops = new Workshops[n];
    for (int i = 0; i < n; i++) {
        aw->workshops[i].start_time = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end_time = start_time[i] + duration[i];
    }
    return aw;
}
```

Tạo một hàm khởi tạo trả về con trỏ trỏ tới `Available_Workshops`

`new Available_Workshops tạo **một đối tượng Available_Workshops trên heap`

```cpp
aw->n = n;
```

Vì `aw` là **con trỏ**, nên muốn truy cập thành viên thì phải dùng `->`.

```cpp
aw->workshops = new Workshop[n];
```

`aw->workshops` là **con trỏ** tới mảng `Workshop`.

`new Workshop[n]` cấp phát động một mảng gồm `n` workshop trên heap.

Sau đó gán địa chỉ mảng đó cho `aw->workshops`.

Kết quả ta có được:

- Một `Available_Workshops` nằm trên heap.

- Bên trong nó có một con trỏ `workshops`, trỏ tới mảng `Workshop[n]` cũng nằm trên heap.

- Như vậy toàn bộ dữ liệu sẽ **sống ngoài hàm** (không bị mất khi hàm return).

```cpp
int CalculateMaxWorkshops(Available_Workshops* ptr){
    sort(ptr->workshops, ptr->workshops + ptr->n,
    [](Workshops& a, Workshops& b){
        return a.end_time<b.end_time;
    });
    int cnt = 0;
    int current_end = 0;
    for(int i = 0;i<ptr->n;i++){
        if(ptr->workshops[i].start_time>=current_end){
            cnt++;
            current_end = ptr->workshops[i].end_time;
        }
    }
    return cnt;
} 
```

Hàm `CalculateMaxWorkshops` đơn giản chỉ là tính toán xem có thể tham gia tối đa bao nhiêu workshops. 

```cpp
sort(ptr->workshops, ptr->workshops + ptr->n,
    [](Workshops& a, Workshops& b){
        return a.end_time<b.end_time;
    });
```

Hàm này mục đích sắp xếp theo thời gian kết thúc sự kiện theo thứ tự từ nhỏ đến lớn để chọn được tối đa các sự kiện.


