#include <iostream>
#include <string>
#include <iterator>
#include <regex>

using namespace std;

string trimCustom(string s) {
    string::iterator beg = s.begin();
    while (*beg == ' ') {
        beg++;
    }
    string::iterator end = s.end();
    while (*end == ' ') {
        end--;
    }
    string result;
    for (string::iterator curr = beg; curr != end; curr++) {
        if (*curr == ' ') {
            if (*(curr-1) != ' ' && *(curr-2) == ' ') {
                result.pop_back();
            }
            else if (*(curr-1) != ' ') {
                result += ' ';
            }
        } else {
            result += *curr;
        }
    }
    if (*(result.end()-1) == ' ') result.pop_back();
    if (*(result.end()-1) != ' ' && *(result.end()-2) == ' ') result.erase(result.size()-2);
    if (*result.begin() != ' ' && *(result.begin()+1) == ' ') result.erase(0, 2);
    return result.size() > sizeof(char) ? result : "";
}

string ltrim(const string &s) {
    size_t start = s.find_first_not_of(' ');
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s) {
    size_t end = s.find_last_not_of(' ');
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
    return rtrim(ltrim(s));
}

string trimString(string s) {
    string result = trim(s);
    regex oneCharWord(" \. ");
    regex doubleSpace("  ");
    while(regex_search(result, oneCharWord)) {
        result = regex_replace(result, oneCharWord, " ");
    }
    while(regex_search(result, doubleSpace)) {
        result = regex_replace(result, doubleSpace, " ");
    }
    if (*(result.end()-1) == ' ') result.pop_back();
    if (*(result.end()-1) != ' ' && *(result.end()-2) == ' ') result.erase(result.size()-2);
    if (*result.begin() != ' ' && *(result.begin()+1) == ' ') result.erase(0, 2);
    return result.size() > sizeof(char) ? result : "";
}

void solveCustom(char (&data)[50][50], const int n) {
    cout << '\n' << "Custom solution: " << endl;
    for (int i = 1; i <= n; i++) {
        string s = data[i];
        cout << '.' << trimCustom(s) << '.' << endl;
    }
    cout << endl;
}

void solveWithLib(char (&data)[50][50], const int n) {
    cout << "StdLib solution: " << endl;
    for (int i = 1; i <= n; i++) {
        string s = data[i];
        cout << trimString(s) << endl;
    }
}

int main()
{
   int n;
   char data[50][50];
   cout << "Enter number of strings" << endl;
   cin >> n;
   for (int i = 0; i <= n; i++) {
        cin.getline(data[i], 50);
   }
   solveCustom(data, n);
   solveWithLib(data, n);
   return 0;
}
