#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(const vector<string>& topic) 
{
    typedef vector<string>::const_iterator vConstIter;
    string::size_type strSz = topic[1].size();
    vector<string>::size_type vecSz = topic.size();
    int maxTopics = -1,
        maxTeams = 0;
    for (vConstIter itB1 = topic.begin(); itB1 != (topic.end() - 1); ++itB1)
    {   
        for (vConstIter itB2 = (itB1 + 1); itB2 != topic.end(); ++itB2)
        {   
            int topics = 0;
            for(int k = 0; k < strSz; ++k)
            {
                if ((*itB1)[k] == '1'
                    || (*itB2)[k] == '1')
                {
                    ++topics;
                }
            }
            if (topics > maxTopics)
            {
                maxTopics = topics;
                maxTeams = 0;
                ++maxTeams;
            } else if (topics == maxTopics) 
            {
                ++maxTeams;
            }
        }
    }
    vector<int> vecRet;
    vecRet.push_back(maxTopics);
    vecRet.push_back(maxTeams);
    
    return vecRet;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
