#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

string counterGame(long n) {
    int idx = 0;
    bool wins = true;
    if(n == 1)
       return "Louise";

    unsigned long long arr[64];
    for(int i = 0; i < 64; i++){
        arr[i] = pow(2, i);
    }

    while(n != 1){
        for(int i = 0; i < 64; i++){
            if(n > arr[i] && n < arr[i + 1]){
                idx = i;
                break;
            }
        }
        if(n > arr[idx] && n < arr[idx + 1])
            n = n - arr[idx];
        else
            n = n / 2;
        if(n == 1)
            break;
        wins = !wins;
    }

    if(wins)
        return "Louise";
    return "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        cout << result << endl;
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
