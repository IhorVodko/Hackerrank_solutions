#Problem: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include <string>
#include <vector>


vector<string> cavityMap(vector<string> grid) {
    static constexpr char kX = 'X'; 
    static constexpr size_t kOne = 1;
    if (grid.size() < 3) 
    {
        return grid;
    } 
    size_t current_col = kOne;
    for (auto itRow = ++grid.begin(); itRow != --grid.end(); ++itRow) {
        for (auto itCol = ++(*itRow).begin(); itCol != --(*itRow).end(); ++itCol, ++current_col) {
            if (*itCol > *(itCol-kOne) && *itCol > *(itCol+kOne) && 
                *itCol > (*(itRow-kOne)).at(current_col) && *itCol > (*(itRow+kOne)).at(current_col)) {
               *itCol = kX;
            }
        }
        current_col = kOne;
    }
 
    return grid;
}
