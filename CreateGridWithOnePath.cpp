// LeetCode 3963
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string;

static int m = 2;
static int n = 3;

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<string>& results);
        public:
            vector<string> createGrid(int m, int n);
    };

    void Program::prettyPrint(vector<string>& results) {
        cout << "{ ";
        for (const string& s : results)
            cout << s << " ";
        cout << "}\n" << endl;
    }

    vector<string> Program::createGrid(int m, int n) {
        vector<string> result(m, string(n, '#'));
        
        for (int i=0; i<m; i++)
            result[i][0] = '.';
        for (int j=0; j<n; j++)
            result[m-1][j] = '.';
        
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.createGrid(m, n);
    return 0;
}