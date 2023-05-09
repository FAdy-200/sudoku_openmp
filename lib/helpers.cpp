#include "helpers.hpp"

int CheckRowsAndColumns(int* grid, int n, int rowsOrColumns){
    int ret = 1;
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        int rows[n];
        int ind;
        memset(rows,0,sizeof(int)*n);
        for (int j = 0; j < n; j++)
        {   
            if (rowsOrColumns)
            {
                ind = i*n+j;
            }else{
                ind = j*n+i;
            }   
            if(grid[ind])
            rows[grid[ind] - 1] = 1;
        }
        int result = 1; 
        for (int j = 0; j < n; j++)
        {
            result &= rows[j];
        }
        #pragma omp critical
        ret &= result;
    }
    return ret;
}



int CheckBoxes(int* grid, int n){
    return 0;
}

int main(){
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
    int rowsCorrect9 = CheckRowsAndColumns((int*) grid9,n,1);
    int columnsCorrect9 = CheckRowsAndColumns((int*) grid9,n,0);
    grid9[0][0] = n;
    int rowsWrong9 = CheckRowsAndColumns((int*) grid9,n,1);
    int columnsWrong3 = CheckRowsAndColumns((int*) grid9,n,0);


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


    int rowsCorrect16 = CheckRowsAndColumns((int*) grid16,n,1);
    int columnsCorrect16 = CheckRowsAndColumns((int*) grid16,n,0);
    grid16[0][0] = n;
    int rowsWrong16 = CheckRowsAndColumns((int*) grid16,n,1);
    int columnsWrong4 = CheckRowsAndColumns((int*) grid16,n,0);
    if((rowsCorrect16 == 1) & (rowsWrong16 == 0) &(columnsCorrect16 == 1) & (columnsWrong3 == 0) 
        & (rowsCorrect9 == 1) & (rowsWrong9 == 0) &(columnsCorrect9 == 1) &(columnsWrong3 == 0))
    std::cout<< "Tests passed" << std::endl;
    else std::cout<< "Tests failed" << std::endl;
    return 0;
}