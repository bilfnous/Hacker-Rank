#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int swap_1(vector<int> arr){
    bool sorted = false;
    int arr_size = arr.size() - 1;
    int swaps = 0, _max = 0, _tmp = 0, _index = 0;

    while(!sorted){
        for(int i = arr_size; i >= 0; i--)
            if(arr[i] > _max){
                _max = arr[i];
                _index = i;
            }

        if(_index != arr_size){
            _tmp = arr[arr_size];
            arr[arr_size] = arr[_index];
            arr[_index] = _tmp;
            swaps++;
        }
        if(arr_size == 1)
            sorted = true;
        arr_size--;
        _max = 0;
    }

    return swaps;
}

int swap_2(vector<int> arr){
    bool sorted = false;
    int arr_size = arr.size() - 1;
    int swaps = 0, _max = 0, _tmp = 0, _index = 0, x = 0;

    while(!sorted){
        for(int i = arr_size; i >= x; i--)
            if(arr[i] > _max){
                _max = arr[i];
                _index = i;
            }

        if(_index != x){
            _tmp = arr[x];
            arr[x] = arr[_index];
            arr[_index] = _tmp;
            swaps++;
        }
        if(arr_size == 1)
            sorted = true;
        arr_size--;
        x++;
        _max = 0;
    }

    return swaps;
}

int lilysHomework(vector<int> arr) {
    return min(swap_1(arr), swap_2(arr));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
