//problem: https://www.hackerrank.com/challenges/happy-ladybugs/problem?isFullScreen=true

#include <algorithm>
#include <array>
#include <string>

string happyLadybugs(string b) {
    std::array<size_t,26> az;
    az.fill(0);
    bool is_happy = true;
    bool is_underscore = false;
    b = "0" + b + "0";
    for (auto i = 1; i < b.size() - 1; ++i)  {
        if (b[i] != '_' && b[i] != b[i-1] && b[i] != b[i+1]) {
            is_happy = false;
        }
        if (b[i] == '_') {
            is_underscore = true;
        } else {
            az[b[i] - 'A']++;
        }
    }
    if (is_happy || (is_underscore && std::find(az.cbegin(), az.cend(), 1) == az.end())) {
        return "YES";
    }
    return "NO";
}
