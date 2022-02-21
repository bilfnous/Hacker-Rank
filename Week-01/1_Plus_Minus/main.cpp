#include <bits/stdc++.h>

// #include <iomanip> std::cout << std::setprecision(2) << std::fixed;

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    double pos = 0.0, neg = 0.0, zero = 0.0;
    //int arrSize = (sizeof(arr)/sizeof(arr[0]));
    // why sizeof doesn't return the correct array/vector length
    int arrSize = arr.size();
    printf("%d\n\n", arrSize);
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){ pos++; }
        else if (arr[i] < 0){ neg++; }
        else{ zero++; }
    }
    printf("%.6f\n", (pos/arrSize));
    printf("%.6f\n", (neg/arrSize));
    printf("%.6f\n", (zero/arrSize));
}

int main()
{
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

    plusMinus(arr);

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
