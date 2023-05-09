#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(){
    int x[2];
    memset(x, 0, sizeof(int)*2);
    cout << x[0] << x[1] << endl;
    return 0;
}