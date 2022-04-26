#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */
bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;

        while(j > i){
            if (s[i] == s[j]){
                i++; j--;
            } else {
                return false;
            }
        }
        return true;
}

string highestValuePalindrome(string _string, int n, int k) {
    int lo = 0;
    int hi = n - 1;;
    int diff = 0;

    for(int i = 0, j = n - 1; i < n / 2; i++, j--)
        if (_string[i] != _string[j])
            diff++;

    if (diff > k)
        return "-1";

    while(hi >= lo){
        if (k <= 0)
            break;

        if (_string[lo] == _string[hi]){
            if (k > 1 && (k-2) >= diff && _string[lo] != '9'){
                _string[lo] = '9';
                _string[hi] = '9';
                k -= 2;
            }
        }
        else {
            if (k > 1 && (k-2) >= diff - 1){
                if (_string[lo] != '9'){
                    _string[lo] = '9';
                    k--;
                }
                if (_string[hi] != '9'){
                    _string[hi] = '9';
                    k--;
                }
            } else {
                if (_string[lo] > _string[hi]){
                    _string[hi] = _string[lo];
                } else {
                    _string[lo] = _string[hi];
                }
                k--;
            }
            diff--;
        }
        if (lo == hi && k > 0){
            _string[lo] = '9';
            k--;
        }
        lo++;
        hi--;
    }

    return isPalindrome(_string) ? _string : "-1";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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