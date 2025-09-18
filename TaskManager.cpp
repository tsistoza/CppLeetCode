// LeetCode 3408
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

#define DEBUG false

using std::cout, std::endl, std::vector;
using std::max, std::map, std::pair;


static vector<vector<int>> tasks { { 1, 101, 10 }, { 2, 102, 20 }, { 3, 103, 15} };

namespace Solution {
    class TaskManager {
        private:
            vector<vector<int>> taskQueue;
            map<int, pair<int,int>> indexes; // { taskId, {userId, priority} }

            void currQueue();
            pair<int,int> findIndex(int priority);
        public:
            void add(int userId, int taskId, int priority);
            void edit(int taskId, int newPriority);
            void rmv(int taskId);
            int execTop();

            TaskManager(vector<vector<int>>& tasks);
    };

    void TaskManager::currQueue() {
        for (int i=0; i<taskQueue.size(); i++)
            cout << "taskQueue[" << i << "]=" << "{ " << taskQueue[i][0] << ", " << taskQueue[i][1] << ", " << taskQueue[i][2] << "}" << endl;
        cout << endl;
        return;
    }

    pair<int,int> TaskManager::findIndex(int priority) {
        int low = 0, high = taskQueue.size()-1;
        while (low < high) {
            int mid = low + (high-low) / 2;
            if (taskQueue[mid][2] == priority) {
                low = mid;
                high = mid;
                break;
            }
            
            if (taskQueue[mid][2] > priority)
                low = mid + 1;
            if (taskQueue[mid][2] < priority)
                high = mid - 1;
        }

        int indexL = low, indexR = high;
        if (low < 0 || low > taskQueue.size()) indexL = high;
        if (high < 0 || high > taskQueue.size()) indexR = low;

        return { indexL, indexR };
    }

    void TaskManager::add(int userId, int taskId, int priority) {
        vector<int> task { userId, taskId, priority };
        if (taskQueue.size() == 0) {
            taskQueue.push_back(task);
            indexes[taskId] = { userId, priority };
            return;
        }

        pair<int,int> p1 = findIndex(priority);

        int index = max(p1.first, p1.second);

        #if DEBUG
        cout << "index=" << index << endl;
        cout << "taskQueue = " << taskQueue[index][2] << endl;
        #endif

        if (taskQueue[index][2] < priority) taskQueue.insert(taskQueue.begin()+index, task);
        if (taskQueue[index][2] > priority) taskQueue.insert(taskQueue.begin()+index+1, task);

        indexes[taskId] = { userId, priority };

        #if DEBUG
        cout << "current task: {" << userId << ", " << taskId << ", " << priority << "}" << endl;
        currQueue();
        #endif

        return;
    }

    void TaskManager::edit(int taskId, int newPriority) {
        int userId = indexes[taskId].first;
        rmv(taskId);
        add(userId, taskId, newPriority);
        
        #if DEBUG
        cout << "Editting..." << endl;
        currQueue();
        #endif
        return;
    }

    void TaskManager::rmv(int taskId) {
        int priority = indexes[taskId].second;

        pair<int,int> index = findIndex(priority);

        if (taskQueue[index.first][2] == priority) taskQueue.erase(taskQueue.begin()+index.first);
        else taskQueue.erase(taskQueue.begin()+index.second);

        indexes.erase(taskId);

        #if DEBUG
        cout << "Removing..." << endl;
        currQueue();
        #endif

        return;
    }

    int TaskManager::execTop() {
        if (taskQueue.size() == 0) return -1;
        vector<int> task {taskQueue[0]};
        
        taskQueue.erase(taskQueue.begin());
        indexes.erase(task[1]);

        #if DEBUG
        cout << "Executing..." << endl;
        currQueue();
        #endif

        return task[0];
    }

    TaskManager::TaskManager(vector<vector<int>>& tasks) {
        for (int i=0; i<tasks.size(); i++)
            add(tasks[i][0], tasks[i][1], tasks[i][2]);
        return;
    }
}

int main() {
    using namespace Solution;
    TaskManager* tm = new TaskManager(tasks);
    tm->add(4, 104, 5);
    tm->edit(102, 8);
    cout << tm->execTop() << endl;
    tm->rmv(101);
    tm->add(5, 105, 15);
    cout << tm->execTop() << endl;
    delete tm;
    return 0;
}