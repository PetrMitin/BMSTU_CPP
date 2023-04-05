#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <QSet>

using namespace std;

//class indefString: public string {
//public:
//    indefString() : string() {}
//    indefString(const char* str) : string(str) {}

//    indefString toLowercase(const indefString &s) const {
//        indefString result = "";
//        for (int i = 0; i < s.length(); i++) result += tolower(s[i]);
//        return result;
//    }

//    bool operator == (const indefString &other) {
//        return this->toLowercase(*this) == this->toLowercase(other);
//    }

//    bool operator < (const indefString &other) {
//        return this->toLowercase(*this) < this->toLowercase(other);
//    }
//};

typedef set<string> stdSet;
const char* fFileName = "C://Users/peter/BMSTU/BMSTU_CPP/LAB/lab72/f.txt";
const char* gFileName = "C://Users/peter/BMSTU/BMSTU_CPP/LAB/lab72/g.txt";

stdSet parseStlSetDataFromFile(const char *filename, int& l) {
    stdSet result;
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
    l = len;
    return result;
}

QSet<string> parseQSetData(const char *filename, int& l) {
    stdSet data = parseStlSetDataFromFile(filename, l);
    QSet<string> result(data.begin(), data.end());
    return result;
}

void solveWithStdSet() {
    stdSet f, g;
    int lf=0, lg=0;
    f = parseStlSetDataFromFile(fFileName, lf);
    g = parseStlSetDataFromFile(gFileName, lg);
    stdSet diff;
    set_symmetric_difference(f.begin(), f.end(), g.begin(), g.end(), diff.begin());
    cout << "Difference with stdSet: " << (f == g) << endl;
    for (stdSet::iterator i = diff.begin(); i != diff.end(); i++) {
        cout << *i << endl;
    }
}

void solveWithQSet() {
    QSet<string> f, g;
    int lf, lg;
    f = parseQSetData(fFileName, lf);
    g = parseQSetData(gFileName, lg);
    QSet<string> diff = (f-g) + (g-f);
    cout << "Difference with QSet: " << endl;
    for (QSet<string>::iterator i = diff.begin(); i != diff.end(); i++) {
        cout << *i << endl;
    }
}

int main() {
    solveWithStdSet();
    cout << endl;
    solveWithQSet();
    return 0;
}
