#include <string>
#include <vector>

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    unordered_map<char, int> termPair;
    
    for (const string& term: terms)
        termPair[term[0]] = stoi(term.substr(2));
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        string date = privacies[i].substr(0, 10);
        int months = termPair[privacies[i].back()];
        
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
                
        m += months;
        y += (m - 1) / 12;
        m = (m - 1) % 12 + 1;
        
        if (--d == 0)
        {
            d = 28;
            if (--m == 0)
            {
                m = 12;
                y--;
            }
        }
        
        string expiry = to_string(y) + "." + 
                       (m < 10 ? "0" : "") + to_string(m) + "." +
                       (d < 10 ? "0" : "") + to_string(d);
        
        if (expiry < today)
            answer.push_back(i + 1);
    }
    
    return answer;
}