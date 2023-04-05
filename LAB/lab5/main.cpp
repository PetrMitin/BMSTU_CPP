#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    int value;
    Node () : value(0), prev(nullptr), next(nullptr) {}
    Node(int val, Node *pr=nullptr, Node *nxt=nullptr) : value(val), prev(pr), next(nxt) {}
};

typedef pair<Node *, Node *> NodePair;
typedef pair<NodePair, int> ParsedData;

 ParsedData parseDataFromString(char *str) {
    ParsedData result;
    NodePair resultData;
    char *token, *nexttoken;
    const char sep=' ';
    Node *first, *last;
    token = strtok_s(str, &sep, &nexttoken);
    first = new Node(atoi(token));
    token = strtok_s(nullptr, &sep, &nexttoken);
    int val = atoi(token);
    Node *curr = new Node(val, first);
    (*first).next = curr;
    last = curr;
    token = strtok_s(nullptr, &sep, &nexttoken);
    int len = 2;
    while (token != nullptr) {
        len++;
        int val = atoi(token);
        curr = new Node(val);
        (*curr).prev = last;
        (*last).next = curr;
        last = curr;
        token = strtok_s(nullptr, &sep, &nexttoken);
    }
    resultData.first = first;
    resultData.second = last;
    result.first = resultData;
    result.second = len;
    return result;
}

Node *sortList(NodePair l, int len) {
    Node *left = l.first;
    Node *right = left->next;
    int x;
    while (left->next) {
        while (right) {
            if ((left->value) > (right->value)) {
                x = left->value;
                left->value = right->value;
                right->value = x;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
    }
    while ((*left).prev != nullptr) {
        left = (*left).prev;
    }
    return left;
}

void printSortedListAndDelete(Node *n) {
    Node *curr = n;
    cout << "Output 1: " << endl;
    cout << (*curr).value << ' ';
    while ((*curr).next != nullptr) {
        curr = (*curr).next;
        cout << (*curr).value << ' ';
    }
    cout << '\n' << "Output 2: " << endl;
    cout << (*curr).value << ' ';
    while ((*curr).prev != nullptr) {
        curr = (*curr).prev;
        delete (*curr).next;
        cout << (*curr).value << ' ';
    }
    cout << endl;
    delete curr;
}

void solve(Node *l, int n) {
    Node *curr = l;
    int counter = 0;
    do {
        int val = curr->value;
        int sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        if (sum > n) counter++;
        curr = (*curr).next;
    } while (curr != nullptr);
    cout << "Ans: " << counter << endl;
}

int main()
{
    char *text = new char[255];
    cout << "Enter text" << endl;
    gets_s(text, sizeof(char)*255);
    pair<NodePair, int> parsedData = parseDataFromString(text);
    int l = parsedData.second;
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    NodePair data = parsedData.first;
    Node *first = sortList(data, l);
    solve(first, n);
    printSortedListAndDelete(first);
    delete[] text;
    return 0;
}
