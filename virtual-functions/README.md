# Topic: [Hacker Rank]([Virtual Functions | HackerRank](https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true)) <- Click to here

## Kiến thức cơ bản

1. Kế thừa 

```cpp
class A : public B
```

class A kế thừa class B

2. Ghi đè

```cpp
class B{
    public:
    virtual void greeting(){
        cout<<"Hello World !"<<endl;
    }  
};
class C : public B{
    public:
    void greeting(){
        cout<<"I love this beautiful place !"<<endl;
    }
}
```

Khi khai báo 

```cpp
B *b[1];
int m;
for(int i = 0;i<2;i++){
    cin>>m;
    if(m == 0){
        b[i] = new B;
    }
    else b[i] = new C;
}
for(int i = 0;i<2;i++){
    b[i]-> greeting();
}
```

3. Biến tĩnh

```cpp
static data_type val_name;
```

Ví dụ

```cpp
class A{
    private:
    int _id;
    string name;
    public:
    static int id ;
    void setData(){
        cin>>name;
        _id = ++id; // id tăng tự động 
    }
    void getData(){
        cout<<name<<" "<<_id<<endl;
    }
};
int A::id = 0; // sét id từ 0
```

Mã tham khảo:

```cpp
class Person{
    private:
    string name;
    int age;
    public:
    virtual void getdata(){
        cin>>name>>age;
    }
    virtual void putdata(){
        cout<<name<<" "<<age;
    }
};
class Professor : public Person{
    private:
    int id;
    int publications;
    public:
    static int cur_id ;

    void getdata(){
        Person::getdata();
        cin>>publications;
        id = ++cur_id;
    }
    void putdata(){
        Person::putdata();
        cout<<" "<<publications<<" "<<id<<endl;
    }    
};
class Student : public Person {
    private:
    int marks[6];
    int id;
    public: 
    static int s_id ;
    void getdata(){
        Person::getdata();
        for(int i = 0;i<6;i++){
            int x;cin>>x;
            marks[i] = x;   
        }
        id = ++s_id;;
    }
    void putdata(){
        int sum = 0;
        Person::putdata();
        for(int i = 0;i<6;i++){
            sum+=marks[i];
        }
        cout<<" "<<sum<<" "<<id<<endl;
    }
};
int Professor::cur_id = 0;
int Student::s_id = 0;
```
