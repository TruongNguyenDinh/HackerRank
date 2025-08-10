//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int jumpingOnClouds(vector<int> c, int k) {
    int energy = 100;
    int n = c.size();
    int i = 0;
    while ((i+k)%n != 0){
            int pos = (i+k) % n;
            if(c[pos] == 0) energy --;
            else energy -=3;
            i+=k;
    }
    i+=k;
    if(c[i%n] == 1) energy -=3;
    else energy --;
    return energy;
}

//GPT version
int jumpingOnClouds_GPT(vector<int> c, int k) {
    int energy = 100;
    int n = c.size();
    int i = 0;
    do {
        i = (i + k) % n;
        energy -= 1 + 2 * c[i];
    } while (i != 0);
    return energy;
}

int main() {
    freopen("input.txt","r",stdin);
    
    return 0;
}
/*
	Đề bài: Có một mảng n đám mấy nối lại thành vòng tròn đánh số từ  0 -> n- 1
			Mỗi đám mây có thể là đám mây thường hoặc đám mây giông với:
				1 là đám mây giông
				2 là đám mây thường
			Một người nhảy từ đám mây này sang đám mây kia với khoảng cách là k
			tức là một bước nhảy sẽ đến đám mây thứ [(i+k) % n]
			Cho năng lượng = 100, mỗi bước nhảy mất 1 năng lượng
			Nếu nhảy vào đám mây giông thì mất thêm 2 năng lượng
			Nhiệm vụ : tính năng lượng còn lại của người này sau khi kết thúc nhảy
						Kết thúc nhảy là khi người đó nhảy lại về vị trí bắt đầu
	Cách giải lặp cho đến khi đến bước được vị trí ban đầu tức là (i+k)%n == 0
		+ nếu là đám mây thường thì trừ 1 năng lượng
		+ nếu không phải từ trừ 2 + 1 năng lượng
		+ Tại bước nhảy cuối cùng kiểm tra là đám mây nào rồi trừ năng lượng tương ứng

*/