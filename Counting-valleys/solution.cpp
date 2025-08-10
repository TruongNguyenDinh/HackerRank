int countingValleys(int steps, string path) {
    int level = 0, cntValleys = 0;
    for(int i = 0;i<path.size();i++){
        if(path[i]=='U'){
            level++;
            if(level == 0) cntValleys ++;
        }
        else {
            level--;
        }
        
    }
    return cntValleys;
}
/*
Phương pháp giải
- Duyệt từng kí tự trong chuỗi
- Tạo biến level để theo dõi độ cao với level set = 0
- Tạo biến valleys = 0 để đếm số thung lũng
- Mỗi khi:
+ Bước U : level ++;
+ Bước D : level --;
- Nếu sau một bước U mà level = 0 ( tức là từ dưới vừa lên ) -> kết thúc một thung lũng
-> Tăng valleys ++;
*/