# Between two sets

## Topic

Cho hai mảng số nguyên **a** và **b** 

Yêu cầu:

1. Mọi phần tử trong mảng **a** đều là ước số của **X**
   
   $X \mid a[i] = 0, \forall i$

2. **X** là ước số của mọi phần tử trong mảng **b**
   
   $b[j] \mid X = 0, \forall j$

Theo đó ta có công thức sau:

- Giả sử mảng **a** có **n** phần tử

- Giả sử mảng **b** có **m** phần tử

$$
x \mid a_i = 0, \forall_i \in [0,n]
$$

$$
b_j \mid x = 0, \forall j \in [0,m]
$$

## Cách giải

1. Tìm Bội Chung Nhỏ Nhất (LCM) của mảng a

2. Tìm Ước Chung Lớn Nhất (GCD) của mảng b

3. Duyệt các số x từ LCM đến GCD, nếu GCD % X == 0 thì đó là một đáp án hợp lệ
