#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <format>

using std::cout, std::endl, std::vector, std::priority_queue, std::set, std::pair, std::unordered_set;

static int k = 3;
static vector<int> arrival { 1, 2, 3, 4, 8, 9, 10 };
static vector<int> load { 5, 2, 10, 3, 1, 2, 2 };

namespace Solution {
    class Compare {
        public:
            bool operator()(const pair<int,int>& item1, const pair<int,int>& item2) const { return item1.second > item2.second; }
    };
    class Program {
        private:
            bool requestAssigned(int load, int requestID);
            void handleRequests(int timePassed);

            int numServers;
            int maxTraffic;
            unordered_set<int> servers;
            vector<int> numRequestsHandled;
            set<int> available;
            priority_queue<pair<int,int>, std::vector<pair<int,int>>, Compare> queueTimes;
        
        public:
            vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load);
    };

    bool Program::requestAssigned(int endTime, int requestID) {
        if (available.size() == 0) return false;

        int server = (requestID % numServers) - 1;
        set<int>::iterator itr = available.upper_bound(server); // ITS GUARANTEED TO HAVE 1 SERVER AVAILABLE
        if (itr == available.end())
            itr = available.upper_bound(-1);
        server = *itr;
        queueTimes.push({ server, endTime });
        available.erase(server);
        numRequestsHandled[server]++;
        cout << std::format("server {}: Requests Handled --> {} | Finish Time --> {}", server, numRequestsHandled[server], endTime) << endl;

        if (numRequestsHandled[server] == maxTraffic && !servers.contains(server)) servers.insert(server);
        else if (numRequestsHandled[server] > maxTraffic) {
            servers.clear();
            servers.insert(server);
            maxTraffic = numRequestsHandled[server];
        }

        return true;
    }

    void Program::handleRequests(int currTime) {
        pair<int,int> item = queueTimes.top();
        while (item.second <= currTime && !queueTimes.empty()) {
            cout << std::format("Server {}: finished request, now free @ time {}", item.first, currTime) << endl;
            queueTimes.pop();
            available.insert(item.first);
            item = queueTimes.top();
        }
    }

    vector<int> Program::busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        numRequestsHandled.resize(k);
        numServers = k;
        for (int i=0; i<k; i++) available.insert(i);
        
        int currTime = arrival[0], endTime = arrival[0] + load[0];
        requestAssigned(endTime, 0);

        for (int i=1; i<arrival.size(); i++) {
            currTime = arrival[i];
            endTime = arrival[i] + load[i];
            handleRequests(currTime);
            requestAssigned(endTime, i);
        }

        return vector<int>(servers.begin(), servers.end());
    }
}

int main() {
    using namespace Solution;
    Program obj;
    vector<int> result = obj.busiestServers(k, arrival, load);
    cout << "{ ";
    for (int i : result) cout << i << " ";
    cout << "}\n\n" << endl;
    return 0;
}