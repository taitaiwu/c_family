# 📄 C++ 考試速查表（Final 版）

---

## 🔹 1. 基本 I/O

```cpp
#include <iostream>
using namespace std;

int a;
cin >> a;

string s;
getline(cin, s);
```

---

## 🔹 2. string

```cpp
#include <string>

s.length() / s.size()
s.substr(pos, len)
s.find("abc")   // 找不到 → string::npos
```

```cpp
if (s.find("x") == string::npos)
```

---

## 🔹 3. stringstream（輸入驗證🔥）

* 輸入數字(整數/浮點數)驗證
    ```cpp
    #include <sstream>

    while (true)  // 可以利用無窮迴圈驗證並重複輸入
    {
        string input;
        getline(cin, input);

        stringstream ss(input);
        int a, b;  //如果只要驗證一個整數就把 b 拿掉

        // 正確兩整數
        if ((ss >> a >> b) && !(ss >> input)) break;

        // 輸出錯誤訊息
        cout << "INPUT ERROR!" << endl;
    }
    ```
* 輸入字元驗證 (y/n or Y/N)
    ```cpp
    #include <sstream>

    while (true) 
    {
        string input;
        getline(cin, input);

        stringstream ss(input);
        char c;

        if ((ss >> c) && !(ss >> input)) {
            c = toupper(c);  //自動轉大寫，也可以直接 if 大小寫
            if (c == 'Y' || c == 'N') break;
        }

        // 輸出錯誤訊息
        cout << "Input ERROR!" << endl;
    }
    ```

---

## 🔹 4. 浮點數判斷

```cpp
#include <cmath>

if (fabs(n - (int)n) < 1e-6)
```
或者利用第3點檢查字串是否含有小數點

---

## 🔹 5. 輸出格式

```cpp
#include <iomanip>

cout << fixed << setprecision(2) << n;
```

---

## 🔹 6. 指標 & 陣列

```cpp
int arr[5];
int *p = arr;

*(p+i) == arr[i]
```

---

## 🔹 7. 動態記憶體

```cpp
int *arr = new int[n];

delete[] arr;
```

---

## 🔹 8. vector(可自動擴充的陣列)

```cpp
#include <vector>

vector<int> v;
v.push_back(10);
v.size()
v[i]
```

---

## 🔹 9. 排序（必考🔥）

```cpp
#include <algorithm>

sort(v.begin(), v.end());
```

```cpp
bool cmp(int a, int b){
    return a > b;
}
sort(v.begin(), v.end(), cmp);
```

---

## 🔹 10. struct / class

```cpp
struct Node{
    int x;
};
```

```cpp
class A{
private:
    int x;
public:
    void set(int v){ x = v; }
};
```

---

## 🔹 11. 🎲 Random（超重要🔥）

```cpp
#include <cstdlib>
#include <ctime>

srand(time(0)); // 只呼叫一次
```

### 範圍公式

```cpp
rand() % n          // 0 ~ n-1
rand() % n + 1      // 1 ~ n
rand() % (b-a+1)+a  // a ~ b
```

### 範例

```cpp
rand() % 6 + 1   // 骰子
rand() % 13 + 1  // 撲克牌
rand() % 4       // 花色
```

❗ 不要在迴圈內 srand

---

## 🔹 12. 數學

```cpp
#include <cmath>

abs(x)      // 整數絕對值
fabs(x)     // 浮點數絕對值
sqrt(x)     // 平方
pow(a,b)    // 次方
floor(x)    // 無條件捨去
ceil(x)     // 無條件進位
round(x)    // 四捨五入
```

---

## 🔹 13. 迴圈

```cpp
for(int i=0;i<n;i++){}
while(true){}
```

---

## 🔹 14. 常見錯誤🔥

### 字串比較

```cpp
if (s == "abc") // ✅
```

---

### find 判斷

```cpp
if (s.find("a") == string::npos) // ✅
```

---

### 浮點比較

```cpp
if (fabs(a-b) < 1e-6) // ✅
```

---

### ❌ 錯誤

```cpp
to_string(n) // 想控制小數 ❌
```