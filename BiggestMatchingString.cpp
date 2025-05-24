#include <iostream>
#include <string>

using namespace std;
int n = 0;

int HashFunction(string str, int size, int position) { // сама€ примитивна€ иде€ хешировани€
    int hash = 0;
    for (int i = position; i < size; i++) {
        hash += (int)str[i];
        n++;
    }
    return hash;
}

bool CollisionCheck(string str1, string str2, int range, int position) { // collision check, nothing more to say
    bool isMatch = 1;
    for (int i = 0; i < range; i++) {
        n++;
        if (str1[position + i] != str2[i]) {
            isMatch = 0;
            break;
        }
    }
    return isMatch;
}

int FindPosition(string str, int strSize, string pattern, int patternSize, int patternHash) // возвращает позицию совпадени€ и -1, если такового нет
{
    int subStrHash = HashFunction(str, patternSize, 0);
    int position = -1; // ѕозици€ совпадени€

    for (int i = 0; i < strSize - patternSize; i++) { // searching for position
        n++;
        if (patternHash == subStrHash) {
            if (CollisionCheck(str, pattern, patternSize, i)) {
                position = i;
                break;
            }
        }
        subStrHash += str[patternSize + i] - str[i];
    }
    
    return position;
}

void sout(string str, int size, int pos) {// string out
    for (int i = pos; i < size + pos; i++)
        cout << str[i];
}

int main(int argc, char* argv[])
{
    string str1 = "123456789081023742358745842890088888888888888888899999999999999999999999999999999999999999999999999";
    string str2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    /*getline(cin, str1);
    getline(cin, str2);*/

    int firstStrSize = str1.length();
    int secondStrSize = str2.length();
    //char ASCII_Table[255];

    if (secondStrSize > firstStrSize) // делаем строку 1 наибольшей, если она таковой не €вл€етс€
    {
        string tempstring;
        tempstring = str1;
        firstStrSize += secondStrSize;
        secondStrSize = firstStrSize - secondStrSize;
        firstStrSize -= secondStrSize;
        str1 = str2;
        str2 = tempstring;
    }


    int position = -1;
    int maxLength = 0;
    int tempHash = HashFunction(str2, secondStrSize, 0);

    for (int pattern_size = secondStrSize; pattern_size > 0; --pattern_size){ // ищем паттерны из второй строки по убыванию длины
        int hash = tempHash;
        for (int offset = 0; offset <= secondStrSize - pattern_size;) {// ƒвигаем паттерн по строке, каждый раз свер€€
            char* pattern = &str2[offset];
            position = FindPosition(str1, firstStrSize, pattern, pattern_size, hash);
            hash += str2[pattern_size + offset] - str2[offset];
            offset++;
            n++;
            
            if (position != -1) break;
        }
        if (position != -1) {
            cout << "First Biggest match at " << position << endl;
            cout << "Biggest time at " << n << endl;
            sout(str1, pattern_size, position);
            return 0;
        }
        tempHash -= str2[pattern_size - 1];
    }

    cout << "no matches." << endl;
    cout << "Biggest time at " << n << endl;
    return 0;
}
//14.10.2024