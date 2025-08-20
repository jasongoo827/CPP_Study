#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s, p;
    string dna;
    int a, c, g, t;
    int freq[4] = {0};
    
    cin >> s >> p >> dna >> a >> c >> g >> t;
    
    for (int i = 0; i < p; ++i)
    {
        if (dna[i] == 'A') freq[0]++;
        else if (dna[i] == 'C') freq[1]++;
        else if (dna[i] == 'G') freq[2]++;
        else if (dna[i] == 'T') freq[3]++;
    }
    
    int ret = 0;
    
    if (freq[0] >= a && freq[1] >= c && freq[2] >= g && freq[3] >= t)
        ret++;
    
    for (int i = 1; i <= s - p; ++i)
    {
        char leftChar = dna[i - 1];
        if (leftChar == 'A') freq[0]--;
        else if (leftChar == 'C') freq[1]--;
        else if (leftChar == 'G') freq[2]--;
        else if (leftChar == 'T') freq[3]--;
        
        char rightChar = dna[i + p - 1];
        if (rightChar == 'A') freq[0]++;
        else if (rightChar == 'C') freq[1]++;
        else if (rightChar == 'G') freq[2]++;
        else if (rightChar == 'T') freq[3]++;
        
        if (freq[0] >= a && freq[1] >= c && freq[2] >= g && freq[3] >= t)
            ret++;
    }
    
    cout << ret;
    
    return 0;
}