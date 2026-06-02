// LeetCode 3633
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::min;

static vector<int> landStartTime { 2, 8 };
static vector<int> landDuration { 4, 1 };
static vector<int> waterStartTime { 6 };
static vector<int> waterDuration { 3 };

namespace Solution {
    class Program {
        public:
            int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration);
    };

    int Program::earliestFinishTime(vector<int> & landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minimumTime = INT_MAX;
        for (int i=0; i<landStartTime.size(); i++) {
            for (int j=0; j<waterStartTime.size(); j++) {
                int time = landStartTime[i] + landDuration[i];
                if (time < waterStartTime[j])
                    time = waterStartTime[j];
                minimumTime = min(minimumTime, time + waterDuration[j]);


                // Reverse
                time = waterStartTime[j] + waterDuration[j];
                if (time < landDuration[i])
                    time = landStartTime[i];
                minimumTime = min(minimumTime, time + landDuration[i]);
            }
        }

        return minimumTime;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}