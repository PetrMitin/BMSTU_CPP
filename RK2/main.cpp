#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct ListElement {
    char word[20];
    ListElement* prev;
    ListElement* next;

    ListElement(char* _word, ListElement* _prev=nullptr, ListElement* _next=nullptr): prev(_prev), next(_next) {
        strcpy(word, _word);
    }
} ListElement;

bool isVowel(char c) {
    bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    bool isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    return isLowercaseVowel || isUppercaseVowel;
}

void solve(ListElement* first) {
    int counter = 0;
    ListElement* curr = first;
    while (curr != nullptr) {
        cout << curr->word << ' ';
        if (isVowel(curr->word[0])) {
            counter++;
            cout << "starts with vowel";
        }
        cout << endl;
        curr = curr->next;
    }
    cout << counter << endl;
}

void freeMemory(ListElement* first) {
    ListElement* curr = first, *pr;
    while (curr != nullptr) {
        pr = curr;
        curr = curr->next;
        delete pr;
    }
}

int main()
{
    char text[300], *token, *nexttoken;
    cout << "Enter string" << endl;
    cin.getline(text, 300);
    token = strtok_s(text, " ", &nexttoken);
    ListElement* first, *last;
    bool flag = true;
    while (token != nullptr)
    {
        ListElement* curr = new ListElement(token);
        if (flag) {
            first = curr;
            last = curr;
            flag = false;
        }
        curr->prev = last;
        last->next = curr;
        last = curr;
        token = strtok_s(nullptr, " ", &nexttoken);
    }
    solve(first);
    freeMemory(first);
    return 0;
}
