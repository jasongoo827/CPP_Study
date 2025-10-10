#include <string>
#include <vector>

#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, pair<int, int>> charToIdx;
    char type[4][2] = {{'R', 'T'},{'C', 'F'}, {'J', 'M'}, {'A', 'N'}}; 
    int scores[4][2] = {0};
    
    charToIdx['R'] = {0, 0}, charToIdx['T'] = {0, 1};
    charToIdx['C'] = {1, 0}, charToIdx['F'] = {1, 1};
    charToIdx['J'] = {2, 0}, charToIdx['M'] = {2, 1};
    charToIdx['A'] = {3, 0}, charToIdx['N'] = {3, 1};
    
    int n = survey.size();
    for (int i = 0; i < n; ++i)
    {
        char c1 = survey[i][0];
        char c2 = survey[i][1];
        
        if (choices[i] < 4)
        {
            auto [y, x] = charToIdx[c1];
            scores[y][x] += abs(choices[i] - 4);
        }
        else if (choices[i] > 4)
        {
            auto [y, x] = charToIdx[c2];
            scores[y][x] += abs(choices[i] - 4);
        }
    }
    
    for (int i = 0; i < 4; ++i)
    {
        if (scores[i][0] >= scores[i][1])
            answer += type[i][0];
        else
            answer += type[i][1];
    }
    
    return answer;
}