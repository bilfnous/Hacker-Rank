#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// DFS Search
int dfs(vector<vector<int>> &v, int current_city, vector<bool> &visited){
    int result = 1; // number of nodes connected to a specific city
    visited[current_city] = true;
    for(int i = 0; i < v[current_city].size(); i++){
        if(!visited[v[current_city][i]])
            result += dfs(v, v[current_city][i], visited);
    }
    return result;
}

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n, the number of cities
 *  2. INTEGER c_lib, the cost to build a library
 *  3. INTEGER c_road, the cost to repair a road
 *  4. 2D_INTEGER_ARRAY cities each cities[i] contains two integers that represent cities that can be connected by a new road
 */

/*
  1. convert the 2D array into undirected graph
  2. Decide whether A) to build a library in each city (n cities)
                    B) or build one library in one city and connect the rest of the cities by roads (n-1 roads)
*/
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    // Adjacency list, stores all nodes (cities) connected to a specific node (city)
    vector<vector<int>> v(n + 1);
    vector<bool> visited(n + 1, false);
    // Number of cities connected to each city
    vector<int> comps;
    long result = 0;

    // Adjacency list, undirected graph
    for(int i = 0; i < cities.size(); i++){
        v[cities[i][0]].push_back(cities[i][1]);
        v[cities[i][1]].push_back(cities[i][0]);
    }

    for(int i = 1; i <= n; i++){
        if(v[i].size() > 0 && !visited[i])
            comps.push_back(dfs(v, i, visited));
        // cities that are not connect to any other city
        else if(v[i].size() == 0)
            comps.push_back(1);
    }

    // Question Specific code
    for(int i = 0; i < comps.size(); i++)
        result += min((comps[i] - 1)* c_road + c_lib, comps[i] * c_lib);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]); // number ofcities

        int m = stoi(first_multiple_input[1]); // number roads

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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
