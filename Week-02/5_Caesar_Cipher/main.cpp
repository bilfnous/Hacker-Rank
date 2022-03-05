#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    int s_size = s.size();
    int i_temp = 0, temp;

    // ASCII A-Z 65 - 90
    // ASCII a-z 97 - 122

    if(k > 26){
        temp = k / 26;
        temp = 26 * temp;
        k = k - temp;
    }

    for(int i = 0; i < s_size; i++){
        if(s[i] > 64 && s[i] < 91){
            i_temp = s[i];
            if(i_temp + k > 90){
                temp = 90 - i_temp;
                temp -= k;
                s[i] = 64 + abs(temp);
            }
            else{
                s[i] = i_temp + k;
            }
        }
        else if (s[i] > 96 && s[i] < 123){
            i_temp = s[i];
            if(i_temp + k > 122){
                temp = 122 - i_temp;
                temp -= k;
                s[i] = 96 + abs(temp);
            }
            else{
                s[i] = i_temp + k;
            }
        }
    }
    cout << s << endl;
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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
