#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Reuse fungsi push dan pop
void push(Node*& top, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top) {
    if (top == NULL) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// Fungsi untuk cek apakah tanda kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = NULL;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        // Jika kurung buka, push
        if (c == '(' || c == '{' || c == '[')
            push(stackTop, c);
        else if (c == ')' || c == '}' || c == ']') {
            // Jika kurung tutup tapi stack kosong, tidak seimbang
            if (stackTop == NULL) return false;
            char topChar = pop(stackTop);
            // Cek pasangan yang sesuai
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
                return false;
        }
    }

    // Stack harus kosong jika seimbang
    return stackTop == NULL;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}

// ?? Penjelasan:
// Kurung buka dimasukkan ke Stack. Saat ada kurung tutup, dicek apakah pasangan terakhirnya cocok.
// Jika tidak cocok atau Stack masih berisi sisa kurung buka, berarti tidak seimbang.

