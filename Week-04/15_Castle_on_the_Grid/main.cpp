#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

 // Graph: Breadth First Search (BFS)
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int r, c, rr, cc;
    size_t grid_size = grid.size();
    // Direction vectors
    int dr[] = { -1, +1, 0, 0 };
    int dc[] = { 0, 0, +1, -1 };
    queue<int> rq, cq; // Empty row queue and column queue
    // Variables to track number of steps taken
    int move_count = 0;
    int nodes_left_in_layer = 1;
    int nodes_in_next_layer = 0;
    bool end_reached = false;
    vector<vector<bool>> visited(grid_size, vector<bool>(grid_size, false));

    rq.push(startX);
    cq.push(startY);
    visited[startX][startY] = true;

    while (!rq.empty()) {
        r = rq.front();
        c = cq.front();
        rq.pop();
        cq.pop();
        if (r == goalX && c == goalY) {
            end_reached = true;
            return move_count;
        }

        for (int i = 0; i < 4; i++) {
            rr = r + dr[i];
            cc = c + dc[i];

            // Skip out of bounds index
            if (rr < 0 || cc < 0) continue;
            if (rr >= grid_size || cc >= grid_size) continue;

            // Skip visited or blocked index
            if (visited[rr][cc]) continue;
            if (grid[rr][cc] == 'X') continue;

            rq.push(rr);
            cq.push(cc);
            visited[rr][cc] = true;
            nodes_in_next_layer++;
        }

        nodes_left_in_layer--;
        if (nodes_in_next_layer == 0) {
            nodes_in_next_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    cout << result << "\n";

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
