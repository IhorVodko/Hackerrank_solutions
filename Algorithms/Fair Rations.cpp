//Problem : https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
#include <algorithm>
#include <bitset>
#include <functional>
#include <limits>
#include <vector>
#include <string>

namespace {
    constexpr size_t MAX_SIZE_OF_QUEUE = 1000;
    constexpr char const * NO = "NO";
}

string fairRations(const vector<int> &input) {
    const auto IsEven = [&](int num){return !(num % 2);};
    std::bitset<::MAX_SIZE_OF_QUEUE> queue;
    size_t begin = 0; 
    std::for_each(input.cbegin(), input.cend(), [&](auto element){!IsEven(element) ? queue.set(begin++) : ++begin;}); 
    if(!IsEven(queue.count())) {
        return ::NO;
    }
    if(queue.count() == 0) {
        return std::to_string(0);
    }
    --begin;
    size_t first_uneven = 0, min_num_of_loaves = 0, dist_first_to_second = 0;
    bool is_first_uneven_found = false;
    while (begin != std::numeric_limits<size_t>::max()) {
        if (queue.test(begin)) {
            if (!is_first_uneven_found) {
                first_uneven = begin;
                is_first_uneven_found = !is_first_uneven_found;
            } else {
                dist_first_to_second = first_uneven - begin;
                min_num_of_loaves += (dist_first_to_second == 0 ? ++dist_first_to_second : dist_first_to_second) * 2;
                is_first_uneven_found = !is_first_uneven_found;
            }
        }
        --begin;
    };
    return std::to_string(min_num_of_loaves);
}
