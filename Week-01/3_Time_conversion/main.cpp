#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string am_pm, result, s_hour;

    am_pm = s.substr(8,9);
    result = s.substr(0,8);
    s_hour = s.substr(0,2);
    if(am_pm.compare("AM") == 0){
        if(s_hour.compare("12") == 0){
            result = result.replace(0,2,"00");
        }
    }
    else{
        if(s_hour.compare("12") == 0){}
        else{
            int hour = stoi(s_hour);
            hour += 12;
            s_hour = to_string(hour);
            result = result.replace(0,2,s_hour);
        }
    }

    cout << result << endl;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
