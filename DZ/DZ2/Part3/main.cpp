#include <iostream>
#include <string.h>

using namespace std;

typedef struct Word {
    char text[50];
    int len;
    int numberOfConsonants;
    Word(): text(""), len(0), numberOfConsonants(0) {}

    Word(const char* _text) {
        strcpy(text, _text);
        char* curr = text;
        len = 0;
        numberOfConsonants = 0;
        while(*curr != '\0') {
            len += 1;
            char c = *curr;
            bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            bool isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
            if (!(isLowercaseVowel || isUppercaseVowel)) {
                numberOfConsonants += 1;
            }
            curr++;
        }
    }

    int getNumberOfVowels() {
        return len - numberOfConsonants;
    }
} Word;

struct TreeNode {
    int idx;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* lft = nullptr, TreeNode* rght = nullptr) : idx(val), left(lft), right(rght) {}
};

TreeNode* addNode(Word* (&arr), int value, TreeNode* node) {
    if (!node) node = new TreeNode(value);
    else {
        if (strcmp(arr[value].text, arr[node->idx].text) < 0) node->left = addNode(arr, value, node->left);
        else node->right = addNode(arr, value, node->right);
    }
    return node;
}

void freeMemory(TreeNode* node) {
    if (node) {
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
}

void findObjectByWord(Word* (&arr), char (&word)[50], TreeNode* currRoot) {
    if (currRoot == nullptr) {
        cout << "No such word" << endl;
    } else {
        if (strcmp(arr[currRoot->idx].text, word) == 0) {
            cout << currRoot->idx << ' ' << arr[currRoot->idx].text << ' ' << arr[currRoot->idx].len << endl;
        } else {
            if (strcmp(arr[currRoot->idx].text, word) < 0) {
                findObjectByWord(arr, word, currRoot->right);
            } else {
                findObjectByWord(arr, word, currRoot->left);
            }
        }
    }
}

void solve(Word* (&arr), const int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].len - arr[i].numberOfConsonants > arr[i].numberOfConsonants) counter++;
    }
    cout << "Answer: " << counter << endl;
}

int main()
{
    int n;
    cout << "Enter number of string" << endl;
    cin >> n;
    char txt[50];
    cin >> txt;
    Word* arr = new Word[n];
    arr[0] = Word(txt);
    for (int i = 0; i < n-1; i++) {
        cin >> txt;
        arr[i+1] = Word(txt);
    }
    solve(arr, n);
    TreeNode* tree = new TreeNode(0);
    for (int i = 1; i < n; i++) {
        addNode(arr, i, tree);
    }
    cout << "Enter word to find" <<endl;
    char wrd[50];
    cin >> wrd;
    findObjectByWord(arr, wrd, tree);
    delete [] arr;
    freeMemory(tree);
    return 0;
}
