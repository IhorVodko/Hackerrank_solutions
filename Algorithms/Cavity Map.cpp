#Problem: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include <string>
#include <vector>


vector<string> cavityMap(vector<string> grid) {
    static constexpr char kX = 'X'; 
    static constexpr size_t kOne = 1;
    std::vector<string> result;
    if (grid.size() < 3) 
    {
        for ( const auto &str : grid)
        {
            result.emplace_back(str);
        }
        return result;
    } 
    size_t current_col = kOne;
    std::string temp_str;
    result.push_back(*grid.cbegin());
    for (auto itRow = ++grid.cbegin(); itRow != --grid.cend(); ++itRow) {
        temp_str.push_back(*(*itRow).cbegin());
        for (auto itCol = ++(*itRow).cbegin(); itCol != --(*itRow).cend(); ++itCol, ++current_col) {
            if (*itCol > *(itCol-kOne) && *itCol > *(itCol+kOne) && 
                *itCol > (*(itRow-kOne)).at(current_col) && *itCol > (*(itRow+kOne)).at(current_col)) {
                temp_str.push_back(kX);
                continue;
            }
            temp_str.push_back(*itCol);
        }
        current_col = kOne;
        temp_str.push_back(*--(*itRow).cend());
        result.emplace_back(temp_str);
        temp_str.clear();
    }
    if (grid.size() > kOne) {
        result.push_back(*--grid.cend());
    }   
    return result;
}
