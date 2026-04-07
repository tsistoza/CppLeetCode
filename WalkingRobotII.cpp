// LeetCode 2069
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

namespace Solution {
    class Robot {
        private:
            int currRow;
            int currCol;
            int maxRow;
            int maxCol;
            char currDirection;

        public:
            Robot(int width, int height) {
                this->currRow = 0;
                this->currCol = 0;
                this->maxRow = height;
                this->maxCol = width;
                this->currDirection = 'E';
            }

            static void prettyPrint(vector<int> pos);
            void step(int num);
            vector<int> getPos();
            string getDir();
    };

    void Robot::prettyPrint(vector<int> pos) {
        cout << " Position: { " << pos[1] << ", " << pos[0] << " } " << endl;
        return;
    }

    void Robot::step(int num) {
        while (num > 0) {
            if (currDirection == 'E') {
                int newCol = currCol + num;
                if (newCol < maxCol) {
                    currCol = newCol;
                    break;
                }

                num -= (maxCol - 1 - currCol);
                currCol = maxCol-1;
                currDirection = 'N';
            } else if (currDirection == 'N') {
                int newRow = currRow + num;
                if (newRow < maxRow) {
                    currRow = newRow;
                    break;
                }

                num -= (maxRow - 1 - currRow);
                currRow = maxRow-1;
                currDirection = 'W';
            } else if (currDirection == 'W') {
                int newCol = currCol - num;
                if (newCol >= 0) {
                    currCol = newCol;
                    break;
                }

                num -= currCol;
                currCol = 0;
                currDirection = 'S';
            } else {
                int newRow = currRow - num;
                if (newRow >= 0) {
                    currRow = newRow;
                    break;
                }

                num -= currRow;
                currRow = 0;
                currDirection = 'E';
            }
        }
        return;
    }

    vector<int> Robot::getPos() {
        return vector<int> { currRow, currCol };
    }

    string Robot::getDir() {
        string direction;
        switch (currDirection) {
            case 'E': direction = "EAST";
                break;
            case 'N': direction = "NORTH";
                break;
            case 'W': direction = "WEST";
                break;
            default: direction = "SOUTH";
                break;
        }
        return direction;
    }
}

int main() {
    using namespace Solution;
    Robot* robot = new Robot(6, 3);
    robot->step(2);
    robot->step(2);
    Robot::prettyPrint(robot->getPos());
    cout << robot->getDir() << endl;
    robot->step(2);
    robot->step(1);
    robot->step(4);
    Robot::prettyPrint(robot->getPos());
    cout << robot->getDir() << endl;
    return 0;
}