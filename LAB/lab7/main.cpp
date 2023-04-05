#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <QSet>

using namespace std;

string toLowercase(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) result += tolower(s[i]);
    return result;
}

bool compareStrings (string s1, string s2) {
    return toLowercase(s1) < toLowercase(s2);
}

bool inequalStrings (string s1, string s2) {
    return toLowercase(s1) != toLowercase(s2);
}

typedef set<string, decltype(&compareStrings)> stdSet;

stdSet parseStlSetDataFromFile(char *filename, int& l) {
    stdSet result(compareStrings);
    int len = 0;
    FILE* file;
    file = fopen(filename, "r+b");
    char ch;
    while ((ch=fgetc(file)) != EOF) {
        string word {ch};
        while ((ch=fgetc(file)) != '\n') {
            word += ch;
        }
        len++;
        word.pop_back();
        result.insert(word);
    }
    fclose(file);
    return result;
}

void solveWithStdSet() {
    stdSet f;
    int lf=0, lg=0;
    f = parseStlSetDataFromFile("C://Users/peter/BMSTU/BMSTU_CPP/LAB/lab7/f.txt", lf);
    stdSet g;
    g = parseStlSetDataFromFile("C://Users/peter/BMSTU/BMSTU_CPP/LAB/lab7/g.txt", lg);
    cout << lf << ' ' << lg << endl;
    stdSet::iterator j;
    stdSet::iterator i;
    if (lf < lg) {
        cout << "Sets compared with stl::set are not equal!" << '\n' << "Inequal items:" << endl;
        for ((i = f.begin(), j = g.begin()); i != f.end(); (j++, i++))
        {
            if (inequalStrings(*i, *j)) cout << "F: " << *i << "G: " << *j << endl;
        }
        while (i != f.end()) {
            cout << "F: " << *i << "G: " << "None" << endl;
            i++;
        }
    } else if (lf > lg) {
        cout << "Sets compared with stl::set are not equal!" << '\n' << "Inequal items:" << endl;
        for ((i = f.begin(), j = g.begin()); j != g.end(); (j++, i++))
        {
            if (inequalStrings(*i, *j)) cout << "F: " << *i << "G: " << *j << endl;
        }
        while (j != g.end()) {
            cout << "F: " << "None" << "G: " << *j << endl;
            j++;
        }
    }
    else {
        int flag = 0;
        for ((i = f.begin(), j = g.begin()); (j != g.end() && i != f.end()); (j++, i++))
        if (inequalStrings(*i, *j)) {
            !flag && (cout << "Sets compared with stl::set are not equal!" << '\n' << "Inequal items:" << endl);
            flag = 1;
            cout << "F: " << *i << ' ' << "G: " << *j << endl;
        }
        if (!flag) cout << "Sets compared with stl::set are equal!" << endl;
    }
}

void solveWithQSet() {

}

int main() {
    solveWithStdSet();
    return 0;
}
