#include <iostream>
#include <deque>
#include <vector>

using std::cout,std::cin,std::endl;
using std::deque,std::vector;

namespace solution
{
    class Program
    {
        public:
            int minFlips;
            vector<vector<int>> direction; //USING VECTORS BECAUSE MAP DOESNT SEEM TO WORK
            deque<vector<int>> map;

            void printIsland(int (&island)[3][3]){
                int row = sizeof(island)/sizeof(island[0]);
                int col = sizeof(island[0])/sizeof(island[0][0]);
                cout << "GRID GOES AS: " << endl;
                for(int i=0 ; i<row ; i++){
                    for(int j=0 ; j<col ; j++){
                        cout << island[i][j] << " ";
                    }
                    cout << endl;
                }
            }

            int ShortestBridge(int (&island)[3][3]);
            void dfs(int (&island)[3][3],int row,int col);
            int bfs(int (&island)[3][3]);
            int isInMap(int row,int col);
    }; //class

    int Program::ShortestBridge(int (&island)[3][3]){
        int row = sizeof(island)/sizeof(island[0]);

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<row ; j++){
                dfs(island,i,j);
                return bfs(island);
            }
        }

        return 0;
    }
    void Program::dfs(int (&island)[3][3],int row,int col){
        int grid = sizeof(island)/sizeof(island[0]);

        if(island[row][col] == 1){
            this->map.push_back( {row,col} );
        }

        if(island[row][col] == 0)
            return;
        if( isInMap(row,col) )
            return;

        if(row < grid)
            dfs(island,row+1,col);
        if(row > 0)
            dfs(island,row-1,col);
        if(col < grid)
            dfs(island,row,col+1);
        if (col > 0)
            dfs(island,row,col-1);

        return;
    }
    int Program::bfs(int (&island)[3][3]){
        int result=0,currRow=0,currCol=0;
        int grid = sizeof(island)/sizeof(island[0]);
        this->direction.push_back( {1,0} );
        this->direction.push_back( {-1,0} );
        this->direction.push_back( {0,1} );
        this->direction.push_back( {0,-1} );

        while( !this->map.empty() ){

            for(vector<int> vec: this->map){
                int index=0;
                for(int i : vec){
                    if(index==0)
                        currRow=i;
                    else
                        currCol=i;
                    index++;
                }
                this->map.pop_front();

                for(vector<int> dir : this->direction){
                    int index2=0,tempRow=0,tempCol=0;
                    for(int j : dir){
                        if(index2 == 0)
                            tempRow = currRow + j;
                        else
                            tempCol = currCol + j;
                    }
                    if(tempRow < grid && tempRow > 0 && tempCol < grid && tempCol > 0 && )
                }

            }

        }
        return result;
    }
    int Program::isInMap(int row,int col){
        int index=0;
        int r,c;
        for(vector<int> list : this->map){
            for(int i : list){
                if(index == 0)
                    r = i;
                else
                    c = i;
                if(r == row && c == col)
                    return 1;
                index++;
            }
        }
        return 0;
    }


} //namepace

int main(){
    int island[3][3] = {{0,1,0},{0,0,0},{0,0,1}};
    solution::Program soln;
    soln.printIsland(island);
    int result = soln.ShortestBridge(island);
    return 0;
}