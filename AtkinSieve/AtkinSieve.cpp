// AtkinSieve.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

vector<bool> getPrimesUpTo(unsigned const limit) {
    vector<bool> sieve(limit);

    for (unsigned long long x2 = 1ull, dx2 = 3ull; x2 < limit; x2 += dx2, dx2 += 2ull)
        for (unsigned long long y2 = 1ull, dy2 = 3ull, n; y2 < limit; y2 += dy2, dy2 += 2ull) {

            // n = 4x² + y²
            n = (x2 << 2ull) + y2;
            if (n <= limit && (n % 12ull == 1ull || n % 12ull == 5ull))
                sieve[n].flip();

            // n = 3x² + y²
            n -= x2;
            if (n <= limit && n % 12ull == 7ull)
                sieve[n].flip();

            // n = 3x² - y² (при x > y)
            if (x2 > y2) {
                n -= y2 << 1ull;
                if (n <= limit && n % 12ull == 11ull)
                    sieve[n].flip();
            }
        }
    // Все числа, кратные квадратам, помечаются как составные
    unsigned r = 5u;
    for (unsigned long long r2 = r * r, dr2 = (r << 1ull) + 1ull; r2 < limit; ++r, r2 += dr2, dr2 += 2ull)
        if (sieve[r])
            for (unsigned long long mr2 = r2; mr2 < limit; mr2 += r2)
                sieve[mr2] = false;

    // Числа 2 и 3 — заведомо простые
    if (limit > 2u)
        sieve[2u] = true;
    if (limit > 3u)
        sieve[3u] = true;
    return sieve;
}

int main()
{
    unsigned limit;

    for (limit = 10; limit <= pow(10, 7); limit *= 10) {
        cout << limit << endl;

        unsigned int start_time = clock();
        auto start = chrono::high_resolution_clock::now();

        vector<bool> primes = getPrimesUpTo(limit);

        auto finish = chrono::high_resolution_clock::now();
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        for (unsigned number = 2u; number < limit; ++number)
            if (primes[number]) {
                cout << number << ' ';
            }

        cout << '\n';

        cout << "start time: " << start_time << endl;
        cout << "end time: " << end_time << endl;
        cout << "search time: " << search_time << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
        cout << endl;
    }
    
    for (limit = 16; limit <= pow(2, 13); limit *= 2) {
        cout << limit << endl;

        unsigned int start_time = clock();
        auto start = chrono::high_resolution_clock::now();

        vector<bool> primes = getPrimesUpTo(limit);

        auto finish = chrono::high_resolution_clock::now();
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        for (unsigned number = 2u; number < limit; ++number)
            if (primes[number]) {
                cout << number << ' ';
            }

        cout << '\n';

        cout << "start time: " << start_time << endl;
        cout << "end time: " << end_time << endl;
        cout << "search time: " << search_time << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
        cout << endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
