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

void hashTableFill(int* hashTable, string str, int str_Size) {
    hashTable[0] = (int)str[0];
    for (int i = 1; i < str_Size; i++) {
        hashTable[i] = (int)str[i] + hashTable[i - 1];
        n++;
    }
}

bool CollisionCheck(string str1, string str2, int range, int position) { // collision check, nothing more to say
    for (int i = 0; i < range; i++) {
        n++;
        if (str1[position + i] != str2[i]) {
            return 0;
        }
    }
    return 1;
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

int SearchPattern(string str1, string str2, int secondStrSize, int pattern_size, int hash, int firstStrSize, int tempHash) {
    int position = -1;

    for (int offset = 0; offset <= secondStrSize - pattern_size;) {// ƒвигаем паттерн по строке, каждый раз свер€€
        char* pattern = &str2[offset];
        position = FindPosition(str1, firstStrSize, pattern, pattern_size, hash);
        hash += str2[pattern_size + offset] - str2[offset];
        offset++;
        n++;

        if (position != -1) break;
    }
    if (position != -1) {
        cout << "First biggest match at " << position << endl;
        cout << "Biggest time at " << n << endl;
        sout(str1, pattern_size, position);
        return position;
    }
    tempHash -= str2[pattern_size - 1];
}

int BinarySearch(string str1, string str2, int* tempHash, int secondStrSize, int firstStrSize) {
    int position = -1;
    int prev_position = -1;
    int pattern_size = secondStrSize / 2;
    int upper_limit = secondStrSize;

    while()
    return prev_position;
}

int main(int argc, char* argv[])
{
    string str1 = "123456789081023742358745842890088888888888888888899999999999999999999999999999999999999999999999999";
    string str2 = "qwertyuiopasdf88888;987650098765";
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
    int* hashTable1 = new int[firstStrSize];
    int* hashTable2 = new int[secondStrSize];
    hashTableFill(hashTable1, str1, firstStrSize);
    hashTableFill(hashTable2, str2, secondStrSize);


    int position = -1;
    int maxLength = 0;
    int tempHash = HashFunction(str2, secondStrSize, 0);

    position = BinarySearch(str1, str2, hashTable2, secondStrSize, firstStrSize);

    //cout << "no matches." << endl;
    cout << "Biggest time at " << n << endl;
    return 0;
}
//14.10.2024