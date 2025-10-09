#include <string>
#include <vector>

#include <iostream>
#include <sstream>

using namespace std;

string chart[51][51];
pair<int, int> parent[51][51];

pair<int,int> find(int r, int c) {
    if (parent[r][c].first == r && parent[r][c].second == c) {
        return {r, c};
    }
    return parent[r][c] = find(parent[r][c].first, parent[r][c].second);
}

void unite(int r1, int c1, int r2, int c2, string& val) {
    auto [pr1, pc1] = find(r1, c1);
    auto [pr2, pc2] = find(r2, c2);
    
    if (pr1 == pr2 && pc1 == pc2)
        return;
    
    chart[pr1][pc1] = "";
    parent[pr1][pc1] = {pr2, pc2};
    chart[pr2][pc2] = val;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= 50; ++i)
        for (int j = 1; j <= 50; ++j)
            parent[i][j] = {i, j};
    
    for (string& command: commands)
    {
        stringstream ss(command);
        string cmd;
        
        ss >> cmd;
        if (cmd == "UPDATE")
        {
            string s1, s2, s3;  
            ss >> s1 >> s2;
            
            if (ss >> s3)
            {
                int r = stoi(s1), c = stoi(s2);
                auto [pr, pc] = find(r, c);
                chart[pr][pc] = s3;
            }
            else
            {
                for (int i = 1; i <= 50; ++i)
                {
                    for (int j = 1; j <= 50; ++j)
                    {
                        if (parent[i][j].first == i && parent[i][j].second == j)
                            if (chart[i][j] == s1)
                                chart[i][j] = s2;
                    }
                }
            }
        }
        else if (cmd == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            
            if (r1 == r2 && c1 == c2)
                continue;
            
            auto [pr1, pc1] = find(r1, c1);
            auto [pr2, pc2] = find(r2, c2);
            
            if (pr1 == pr2 && pc1 == pc2)
                continue;
            
            string mergeVal = chart[pr1][pc1];
            if (mergeVal.empty())
                mergeVal = chart[pr2][pc2];
            
            unite(pr1, pc1, pr2, pc2, mergeVal);
        }
        else if (cmd == "UNMERGE")
        {
            int r, c;
            ss >> r >> c;
            
            auto [pr, pc] = find(r, c);
            string val = chart[pr][pc];
            
            vector<pair<int, int>> cells;
            for (int i = 1; i <= 50; ++i)
            {
                for (int j = 1; j <= 50; ++j)
                {
                    auto [pi, pj] = find(i, j);
                    if (pi == pr && pj == pc)
                        cells.push_back({i, j});
                }
            }
            
            for (auto& [y, x]: cells)
            {
                parent[y][x] = {y, x};
                chart[y][x] = "";
            }
            chart[r][c] = val;
        }
        else
        {
            int r, c;
            ss >> r >> c;
            auto [pr, pc] = find(r, c);
            if (chart[pr][pc].empty())
                answer.push_back("EMPTY");
            else
                answer.push_back(chart[pr][pc]);
        }
    }
    
    return answer;
}