// LeetCode 2559
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout, std::endl;
using std::string, std::vector;
using std::unordered_map;

static vector<string> words { "aba", "bcb", "ece", "aa", "e" };
static vector<vector<int>> queries { {0, 2}, {1, 4}, {1, 1} };
static vector<string> words1 { "a", "e", "i" };
static vector<vector<int>> queries1 { {0, 2}, {0, 1}, {2, 2} };

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries);
bool checkVowel(string word, unordered_map<char, int>& dict);


vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<char> vowels { 'a', 'e', 'i', 'o', 'u' };
    unordered_map<char, int> dict;
    for (char c : vowels)
        dict[c] = 1;
    
    for (auto it=queries.begin(); it!=queries.end(); it++) {
        ans.push_back(0);
        for (int i = (*it)[0]; i<=(*it)[1]; i++)
            if (checkVowel(words[i], dict)) ans[ans.size()-1]++;
    }

    return ans;
}

bool checkVowel(string word, unordered_map<char, int>& dict) {
    if (dict.contains(word.front()) && dict.contains(word.back())) return true;
    return false;
}

int main() {
    for (int i : vowelStrings(words, queries))
        cout << i << " ";
    cout << endl;

    for (int i : vowelStrings(words1, queries1))
        cout << i << " ";
    cout << endl;
    return 0;
}