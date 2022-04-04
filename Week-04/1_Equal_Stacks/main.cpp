#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int h1_size = h1.size();
    int h2_size = h2.size();
    int h3_size = h3.size();
    int h1_sum = 0, h2_sum = 0, h3_sum = 0;
    bool pass = true;

    if(h1_size == 0 && h2_size == 0 && h3_size == 0)
        return 0;

    for(int i = 0; i < h1_size; i++)
        h1_sum += h1[i];
    for(int i = 0; i < h2_size; i++)
        h2_sum += h2[i];
    for(int i = 0; i < h3_size; i++)
        h3_sum += h3[i];

    if(h1_sum == h2_sum && h1_sum == h3_sum)
        return h1_sum;

    while(pass){
        if(h1_sum >= h2_sum && h1_sum >= h3_sum){
            h1_sum -= h1[0];
            h1.erase(h1.begin());
        }
        else if(h2_sum >= h1_sum && h2_sum >= h3_sum){
            h2_sum -= h2[0];
            h2.erase(h2.begin());
        }
        else if(h3_sum >= h1_sum && h3_sum >= h2_sum){
            h3_sum -= h3[0];
            h3.erase(h3.begin());
        }
        if(h1_sum == h2_sum && h1_sum == h3_sum){
            pass = false;
        }
        if(h1_sum == 0 || h2_sum == 0 || h3_sum == 0){
            return 0;
        }
    }

    return h1_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

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
