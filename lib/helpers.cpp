#include "helpers.hpp"

bool CheckRowsAndColumns(int* grid, int n, int rowsOrColumns){
    bool ret = true;
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        bool rows[n];
        int ind;
        memset(rows,0,sizeof(bool)*n);
        for (int j = 0; j < n; j++)
        {   
            if (rowsOrColumns)
            {
                ind = i*n+j;
            }else{
                ind = j*n+i;
            }   
            if(grid[ind])
            rows[grid[ind] - 1] = true;
        }
        bool result = true; 
        for (int j = 0; j < n; j++)
        {
            result &= rows[j];
        }
        #pragma omp atomic update
        ret &= result;
    }
    return ret;
}



bool CheckBoxes(int* grid, int n){
    return 0;
}
