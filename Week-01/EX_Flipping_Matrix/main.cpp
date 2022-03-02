#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int quadsum(vector<vector<int>> matrix) {
    int m_size = matrix.size();
    int result = 0;
    for(int c = 0; c < m_size/2; c++){
        for(int r = 0; r < m_size/2; r++){
            result += matrix[r][c];
        }
    }
    return result;
}

vector<vector<int>> flipRow(vector<vector<int>> matrix, int r){
    int m_size = matrix.size();
    int temp_size = m_size - 1;
    int temp;
    for(int i = 0; i < m_size/2; i++){
        temp = matrix[r][i];
        matrix[r][i] = matrix[r][temp_size];
        matrix[r][temp_size] = temp;
        temp_size--;

    }
    return matrix;
}

vector<vector<int>> flipColumn(vector<vector<int>> matrix, int c){
    int m_size = matrix.size();
    int temp_size = m_size - 1;
    int temp;
    for(int i = 0; i < m_size/2; i++){
        temp = matrix[i][c];
        matrix[i][c] = matrix[temp_size][c];
        matrix[temp_size][c] = temp;
        temp_size--;
    }
    return matrix;
}





/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int flippingMatrix(vector<vector<int>> matrix) {
    int m_size = matrix.size();

    // Columns
    for(int c = 0; c < m_size; c++){
        int quad_sum_before = quadsum(matrix);
        int result_1 = 0, result_2 = 0;
        for(int r = 0; r < m_size/2; r++){
            result_1 += matrix[r][c];
        }
        for(int r = m_size - 1; r >= m_size/2; r--){
            result_2 += matrix[r][c];
        }
        if(result_2 > result_1){
            //flip columns
            matrix = flipColumn(matrix, c);

        }
        int quad_sum_after = quadsum(matrix);
        if(quad_sum_before > quad_sum_after){
            matrix = flipColumn(matrix, c);
        }
    }

     for(int r = 0; r < m_size; r++){
        // Rows
        int result_1 = 0, result_2 = 0;
        int quad_sum_before = quadsum(matrix);
        for(int c = 0; c < m_size/2; c++){
            result_1 += matrix[r][c];
        }
        for(int c = m_size - 1; c >= m_size/2; c--){
            result_2 += matrix[r][c];
        }
        if(result_2 > result_1){
            // flip rows
            matrix = flipRow(matrix, r);
        }

        int quad_sum_after = quadsum(matrix);
        if(quad_sum_before > quad_sum_after){
            matrix = flipRow(matrix, r);
        }


        for(int r = 0; r < m_size; r++){
            for(int c = 0; c < m_size; c++){
                    cout << matrix[r][c] << " ";
            }
            printf("\n");
        }


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        //cout << quadsum(matrix) << endl;
        int result = flippingMatrix(matrix);

        fout << result << "\n";
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
