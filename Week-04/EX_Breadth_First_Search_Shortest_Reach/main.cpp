#include "C:\msys64\mingw64\include\c++\11.2.0\x86_64-w64-mingw32\bits\stdc++.h"

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n - the number of nodes
 *  2. INTEGER m - the number of edges
 *  3. 2D_INTEGER_ARRAY edges - start and end nodes for edges
 *  4. INTEGER s - the node to start traversals from
 */

void addEdge(vector<vector<int>> adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n);  // adjacency list representation
    vector<int> distances(m, 0);
    vector<bool> visited(n, false);
    queue<int> nodes;
    nodes.push(s);
    visited[s] = true;

    for (int i = 0; i < m; i++)
        addEdge(adj, edges[i][0], edges[i][1]);

    // adj[n][0] ??

    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        for (int i : adj[node]) {
            if (!visited[i]) {
                distances[i] = distances[node] + 6;
                nodes.push(i);
                visited[i] = true;
            }
        }
    }

    //for (int i = 0; i < n; i++) {
    //    if (visited[i] == false)
    //        distances[i] = -1;
    //    else if (distances[i] > 0)
    //        distances[i] *= 6;
    //}

    return distances;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    //fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
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
