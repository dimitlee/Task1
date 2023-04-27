#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <locale>
#include <fstream>
#include <windows.h>
#include <codecvt>

using namespace std;

// Функция изменения текста, подсчитывает повторения символов в строке, затем составляет нужную строку
wstring change_string(wstring text) 
{
    unordered_map<wchar_t, int> char_count;
    wstring result_string = L"";

    for (wchar_t a : text) 
    {
        a = towlower(a);
        if (char_count.count(a) == 0) 
        {
            char_count.insert({a, 1});
        }
        else
        {
            char_count[a]++;
        }
    }
    for (wchar_t a : text)
    {
        a = towlower(a);
        if (char_count[a] == 1)
        {
            result_string += L"(";
        }
        else
        {
            result_string += L")";
        }
    }
    return result_string;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    wstring input_string;
    wstring result_string;

    while (true)
    {
        wcout << L"Введите текст (Чтобы выйти отправьте q): ";
        getline(wcin, input_string);
        if (input_string == L"q")
        {
            break;
        }
        result_string = change_string(input_string);
        wcout << input_string << L" : " << result_string << endl;
    }
    
    return 0;
}