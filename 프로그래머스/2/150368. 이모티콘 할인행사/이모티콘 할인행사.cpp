#include <string>
#include <vector>

#include <iostream>

using namespace std;

void dfs(int n, vector<int>& selected, vector<vector<int>>& ret)
{
    if (selected.size() == n)
    {
        ret.push_back(selected);
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        selected.push_back(i);
        dfs(n, selected, ret);
        selected.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    int n = emoticons.size();
    vector<vector<int>> subsets;
    vector<int> selected;
    dfs(n, selected, subsets);
    
    int maxSub = 0;
    int maxSell = 0;
    
    vector<int> sale = {10, 20, 30, 40};
    for (const auto& subset: subsets)
    {   
        int sub = 0;
        int totalSell = 0;
        for (const auto& user: users)
        {
            int sell = 0;
            for (int i = 0; i < subset.size(); ++i)
            {
                if (user[0] <= sale[subset[i]])
                    sell += emoticons[i] * (100 - sale[subset[i]]) / 100;
            }
            if (sell >= user[1])
                sub++;
            else
                totalSell += sell;
        }
        if (maxSub < sub)
        {
            maxSub = sub;
            maxSell = totalSell;
            answer = {sub, totalSell};
        }
        else if (maxSub == sub)
        {
            if (maxSell < totalSell)
            {
                maxSell = totalSell;
                answer = {sub, totalSell};
            }
        }
    }
    
    return answer;
}