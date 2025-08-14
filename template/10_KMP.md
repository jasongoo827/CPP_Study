# 🔍 KMP (문자열 매칭)

> **난이도**: Platinum  
> **대표 문제**: 1786(찾기), 1305(광고), 4354(문자열 제곱)

---

## 🎯 **핵심 개념**

KMP(Knuth-Morris-Pratt) 알고리즘은 **선형 시간**에 문자열 매칭을 수행하는 고급 알고리즘입니다:
- **실패함수(Failure Function)**: 패턴에서 매칭이 실패했을 때 다음에 비교할 위치를 결정
- **시간복잡도**: O(n + m) (n: 텍스트 길이, m: 패턴 길이)
- **핵심 아이디어**: 이미 매칭된 정보를 재활용하여 불필요한 비교를 줄임

---

## 🔧 **기본 템플릿**

### **실패함수 (Failure Function)**
```cpp
// 패턴의 실패함수 계산
vector<int> getFailure(const string& pattern) {
    int m = pattern.length();
    vector<int> failure(m, 0);
    
    for (int i = 1, j = 0; i < m; i++) {
        // 현재 문자가 다르면 이전 실패값으로 이동
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1];
        }
        
        // 현재 문자가 같으면 실패함수 값 증가
        if (pattern[i] == pattern[j]) {
            failure[i] = ++j;
        }
    }
    
    return failure;
}
```

### **KMP 매칭**
```cpp
// KMP를 이용한 모든 매칭 위치 찾기
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> failure = getFailure(pattern);
    vector<int> matches;
    
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0, j = 0; i < n; i++) {
        // 현재 문자가 다르면 실패함수 활용
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j - 1];
        }
        
        // 현재 문자가 같으면 진행
        if (text[i] == pattern[j]) {
            j++;
        }
        
        // 패턴 완전 매칭 발견
        if (j == m) {
            matches.push_back(i - m + 1);  // 매칭 시작 위치
            j = failure[j - 1];  // 다음 매칭을 위해 이동
        }
    }
    
    return matches;
}
```

### **통합 버전**
```cpp
class KMP {
private:
    string pattern;
    vector<int> failure;
    
    void buildFailure() {
        int m = pattern.length();
        failure.assign(m, 0);
        
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = failure[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                failure[i] = ++j;
            }
        }
    }
    
public:
    KMP(const string& pat) : pattern(pat) {
        buildFailure();
    }
    
    vector<int> search(const string& text) {
        vector<int> matches;
        int n = text.length();
        int m = pattern.length();
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && text[i] != pattern[j]) {
                j = failure[j - 1];
            }
            
            if (text[i] == pattern[j]) j++;
            
            if (j == m) {
                matches.push_back(i - m + 1);
                j = failure[j - 1];
            }
        }
        
        return matches;
    }
    
    const vector<int>& getFailure() const {
        return failure;
    }
};
```

---

## 💡 **풀이 패턴**

### **1. 기본 문자열 매칭**
```cpp
// 텍스트에서 패턴이 나타나는 모든 위치 찾기
void findAllOccurrences(const string& text, const string& pattern) {
    vector<int> matches = kmpSearch(text, pattern);
    
    cout << matches.size() << "\n";  // 매칭 개수
    for (int pos : matches) {
        cout << pos + 1 << " ";  // 1-based 인덱스
    }
    cout << "\n";
}
```

### **2. 주기 패턴 찾기**
```cpp
// 문자열의 최소 주기 찾기
int findMinimalPeriod(const string& s) {
    vector<int> failure = getFailure(s);
    int n = s.length();
    int periodLength = n - failure[n - 1];
    
    // 주기가 문자열 길이를 나누어 떨어뜨리면 주기적
    if (n % periodLength == 0) {
        return periodLength;
    }
    
    return n;  // 주기 없음 (전체가 최소 주기)
}

// 문자열이 다른 문자열의 반복인지 확인
bool isRepeated(const string& s) {
    int period = findMinimalPeriod(s);
    return period < s.length() && s.length() % period == 0;
}
```

### **3. 접두사-접미사 매칭**
```cpp
// 문자열에서 접두사이면서 접미사인 모든 길이 찾기
vector<int> findPrefixSuffixLengths(const string& s) {
    vector<int> failure = getFailure(s);
    vector<int> lengths;
    
    int cur = failure[s.length() - 1];
    while (cur > 0) {
        lengths.push_back(cur);
        cur = failure[cur - 1];
    }
    
    reverse(lengths.begin(), lengths.end());
    return lengths;
}
```

---

## 🔍 **실제 예시**

### **예시 1: 찾기 (1786번)**
```cpp
#include <iostream>
#include <vector>
#include <string>

vector<int> getFailure(const string& pattern) {
    int m = pattern.length();
    vector<int> failure(m, 0);
    
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            failure[i] = ++j;
        }
    }
    return failure;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> failure = getFailure(pattern);
    vector<int> matches;
    
    for (int i = 0, j = 0; i < text.length(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j - 1];
        }
        
        if (text[i] == pattern[j]) j++;
        
        if (j == pattern.length()) {
            matches.push_back(i - pattern.length() + 1);
            j = failure[j - 1];
        }
    }
    return matches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    
    vector<int> matches = kmpSearch(text, pattern);
    
    cout << matches.size() << "\n";
    for (int pos : matches) {
        cout << pos + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}
```

### **예시 2: 광고 (1305번)**
```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L;
    string ad;
    cin >> L >> ad;
    
    // 실패함수 계산
    vector<int> failure(L, 0);
    for (int i = 1, j = 0; i < L; i++) {
        while (j > 0 && ad[i] != ad[j]) {
            j = failure[j - 1];
        }
        if (ad[i] == ad[j]) {
            failure[i] = ++j;
        }
    }
    
    // 최소 광고 길이 = 전체 길이 - 최대 공통 접두사/접미사 길이
    cout << L - failure[L - 1] << "\n";
    
    return 0;
}
```

### **예시 3: 문자열 제곱 (4354번)**
```cpp
#include <iostream>
#include <vector>
#include <string>

int getMaxRepetition(const string& s) {
    int n = s.length();
    vector<int> failure(n, 0);
    
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = failure[j - 1];
        }
        if (s[i] == s[j]) {
            failure[i] = ++j;
        }
    }
    
    int periodLength = n - failure[n - 1];
    
    // 주기가 전체 길이를 나누어 떨어뜨리면 반복 구조
    if (n % periodLength == 0) {
        return n / periodLength;
    }
    
    return 1;  // 반복 없음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    while (cin >> s && s != ".") {
        cout << getMaxRepetition(s) << "\n";
    }
    
    return 0;
}
```

---

## ⚡ **고급 테크닉**

### **1. Z 알고리즘과의 비교**
```cpp
// Z 알고리즘 (KMP의 대안)
vector<int> zAlgorithm(const string& s) {
    int n = s.length();
    vector<int> z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}
```

### **2. 다중 패턴 매칭 (Aho-Corasick 예고)**
```cpp
// 여러 패턴을 동시에 검색할 때는 Aho-Corasick 알고리즘 사용
// KMP를 트라이 구조로 확장한 형태
```

### **3. 순환 문자열 매칭**
```cpp
// 순환 문자열에서 패턴 찾기
bool findInCircularString(const string& text, const string& pattern) {
    string doubled = text + text;
    vector<int> matches = kmpSearch(doubled, pattern);
    
    for (int pos : matches) {
        if (pos < text.length()) {
            return true;
        }
    }
    return false;
}
```

---

## 🧮 **시간/공간 복잡도**

- **전처리 시간**: O(m) - 실패함수 계산
- **검색 시간**: O(n) - 텍스트 스캔
- **전체 시간**: O(n + m)
- **공간 복잡도**: O(m) - 실패함수 배열

기존 브루트 포스 O(nm)에서 O(n + m)으로 획기적 개선!

---

## 📝 **관련 문제**

### **기초**
- 1786: 찾기
- 16916: 부분 문자열

### **주기 패턴**
- 1305: 광고  
- 4354: 문자열 제곱
- 1701: Cubeditor

### **고급 응용**
- 1893: 시저 암호
- 5525: IOIOI
- 11585: 속타는 저녁 메뉴

### **관련 알고리즘**
- 아호-코라식: 다중 패턴 매칭
- 접미사 배열: 더 복잡한 문자열 처리
- 라빈-카프: 해시 기반 문자열 매칭

---

**🔑 핵심 포인트**:
- **실패함수**가 KMP의 핵심 - 정확히 이해하기
- **주기성 분석**에 매우 유용
- **선형 시간** 보장으로 대용량 텍스트 처리 가능
- **접두사-접미사** 개념이 다양한 문제에 응용됨