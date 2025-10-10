// LeetCode 3147
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> energy { 5,2,-10,-5,1 };
static int k = 3;

namespace Solution {
    class Program {
        public:
            int maximumEnergy(vector<int>& energy, int k);
    };

    int Program::maximumEnergy(vector<int>& energy, int k) {
        vector<int> arr(energy.size(), 0);
        int maxEnergy = INT_MIN;

        int numMagicians = energy.size();
        int i=numMagicians-1;
        for (; i>=numMagicians-k; i--) {
            arr[i] = energy[i];
            maxEnergy = max(arr[i], maxEnergy);
        }

        for (; i>0; i--) {
            arr[i] = arr[i+k] + energy[i];
            maxEnergy = max(arr[i], maxEnergy);
        }

        return maxEnergy; 
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumEnergy(energy, k) << endl;
    return 0;
}