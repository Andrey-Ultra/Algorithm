/*
Дана строка s. Найдите сумму значений префикс-функции для всех позиций строки s.

Входные данные
Во входном файле записана единственная строка s.

Выходные данные
В выходной файл выведите одно число — ответ на задачу.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); ++i) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    long long sum = 0;
    for (auto i: p) {
        sum += i;
    }
    cout<<sum;
}