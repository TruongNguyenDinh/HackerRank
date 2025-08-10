//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
int gameWithCells(int n, int m) {
    return ((m+1)/2)*((n+1)/2);
}
/*
- Thêm cộng 1 mục đích làm tròn lên
- Giả sử m = 5, n = 2
=> số tiếp tế cần là: (5+1)/2 * (2+1)/2 = 3 * 1 = 3.
- Nếu không cộng 1 thì kết quả được 2(sai). 
*/
int main() {
    freopen("input.txt","r",stdin);
    
    return 0;
}
/*
Bài toán: có m * n căn nhà xếp lưới 
-Tính số tiếp tế tối thiểu có thể thả khi có m*n căn nhà
-Các căn nhà có thể nhận hàng tiếp tế nếu chung vách
-	----- -----
-	|	 |	  |
- 	-----o-----
- 	|	 |	  |
- 	-----------
- o là điểm thả tiếp tế
*** Cách giải  ***
- Cứ 4 căn nhà tạo thành 1 khối 2x2
- => Với N * M căn nhà -> chia thành khối 2x2 -> số lượng khối 2x2 = ceil(M/2) * ceil(N/2)
(ceil : là làm tròn ) 
*/