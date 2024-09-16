/*
Задача: написать программу, обрабатывающую два типа запросов к словарю:

1 S — добавить слово S в словарь.
2 S — вывести количество слов в словаре, начинающихся на префикс S.
Входные данные:

Число N (1 ≤ N ≤ 50,000) — количество слов в словаре.
N строк — слова, состоящие из строчных латинских букв (длина каждого от 1 до 500).
Число M (1 ≤ M ≤ 50,000) — количество запросов.
M строк — запросы, состоящие из целого числа Tj (1 ≤ Tj ≤ 2) и строки Sj (длина от 1 до 500).
Выходные данные:

Для каждого запроса типа 2 вывести количество слов, начинающихся на заданный префикс.
 */

#include <iostream>

using namespace std;

const int k = 26;

struct Vertex {
    Vertex *to[k] = {0};
    bool terminal = 0;
    int cnt = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex *v = root;
    v->cnt++;
    for (char c: s) {
        c -= 'a';
        if (!v->to[c]) {
            v->to[c] = new Vertex();
        }
        v = v->to[c];
        v->cnt++;
    }
    v->terminal = true;
}

int get_cnt(string &s){
    Vertex *v = root;
    for (char c: s) {
        c -= 'a';
        if (!v->to[c]) {
            return 0;
        }
        v = v->to[c];
    }
    return v->cnt;
}


int main(){
    int n, a;
    string s;
    cin >>n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        add_string(s);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >>a>> s;
        if(a==1){
        add_string(s);}
        else{
            cout << get_cnt(s)<<'\n';
        }

    }
}
