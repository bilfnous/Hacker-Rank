#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int s_num[26] = {0};
    vector<int> occur;
    // a=97, z=122
    for(int i = 0; i < s.size(); i++){
        s_num[s[i] - 97]++;
    }
    int one = 0;
    for(int i = 0; i < 26; i++){
        if(s_num[i] > 0){
            occur.push_back(s_num[i]);
            if(s_num[i] == 1) one++;
        }
    }
    if(s.size() == 1){
        cout << "YES" << endl;
        return "YES";
    }

    int temp = 0;
    for(int i = 0; i < occur.size(); i++){
        if(occur[i] != occur[0])
            temp++;
        if( (occur[0] - occur[i] > 1 && one > 2) || temp > 1){
            cout << "NO" << endl;
            return "NO";
        }
    }
    cout << "YES" << endl;
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

