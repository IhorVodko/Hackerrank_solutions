#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations (
        int _numOfCities
    ,   std::vector< int >  _citiesWithStations
) 
{
    int countOfCitiesWthSttns = _citiesWithStations.size();
    
    if ( _numOfCities == countOfCitiesWthSttns )
    {
        return 0;
    }
    
    if( countOfCitiesWthSttns == 1 )
    { 
        auto const & numOfCityWthSttn = _citiesWithStations.front();
        if (  
                numOfCityWthSttn == 0 
            ||  numOfCityWthSttn == _numOfCities - 1    
        )
        { 
            return --_numOfCities;
        }
        else
        {
            return std::max( 
                    numOfCityWthSttn
                ,   ( _numOfCities - 1 ) - numOfCityWthSttn 
            );
        }
    }    

    std::sort( std::begin( _citiesWithStations ), std::end( _citiesWithStations ) );
    
    bool 
            isFirstInserted = false
        ,   isLastInserted = false 
    ;
            
    if ( _citiesWithStations.front() != 0 )
    {
        _citiesWithStations.insert( std::begin( _citiesWithStations ), 0 );
        isFirstInserted = true;
    }
    
    if ( _citiesWithStations.back() !=  countOfCitiesWthSttns - 1 )
    {
        _citiesWithStations.emplace_back( countOfCitiesWthSttns - 1 );
        isLastInserted = true;
    }
    
    int 
            currentMaxNearestDistance = 0
        ,   currentNearestDistance = 0
    ;
    
    auto citBeforeLast = std::cend( _citiesWithStations ) - 1;
    
    for( auto citFirst = std::cbegin( _citiesWithStations ); citFirst != citBeforeLast; ++citFirst )
    {
        currentNearestDistance = *( citFirst + 1 ) - *citFirst;
        
        if ( currentNearestDistance > currentMaxNearestDistance )
        {
            currentMaxNearestDistance = currentNearestDistance;
        }
    }
    
    int result = currentMaxNearestDistance / 2;
    int lastDistance = *citBeforeLast - *( citBeforeLast - 1 );
    
    auto citFirst = std::cbegin( _citiesWithStations );
    
    int firstDistance = *( citFirst + 1 ) -  *citFirst;
    
    if ( isFirstInserted && isLastInserted )
    {    
        return std::max( { firstDistance, result, lastDistance } );
    }
    else if ( isFirstInserted )
    {    
        return std::max( firstDistance, result );
    }
    else if ( isLastInserted )
    {    
        return std::max( result, lastDistance );
    }
    else 
    {
        return result;
    }
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
