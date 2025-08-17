# Topic :[Hacker Rank](https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true) <- Click to here

## 1.Mã tham khảo

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; 
    cin >> n >> m; cin.ignore();// Nhập thẻ và số truy vấn đồng thời xóa kí tự cuối 

    map<string,string> mp; // Ánh xạ
    vector<string> tagPath;// Đường dẫn

    for (int i = 0; i < n; i++) { 
        string line;
        getline(cin, line); // Nhập dòng

        if (line[1] == '/') { // Nếu thẻ đóng
            tagPath.pop_back(); // Xóa cuối đi
        } 
        else {
            line = line.substr(1, line.size()-2); //bỏ đi <>
            stringstream ss(line); // tách chuỗi bởi các dấu cách
            string tag; ss >> tag; // Đẩy tag ra
            tagPath.push_back(tag); // cho vào đường dẫn

            string attr, eq, val; // thuộc tính, dấu bằng và giá trị
            while (ss >> attr >> eq >> val) { 
                val = val.substr(1, val.size()-2);// bỏ cặp dấu ""
                string fullPath = "";
                for (int j=0;j<tagPath.size();j++) {
                    if (j>0) fullPath += ".";
                    fullPath += tagPath[j];
                }
                mp[fullPath + "~" + attr] = val;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        string query; getline(cin, query);
        if (mp.count(query)) cout << mp[query] << endl;
        else cout << "Not Found!" << endl;
    }

    return 0;
}


```


