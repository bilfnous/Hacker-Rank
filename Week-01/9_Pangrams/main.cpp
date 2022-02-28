#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    string pangram = "the quick brown fox jumps over the lazy dog";
    int s_size = s.size();
    int alph_count = 0;

    for(int i = 0; i < s_size; i++){
        char ch = tolower(s[i]);
        if(pangram.find(ch)!= std::string::npos){
            pangram.erase(remove(pangram.begin(), pangram.end(), ch), pangram.end());
            alph_count++;
        }
    }

    if(pangram.size() == 0){
        cout << "Pan" << endl;
        return "pangram";
    }
    else{
        cout << "Not Pan" << endl;
        return "not pangram";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
