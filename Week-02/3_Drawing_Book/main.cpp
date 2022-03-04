#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    int pages = 0;
    int current = 1;
    int mid_book = n / 2;

    if(p <= mid_book){
      if(p == 1){
        return 0;
      }
      else
        while( (p != current) && (p != current - 1) ){
            current += 2;
            pages++;
      }
    }
    else{
        if(p == n){
            return 0;
          }
        else if(p == n - 1){
            return 1;
        }
        else{
            current = n;
            while( (p != current) && (p != current - 1) ){
                current -= 2;
                pages++;
            }
        }
    }
    cout << pages << endl;
    return pages;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
