# 🔗 Union-Find (Disjoint Set)

> **난이도**: Gold  
> **대표 문제**: 20040(사이클 게임), 1976(여행 가자), 1717(집합의 표현)

---

## 🎯 **핵심 개념**

Union-Find는 **서로소 집합(Disjoint Set)**을 효율적으로 관리하는 자료구조입니다:
- **Find**: 원소가 속한 집합의 루트(대표원소)를 찾기
- **Union**: 두 집합을 하나로 합치기
- **주요 활용**: 사이클 감지, 연결성 확인, MST 구현

---

## 🔧 **기본 템플릿**

### **기본 Union-Find 구조**
```cpp
class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // 초기에는 자기 자신이 부모
        }
    }
    
    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 경로 압축
        }
        return parent[x];
    }
    
    // Union with Union by Rank
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false;  // 이미 같은 집합 = 사이클
        }
        
        // Union by Rank: 작은 트리를 큰 트리에 붙이기
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
    
    // 같은 집합인지 확인
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### **간단한 버전 (배열 기반)**
```cpp
int parent[MAX_SIZE];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);  // 경로 압축
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return false;  // 이미 연결됨
    
    parent[a] = b;  // 또는 parent[b] = a
    return true;
}

bool isConnected(int a, int b) {
    return find(a) == find(b);
}
```

---

## 💡 **풀이 패턴**

### **1. 사이클 감지 문제**
```cpp
// 간선을 하나씩 추가하면서 사이클 확인
int detectCycle(vector<pair<int, int>>& edges, int n) {
    UnionFind uf(n);
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        if (!uf.unionSets(u, v)) {
            return i + 1;  // 사이클이 생성된 간선 번호
        }
    }
    return 0;  // 사이클 없음
}
```

### **2. 연결성 확인 문제**
```cpp
// 쿼리 처리: 두 노드가 연결되어 있는가?
void processQueries(vector<tuple<int, int, int>>& queries, int n) {
    UnionFind uf(n);
    
    for (auto [op, a, b] : queries) {
        if (op == 0) {  // union 연산
            uf.unionSets(a, b);
        } else {        // find 연산
            if (uf.isConnected(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
```

### **3. MST에서의 활용 (크루스칼 알고리즘)**
```cpp
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

long long kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    
    long long mstWeight = 0;
    int edgeCount = 0;
    
    for (const Edge& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgeCount++;
            
            if (edgeCount == n - 1) break;  // MST 완성
        }
    }
    
    return edgeCount == n - 1 ? mstWeight : -1;  // 연결 불가능
}
```

---

## 🔍 **실제 예시**

### **예시 1: 사이클 게임 (20040번)**
```cpp
#include <iostream>
#include <vector>

class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        parent[rootX] = rootY;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n);
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        
        if (!uf.unionSets(a, b)) {
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << 0 << "\n";
    return 0;
}
```

### **예시 2: 집합의 표현 (1717번)**
```cpp
#include <iostream>
#include <vector>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    function<int(int)> find = [&](int x) -> int {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    auto unionSets = [&](int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    };
    
    auto isConnected = [&](int x, int y) {
        return find(x) == find(y);
    };
    
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        
        if (op == 0) {
            unionSets(a, b);
        } else {
            cout << (isConnected(a, b) ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}
```

---

## ⚡ **최적화 기법**

### **1. 경로 압축 (Path Compression)**
```cpp
// 재귀 버전
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 경로 압축
    }
    return parent[x];
}

// 반복 버전 (스택 오버플로우 방지)
int findIterative(int x) {
    int root = x;
    while (parent[root] != root) {
        root = parent[root];
    }
    
    // 경로 압축
    while (parent[x] != x) {
        int next = parent[x];
        parent[x] = root;
        x = next;
    }
    
    return root;
}
```

### **2. Union by Rank/Size**
```cpp
class OptimizedUnionFind {
private:
    vector<int> parent, size;
    
public:
    OptimizedUnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // 크기가 작은 트리를 큰 트리에 붙이기
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
};
```

### **3. 분리된 집합 개수 추적**
```cpp
class UnionFindWithCount {
private:
    vector<int> parent;
    int componentCount;
    
public:
    UnionFindWithCount(int n) : parent(n), componentCount(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        parent[rootX] = rootY;
        componentCount--;  // 두 집합이 합쳐지므로 개수 감소
        return true;
    }
    
    int getComponentCount() const {
        return componentCount;
    }
};
```

---

## 🧮 **시간 복잡도**

- **Find**: O(α(n)) ≈ O(1) (아커만 함수 역함수)
- **Union**: O(α(n)) ≈ O(1)  
- **전체**: m개 연산에 대해 O(m × α(n)) ≈ O(m)

여기서 α(n)은 실용적인 모든 n에 대해 5 이하의 매우 작은 상수입니다.

---

## 📝 **관련 문제**

### **기초**
- 1717: 집합의 표현
- 1976: 여행 가자  
- 10775: 공항

### **사이클 감지**
- 20040: 사이클 게임
- 1043: 거짓말

### **MST (최소 스패닝 트리)**
- 1197: 최소 스패닝 트리
- 1647: 도시 분할 계획

### **고급 응용**
- 4195: 친구 네트워크 (크기 추적)
- 3830: 교수님은 기다리지 않는다 (가중치 Union-Find)

---

**🔑 핵심 포인트**:
- **사이클 감지**: merge() 실패 시 사이클 존재
- **경로 압축** 반드시 구현하기
- **Union by Rank/Size**로 더욱 최적화 가능
- **시간복잡도**: 거의 O(1)에 가까운 매우 빠른 자료구조