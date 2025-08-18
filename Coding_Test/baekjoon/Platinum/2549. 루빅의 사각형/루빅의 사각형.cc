#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

using Board = vector<vector<int>>;

struct Move {
    int type;  // 0: row, 1: col
    int index; // 행/열 번호 (0~3)
    int count; // 이동 칸수 (1~3)
};

uint64_t getHash(const Board& board) {
    uint64_t hash = 0;
    uint64_t base = 17;
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            hash = hash * base + board[i][j];
    return hash;
}

Board rotateRow(const Board& board, int row, int count) {
    Board ret = board;
    for (int i = 0; i < 4; ++i)
        ret[row][(i + count) % 4] = board[row][i];
    return ret;
}

Board rotateCol(const Board& board, int col, int count) {
    Board ret = board;
    for (int i = 0; i < 4; ++i)
        ret[(i + count) % 4][col] = board[i][col];
    return ret;
}

Move reverseMove(const Move& move) {
    return {move.type, move.index, 4 - move.count};
}

void printPath(const vector<Move>& path) {
    for (const auto& move : path) {
        cout << move.type + 1 << " " << move.index + 1 << " " << move.count << "\n";
    }
}

// 경로 복원 함수 (수정됨)
vector<Move> reconstructPath(uint64_t hash, 
                           const unordered_map<uint64_t, pair<uint64_t, Move>>& parent,
                           bool reverse = false) {
    vector<Move> path;
    uint64_t curr = hash;
    
    while (parent.count(curr)) {
        auto [parentHash, move] = parent.at(curr);
        path.push_back(reverse ? reverseMove(move) : move);
        curr = parentHash;
    }
    
    // reverse가 false일 때만 경로를 뒤집음 (start -> meeting point 순서로 만들기 위해)
    if (!reverse) {
        std::reverse(path.begin(), path.end());
    }
    
    return path;
}

int handleMeeting(const Move& currentMove, uint64_t currentHash, uint64_t nextHash,
                 int currentDepth, bool isFront,
                 const unordered_map<uint64_t, int>& otherVisited,
                 const unordered_map<uint64_t, pair<uint64_t, Move>>& frontParent,
                 const unordered_map<uint64_t, pair<uint64_t, Move>>& backParent) {
    
    vector<Move> frontPath, backPath;
    
    if (isFront) {
        // 앞쪽에서 만남: start -> currentHash -> nextHash <- target
        frontPath = reconstructPath(currentHash, frontParent, false);
        frontPath.push_back(currentMove);  // 마지막 이동 추가
        
        backPath = reconstructPath(nextHash, backParent, true);
        
    } else {
        // 뒤쪽에서 만남: start -> nextHash <- currentHash <- target
        frontPath = reconstructPath(nextHash, frontParent, false);
        
        backPath = reconstructPath(currentHash, backParent, true);
        backPath.insert(backPath.begin(), reverseMove(currentMove));  // 첫 번째 이동 추가
    }
    
    int totalMoves = currentDepth + 1 + otherVisited.at(nextHash);
    cout << totalMoves << "\n";
    printPath(frontPath);
    printPath(backPath);
    
    return totalMoves;
}

bool expandStates(queue<pair<Board, int>>& myQueue, 
                 unordered_map<uint64_t, int>& myVisited,
                 unordered_map<uint64_t, pair<uint64_t, Move>>& myParent,
                 const unordered_map<uint64_t, int>& otherVisited,
                 const unordered_map<uint64_t, pair<uint64_t, Move>>& frontParent,
                 const unordered_map<uint64_t, pair<uint64_t, Move>>& backParent,
                 bool isFront) {
    
    if (myQueue.empty()) return false;
    
    auto [board, depth] = myQueue.front();
    myQueue.pop();
    
    if (depth >= 4) return false;  // 최대 깊이 제한
    
    uint64_t currentHash = getHash(board);
    
    // 모든 가능한 이동 시도
    for (int type = 0; type < 2; ++type) {  // 0: row, 1: col
        for (int index = 0; index < 4; ++index) {
            for (int count = 1; count <= 3; ++count) {
                Board next = (type == 0) ? rotateRow(board, index, count) 
                                        : rotateCol(board, index, count);
                uint64_t nextHash = getHash(next);
                
                // 다른 방향에서 이미 방문한 상태를 만남
                if (otherVisited.count(nextHash)) {
                    Move currentMove = {type, index, count};
                    handleMeeting(currentMove, currentHash, nextHash, depth, isFront,
                                otherVisited, frontParent, backParent);
                    return true;
                }
                
                // 처음 방문하는 상태
                if (!myVisited.count(nextHash)) {
                    myVisited[nextHash] = depth + 1;
                    myParent[nextHash] = {currentHash, {type, index, count}};
                    myQueue.push({next, depth + 1});
                }
            }
        }
    }
    
    return false;
}

void bidirectionalBFS(Board& start, Board& target) {
    if (start == target) {
        cout << "0\n";
        return;
    }
    
    queue<pair<Board, int>> frontQueue, backQueue;
    unordered_map<uint64_t, int> frontVisited, backVisited;
    unordered_map<uint64_t, pair<uint64_t, Move>> frontParent, backParent;
    
    uint64_t startHash = getHash(start);
    uint64_t targetHash = getHash(target);
    
    frontQueue.push({start, 0});
    backQueue.push({target, 0});
    frontVisited[startHash] = 0;
    backVisited[targetHash] = 0;
    
    while (!frontQueue.empty() || !backQueue.empty()) {
        // 더 작은 큐를 먼저 확장하여 균형 유지
        bool expandFront = !frontQueue.empty() && 
                          (backQueue.empty() || frontQueue.size() <= backQueue.size());
        
        if (expandFront) {
            // 앞쪽 확장
            if (expandStates(frontQueue, frontVisited, frontParent, backVisited,
                            frontParent, backParent, true)) {
                return;
            }
        } else {
            // 뒤쪽 확장
            if (expandStates(backQueue, backVisited, backParent, frontVisited,
                            frontParent, backParent, false)) {
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Board start(4, vector<int>(4));
    Board target{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> start[i][j];
    
    bidirectionalBFS(start, target);
    
    return 0;
}