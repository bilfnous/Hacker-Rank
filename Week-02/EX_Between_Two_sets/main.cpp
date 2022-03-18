#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

 /*
  *  O(n log(n)) solution.
  *  1. find the LCM of all the integers of array A.
  *  2. find the GCD of all the integers of array B.
  *  3. Count the number of multiples of LCM that evenly divides the GCD.??
 */

int GCD(int num1, int num2){
    if (num2 == 0) {
      return num1;
    }
    return GCD(num2, num1 % num2);
}

int LCM(int num1, int num2){
    if (num1 == 0 || num2 == 0)
      return 0;
    else {
      int gcd = GCD(num1, num2);
      return abs(num1 * num2) / gcd;
    }
}

int getTotalX(vector<int> a, vector<int> b) {
    int result = 0;

    int lcm = a[0];
    for(int i = 1; i < a.size(); i++)
        lcm = LCM(lcm, a[i]);

    // Get GCD of all elements of b
    int gcd = b[0];
    for(int i = 1; i < b.size(); i++)
        gcd = GCD(gcd, b[i]);


    // Count multiples of lcm that divide the gcd
    int multiple = 0;
    while(multiple <= gcd) {
        multiple += lcm;
        if(gcd % multiple == 0)
            result++;
    }

    cout << result << endl;

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
