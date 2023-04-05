#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct Book {
    char name[20];
    int year;
    Book() {}
    Book(const char _name[20], int _year): year(_year) {
        strncpy(name, _name, sizeof(name));
    }
} Book;

const char* filename = "C://Users/peter/BMSTU/BMSTU_CPP/DZ/DZ2/Part2/books.txt";
const char* namesIndexFilename = "C://Users/peter/BMSTU/BMSTU_CPP/DZ/DZ2/Part2/namesIndex.txt";
const char* yearIndexFilename = "C://Users/peter/BMSTU/BMSTU_CPP/DZ/DZ2/Part2/yearIndex.txt";
const char* FORMAT = "%s %d\n";

string genRandomString(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}

void generateDataFile() {
    FILE* file;
    fopen_s(&file, filename, "w+b");
    for (int i = 0; i < 1000000; i++) {
        string s = genRandomString(20);
        char s1[20];
        for (int j = 0; j < 20; j++) {
            s1[j] = s[j];
        }
        Book rec(s1, rand());
        fwrite(&rec, sizeof(rec), 1, file);
    }
    fclose(file);
}

void searchByName(const char* title) {
    FILE* file;
    fopen_s(&file, filename, "rb");
    for (int i = 0; i < 1000000; i++) {
        Book rec;
        fread(&rec, sizeof(rec), 1, file);
        if (
                strcmp(rec.name, title) == 0
                //i%10000 ==0
                ) cout << rec.name << ' ' << rec.year << endl;
    }
    fclose(file);
}

void searchByYear(int year) {
    FILE* file;
    fopen_s(&file, filename, "rb");
    bool flag = true;
    for (int i = 0; i < 1000000; i++) {
        Book rec;
        fread(&rec, sizeof(rec), 1, file);
        if (
                rec.year == year && flag
                //i%10000 ==0
                ) {
            cout << rec.name << ' ' << rec.year << endl;
            flag = false;
        }
    }
    fclose(file);
}

bool compareBooksByName(const pair<int, Book> &b1, const pair<int, Book> &b2) {
    return strcmp(b1.second.name, b2.second.name) < 0;
}

bool compareBooksByYear(const pair<int, Book> &b1, const pair<int, Book> &b2) {
    return b1.second.year < b2.second.year;
}


void generateIndexFiles() {
    FILE* file;
    fopen_s(&file, filename, "rb");
    vector<pair<int, Book>> sortedBooks;
    for (int i = 0; i < 1000000; i++) {
        Book rec;
        fread(&rec, sizeof(rec), 1, file);
        pair<int, Book> p(i, rec);
        sortedBooks.push_back(p);
    }
    fclose(file);
    sort(sortedBooks.begin(), sortedBooks.end(), compareBooksByName);
    FILE* namesIndexFile;
    fopen_s(&namesIndexFile, namesIndexFilename, "w+b");
    for (vector<pair<int, Book>>::iterator i = sortedBooks.begin(); i != sortedBooks.end(); i++) {
        int idx = i->first;
        fwrite(&idx, sizeof(idx), 1, namesIndexFile);
    }
    fclose(namesIndexFile);
    sort(sortedBooks.begin(), sortedBooks.end(), compareBooksByYear);
    FILE* yearIndexFile;
    fopen_s(&yearIndexFile, yearIndexFilename, "w+b");
    for (vector<pair<int, Book>>::iterator i = sortedBooks.begin(); i != sortedBooks.end(); i++) {
        int idx = i->first;
        fwrite(&idx, sizeof(idx), 1, yearIndexFile);
    }
    fclose(yearIndexFile);
}

void searchByNameWithIndex(const char* name) {
    FILE* indexFile, *dataFile;
    fopen_s(&indexFile, namesIndexFilename, "rb");
    fopen_s(&dataFile, filename, "rb");
    long lbIdx = 0;
    long rbIdx = sizeof(int)*(1000000-1);
    long curr = (lbIdx + rbIdx) / 2;
    curr -= curr % sizeof(int);
    Book rec;
    int idx;
    fseek(indexFile, curr, 0);
    fread(&idx, sizeof(idx), 1, indexFile);
    fseek(dataFile, idx * sizeof(rec), 0);
    fread(&rec, sizeof(rec), 1, dataFile);
    while (strcmp(name, rec.name) != 0 && lbIdx < rbIdx) {
        if (strcmp(name, rec.name) < 0) {
            rbIdx = curr;
        } else {
            lbIdx = curr;
        }
        curr = (lbIdx + rbIdx) / 2;
        curr -= curr % sizeof(int);
        fseek(indexFile, curr, 0);
        fread(&idx, sizeof(idx), 1, indexFile);
        fseek(dataFile, idx * sizeof(rec), 0);
        fread(&rec, sizeof(rec), 1, dataFile);
    }
    cout << idx << ' ' << rec.name << ' ' << rec.year << endl;
}

void searchByYearWithIndex(int year) {
    FILE* indexFile, *dataFile;
    fopen_s(&indexFile, yearIndexFilename, "rb");
    fopen_s(&dataFile, filename, "rb");
    long lbIdx = 0;
    long rbIdx = sizeof(int)*(1000000-1);
    long curr = (lbIdx + rbIdx) / 2;
    curr -= curr % sizeof(int);
    Book rec;
    int idx;
    fseek(indexFile, curr, 0);
    fread(&idx, sizeof(idx), 1, indexFile);
    fseek(dataFile, idx * sizeof(rec), 0);
    fread(&rec, sizeof(rec), 1, dataFile);
    while (rec.year != year && lbIdx < rbIdx) {
        if (year < rec.year) {
            rbIdx = curr;
        } else {
            lbIdx = curr;
        }
        curr = (lbIdx + rbIdx) / 2;
        curr -= curr % sizeof(int);
        fseek(indexFile, curr, 0);
        fread(&idx, sizeof(idx), 1, indexFile);
        fseek(dataFile, idx * sizeof(rec), 0);
        fread(&rec, sizeof(rec), 1, dataFile);
    }
    cout << idx << ' ' << rec.name << ' ' << rec.year << endl;
}

int main()
{
    //generateDataFile();
    //generateIndexFiles();
    auto start = high_resolution_clock::now();
    searchByName("hdIEfqnowrawMd3Wef1K][");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    searchByYear(324);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    searchByNameWithIndex("hdIEfqnowrawMd3Wef1K][");
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    searchByYearWithIndex(324);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << endl;
    return 0;
}
