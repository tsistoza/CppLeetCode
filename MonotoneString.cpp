#include <iostream>
#include <string>
#include <vector>
using std::cout,std::cin;
using std::string,std::vector;

namespace Solution 
{
    class Program
    {
        public:
            int minFlipsMonoIncr(string s){
                vector<char> findone;
                int flipOnes=0,flipZeros=0;
                for(string::iterator it=s.begin() ; it!=s.end() ; it++){

                    if((char)*it == '1' && findone.empty())     //FIND THE FIRST ONE
                        findone.push_back((char)*it);
                    if (!findone.empty() && (char)*it == '0')   //IF ONE IS FOUND, FLIP ALL ZEROS
                        flipZeros++;
                    else if(!findone.empty() && (char)*it == '1')//FLIP ONES
                        flipOnes++;

                }
                return std::min(flipZeros,flipOnes); //RETURN THE MIN
            }
    };
}

int main(){
    Solution::Program soln;
    int result = soln.minFlipsMonoIncr("00011000");
    cout << result;
    return 0;
}