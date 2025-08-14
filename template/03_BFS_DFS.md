# 🌊 BFS & DFS (그래프 탐색)

> **난이도**: Silver ~ Gold  
> **대표 문제**: 2606(바이러스), 2667(단지번호붙이기), 7576(토마토), 2206(벽 부수고 이동하기)

---

## 🎯 **핵심 개념**

그래프 탐색의 두 기본 알고리즘:
- **BFS (너비 우선 탐색)**: 가까운 노드부터 차례대로 탐색, **최단거리** 보장
- **DFS (깊이 우선 탐색)**: 한 방향으로 끝까지 탐색 후 백트래킹, **경로 탐색**에 유리

---

## 🔧 **BFS 기본 템플릿**

### **기본 BFS 구조**
```cpp
#include <queue>
#include <vector>

int dx[] = {-1, 1, 0, 0};  // 상하좌우
int dy[] = {0, 0, -1, 1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // 현재 위치 처리
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // 방문 체크 & 조건 체크
            if (!visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
```

### **거리 정보 포함 BFS**
```cpp
struct Node {
    int x, y, dist;
};

int bfsDistance(int startX, int startY, int endX, int endY) {
    queue<Node> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    q.push({startX, startY, 0});
    dist[startX][startY] = 0;
    
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        
        if (curr.x == endX && curr.y == endY) {
            return curr.dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                dist[nx][ny] == -1 && grid[nx][ny] == 1) {
                
                dist[nx][ny] = curr.dist + 1;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }
    return -1;  // 도달 불가능
}
```

---

## 🌳 **DFS 기본 템플릿**

### **재귀 DFS**
```cpp
vector<vector<bool>> visited;

void dfs(int x, int y) {
    visited[x][y] = true;
    
    // 현재 위치 처리
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
            !visited[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}
```

### **스택 기반 DFS**
```cpp
void dfsIterative(int startX, int startY) {
    stack<pair<int, int>> st;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    st.push({startX, startY});
    
    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        
        if (visited[x][y]) continue;
        visited[x][y] = true;
        
        // 현재 위치 처리
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                !visited[nx][ny] && grid[nx][ny] == 1) {
                st.push({nx, ny});
            }
        }
    }
}
```

---

## 💡 **풀이 패턴**

### **1. 연결된 컴포넌트 개수**
```cpp
int countComponents() {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                // BFS 또는 DFS로 연결된 모든 셀 방문
                bfs(i, j, visited);
                components++;
            }
        }
    }
    return components;
}
```

### **2. 각 컴포넌트의 크기**
```cpp
int componentSize(int startX, int startY, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int size = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        size++;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return size;
}
```

### **3. 동시 다발적 BFS (토마토 문제)**
```cpp
int simultaneousBFS() {
    queue<pair<int, int>> q;
    int unripe = 0;
    
    // 익은 토마토들을 모두 큐에 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
            } else if (grid[i][j] == 0) {
                unripe++;
            }
        }
    }
    
    int days = 0;
    
    while (!q.empty() && unripe > 0) {
        int qSize = q.size();
        
        // 현재 레벨의 모든 토마토 처리
        for (int i = 0; i < qSize; i++) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                    unripe--;
                }
            }
        }
        days++;
    }
    
    return unripe == 0 ? days : -1;
}
```

---

## 🔍 **실제 예시**

### **예시 1: 바이러스 (2606번)**
```cpp
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    int infected = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                infected++;
            }
        }
    }
    
    cout << infected << "\n";
    return 0;
}
```

### **예시 2: 단지번호붙이기 (2667번)**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<string>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 0;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        size++;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                !visited[nx][ny] && grid[nx][ny] == '1') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return size;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> complexSizes;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                int size = bfs(grid, visited, i, j);
                complexSizes.push_back(size);
            }
        }
    }
    
    sort(complexSizes.begin(), complexSizes.end());
    
    cout << complexSizes.size() << "\n";
    for (int size : complexSizes) {
        cout << size << "\n";
    }
    
    return 0;
}
```

---

## ⚡ **고급 테크닉**

### **1. 상태를 포함한 BFS**
```cpp
// 벽 부수고 이동하기 (2206번)
struct State {
    int x, y, dist, broken;
};

int bfsWithState() {
    queue<State> q;
    bool visited[n][m][2];  // [x][y][벽을 부쉈는지 여부]
    memset(visited, false, sizeof(visited));
    
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        if (curr.x == n-1 && curr.y == m-1) {
            return curr.dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // 일반 이동
            if (grid[nx][ny] == 0 && !visited[nx][ny][curr.broken]) {
                visited[nx][ny][curr.broken] = true;
                q.push({nx, ny, curr.dist + 1, curr.broken});
            }
            
            // 벽 부수고 이동 (아직 벽을 부수지 않았다면)
            if (grid[nx][ny] == 1 && curr.broken == 0 && !visited[nx][ny][1]) {
                visited[nx][ny][1] = true;
                q.push({nx, ny, curr.dist + 1, 1});
            }
        }
    }
    return -1;
}
```

### **2. 양방향 BFS**
```cpp
int bidirectionalBFS(int start, int end) {
    if (start == end) return 0;
    
    queue<int> q1, q2;
    unordered_map<int, int> visited1, visited2;
    
    q1.push(start);
    q2.push(end);
    visited1[start] = 0;
    visited2[end] = 0;
    
    while (!q1.empty() || !q2.empty()) {
        // 더 작은 큐를 확장
        if (q1.size() <= q2.size()) {
            int level = expandLevel(q1, visited1, visited2);
            if (level != -1) return level;
        } else {
            int level = expandLevel(q2, visited2, visited1);
            if (level != -1) return level;
        }
    }
    return -1;
}
```

---

## 📝 **관련 문제**

### **기초 BFS/DFS**
- 1260: DFS와 BFS
- 2606: 바이러스
- 2667: 단지번호붙이기
- 1012: 유기농 배추

### **최단거리 BFS**
- 7576: 토마토
- 7569: 토마토 (3D)
- 2178: 미로 탐색
- 1697: 숨바꼭질

### **고급 BFS**
- 2206: 벽 부수고 이동하기
- 13460: 구슬 탈출 2
- 16236: 아기 상어
- 9019: DSLR

### **트리 DFS**
- 11725: 트리의 부모 찾기
- 1167: 트리의 지름
- 15681: 트리와 쿼리

---

**🔑 핵심 포인트**:
- **BFS**: 최단거리, 레벨별 처리
- **DFS**: 경로 탐색, 깊은 분석
- **상태 공간**: 필요시 추가 차원으로 상태 표현
- **메모리 관리**: visited 배열 적절히 활용