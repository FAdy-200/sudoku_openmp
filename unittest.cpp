#include "lib/helpers.hpp"

bool TestCheckRowsAndColumns(){
    int n = 9;
    int grid9[n][n];
    memset(grid9,0,sizeof(int)*n*n);
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if((i+j-1)%(n)) grid9[i-1][j-1] = (i+j-1)%n;
            else grid9[i-1][j-1] = n;
            // std::cout << grid9[i-1][j-1] << " ";
        }
        // std::cout << std::endl;   
    }
    bool rowsCorrect9 = CheckRowsAndColumns((int*) grid9,n,1);
    bool columnsCorrect9 = CheckRowsAndColumns((int*) grid9,n,0);
    grid9[0][0] = n;
    bool rowsWrong9 = CheckRowsAndColumns((int*) grid9,n,1);
    bool columnsWrong9 = CheckRowsAndColumns((int*) grid9,n,0);


    n = 16;
    int grid16[n][n];
    memset(grid16,0,sizeof(int)*n*n);
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if((i+j-1)%(n)) grid16[i-1][j-1] = (i+j-1)%n;
            else grid16[i-1][j-1] = n;
        }
    
    }


    bool rowsCorrect16 = CheckRowsAndColumns((int*) grid16,n,1);
    bool columnsCorrect16 = CheckRowsAndColumns((int*) grid16,n,0);
    grid16[0][0] = n;
    bool rowsWrong16 = CheckRowsAndColumns((int*) grid16,n,1);
    bool columnsWrong16 = CheckRowsAndColumns((int*) grid16,n,0);
    return (rowsCorrect16) & (!rowsWrong16) &(columnsCorrect16) & (!columnsWrong9) 
        & (rowsCorrect9) & (!rowsWrong9) &(columnsCorrect9) &(!columnsWrong16);

}
int main(int argc, char * argv[]){
    bool mode = 1;
    bool failed = 0;
    if(argc>1) mode = atoi(argv[1]);
    

    std::cout << "Starting the test\n";
    std::cout << "Testing the function CheckRowsAndColumns"<<std::endl;
    if(TestCheckRowsAndColumns()) std::cout << "Test Completed Successfully"<<std::endl;
    else {
        std::cout << "Test failed\n"<<std::endl;
        failed = 1;
        if(mode) return 1;
    }
    if(failed) return -1;
    return 0;
}