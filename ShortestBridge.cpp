#include <iostream>
#include <deque>
#include <vector>
#include <utility>

using std::cout,std::cin,std::endl;
using std::deque,std::vector,std::pair;

namespace solution
{
    class Program
    {
        public:
            int minFlips;
            vector<pair<int,int>> visited; //USING VECTORS BECAUSE MAP DOESNT SEEM TO WORK
            vector<pair<int,int>> island;
            deque<pair<int,int>> map;
            vector<int> ri{+1,-1,0,0};
            vector<int> ci{0,0,-1,+1};

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
            int isVisited(int row,int col,vector<pair<int,int>> temp);
    }; //class

    int Program::ShortestBridge(int (&island)[3][3]){
        int row = sizeof(island)/sizeof(island[0]);
        dfs(island,0,0);
        return bfs(island);
    }

    void Program::dfs(int (&island)[3][3],int row,int col){
        if( isVisited(row,col,this->visited) )
            return;
        this->visited.push_back( std::make_pair(row,col) );

        int grid = sizeof(island)/sizeof(island[0]);
        
        if(island[row][col] == 1){
            this->map.push_back( std::make_pair(row,col) );
        }


        if(row < grid)
            dfs(island,row+1,col);
        if(col < grid)
            dfs(island,row,col+1);
    }

    int Program::bfs(int (&island)[3][3]){
        int result=0,currRow=0,currCol=0;
        int grid = sizeof(island)/sizeof(island[0]);

        while( !this->visited.empty() )
            this->visited.pop_back();
        
        while( !this->map.empty() ){ //STARTING FROM AN ISLAND DO BFS
            pair rowcol = this->map.front();
            int r = rowcol.first;
            int c = rowcol.second;
            
            //Perform BFS
            for(int i=0 ; i<4 ; i++){
                int currRow = r + ri[i];
                int currCol = c + ci[i];

                if(currRow>=0 && currRow<grid && currCol>=0 && currCol<grid && island[currRow][currCol]==0 && isVisited(currRow,currCol,this->visited)==0){
                    this->visited.push_back({currRow,currCol});
                }
                else if(currRow>=0 && currRow<grid && currCol>=0 && currCol<grid && island[currRow][currCol]==1 && isVisited(currRow,currCol,this->visited)==0)
                    continue;
            }
            result++;
            this->map.pop_front();
        }
        return result;
    }

    int Program::isVisited(int row,int col,vector<pair<int,int>> temp){
        int index=0;
        int r,c;
        for(pair<int,int> list : temp){
            r = list.first;
            c = list.second;
            if(r == row && c == col){
                return 1;
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
    cout << result << endl;
    return 0;
}