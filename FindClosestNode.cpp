// LeetCode 2359
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::pair, std::priority_queue, std::unordered_map;
using std::min, std::max;

static vector<int> edges { 1,2,0,4,5,3 };
static int node1 = 0;
static int node2 = 2;

namespace Solution {
    class Compare {
        public:
            bool operator() (pair<int,int>& p1, pair<int,int>& p2) const { return p1.second > p2.second; }
    };
    class Program {
        public:
            int closestMeetingNode(vector<int>& edges, int node1, int node2);
    };

    int Program::closestMeetingNode(vector<int>& edges, int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> dfsQ1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> dfsQ2;
        unordered_map<int,int> n1;
        unordered_map<int,int> n2;

        dfsQ1.push({ node1, 0 });
        dfsQ2.push({ node2, 0 });
        
        int minDistNode = edges.size();
        int minMaxDist = INT_MAX;
        pair<int,int> lastPair1 { node1, 0 };
        pair<int,int> lastPair2 { node2, 0 };
        while(!dfsQ1.empty() || !dfsQ2.empty()) {
            pair<int,int> currPtr1 = lastPair1, currPtr2 = lastPair2;
            if (!dfsQ1.empty()) {
                currPtr1 = dfsQ1.top();
                n1[currPtr1.first] = currPtr1.second;
                dfsQ1.pop();
            }
            if (!dfsQ2.empty()) {
                currPtr2 = dfsQ2.top();
                n2[currPtr2.first] = currPtr2.second;
                dfsQ2.pop();
            }

            if (n2.contains(currPtr1.first)) {
                int newMinMaxDist = max(n1[currPtr1.first], n2[currPtr1.first]);
                minDistNode = (minMaxDist > max(n1[currPtr1.first], n2[currPtr1.first])) ? currPtr1.first : minDistNode;
                minMaxDist = newMinMaxDist;
            }
            if (n1.contains(currPtr2.first)) {
                int newMinMaxDist = max(n1[currPtr2.first], n2[currPtr2.first]);
                minDistNode = (minMaxDist > max(n1[currPtr2.first], n2[currPtr2.first])) ? currPtr2.first : minDistNode;
                minMaxDist = newMinMaxDist;
            }

            if (edges[currPtr1.first] != -1 && !n1.contains(edges[currPtr1.first])) {
                dfsQ1.push( {edges[currPtr1.first], currPtr1.second+1 } );
                lastPair1 = currPtr1;
            }

            if (edges[currPtr2.first] != -1 && !n2.contains(edges[currPtr2.first])) {
                dfsQ2.push( {edges[currPtr2.first], currPtr2.second+1 } );
                lastPair2 = currPtr2;
            }
        }
        return (minDistNode == edges.size()) ? -1 : minDistNode;

    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.closestMeetingNode(edges, node1, node2) << endl;
    return 0;
}