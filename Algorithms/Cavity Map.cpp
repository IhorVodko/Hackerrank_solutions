#Problem: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include <string>
#include <vector>


vector<string> cavityMap(vector<string> grid) {
    static constexpr char kX = 'X'; 
    static constexpr size_t kOne = 1;
    const auto rows = grid.size() - kOne;
    if (!rows) {
        return grid;
    }
    const auto columns = grid.front().size() - kOne;
    int temp = 0;
    for (auto row = kOne; row != rows; ++row) {
        for (auto column = kOne; column != columns; ++column) {
            temp = grid.at(row).at(column);
            if (temp > grid.at(row).at(column - kOne) && temp > grid.at(row).at(column + kOne) && 
                temp > grid.at(row - kOne).at(column) &&  temp > grid.at(row + kOne).at(column)) {
               grid.at(row).at(column) = kX;
            }
        }
    }
    return grid;
}
