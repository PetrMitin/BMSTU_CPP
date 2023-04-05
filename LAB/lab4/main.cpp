#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct letterData {
    letterData(int app=0, int bef=0) : appearances(app), beforeA(bef) {}
    int appearances;
    int beforeA;
};

typedef pair<char, letterData> letterMapNode;
typedef map<char, letterData> lettersDict;
typedef vector<letterMapNode> lettersVector;


lettersDict parseData(char text[]) {
    lettersDict data;
    char *ptr;
    ptr = &text[0];
    while (*ptr != '\0') {
        char l = *ptr;
        if (l != ' ') {
            data[l].appearances++;
            if (*(ptr+1) == 'a') data[l].beforeA++;
        }
        ptr++;
    }
    return data;
}

bool cmpDesc(letterMapNode el1, letterMapNode el2) {
    return el1.second.appearances < el2.second.appearances;
}

lettersVector sortParsedData(const lettersDict& data) {
   lettersVector vec;
   for (auto& it : data) if (it.second.beforeA) vec.push_back(it);
   sort(vec.begin(), vec.end(), cmpDesc);
   return vec;
}

void printSortedData(const lettersVector sortedData) {
    cout << "Sorted letters, appearances and beforeA: " << '\n';
    if (!sortedData.size()) cout << "None of such letters were found!" << endl;
    else for (auto elem : sortedData) cout << elem.first << ' ' << elem.second.appearances << ' ' << elem.second.beforeA << endl;
}

void printAdressOfWordsWithTwoA(char text[]) {
    char *token, *nexttoken, *ptr;
    char seps[] = " ";
    token = strtok_s(text, seps, &nexttoken);
    cout << "Adresses: " << '\n';
    while (token != nullptr)
    {
        ptr = token;
        int count = 0;
        while (*ptr != '\0') {
            if (*ptr == 'a') count++;
            ptr++;
        }
        if (count >= 2) printf("%p\n", token);
        token = strtok_s(nullptr, seps, &nexttoken);
    }
}

int main()
{
    char text[255];
    cout << "Enter text" << endl;
    gets_s(text);
    printSortedData(sortParsedData(parseData(text)));
    printAdressOfWordsWithTwoA(text);
    return 0;
}
