#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

#define div ";"

extern void menu();

vector <string> split(string str, string divider)
{
  vector <string> res;
  int start = 0, end, delta = divider.length(), i = 0;
  while ((end = str.find(divider, start)) != string::npos)
  {
    res.push_back(str.substr(start, end - start));
    start = end + delta;
  }
  res.push_back(str.substr(start));
  return res;
}

struct type {
  string name;
  int people, duration, production;
};

void read()
{
  int i = 0;
  vector<type> Data;
  string temp;
  vector <string> buff;
  ifstream file("file.txt");
  if (file.fail())
  {
    cout << "Неможливо вiдкрити файл" << endl;
  }
  else
  {
    while (file.eof() != 1)
    {
      file >> temp;
      buff = split(temp, div);
      Data.resize(Data.size() + 1);
      Data[i].name = buff[0];
      Data[i].people = stoi(buff[1]);
      Data[i].duration = stoi(buff[2]);
      Data[i].production = stoi(buff[3]);
      i++;;
    }
    Data.pop_back();
    file.close();
  }
  cout << setw(10) << "Ім'я" << setw(20) << "Кількість людей" << setw(20) << "Тривалість зміни" << setw(20) << "Продуктивність" << setw(30) << "Продуктивність з міс"  << endl;
  if (Data.empty() == 0)
  {
    for (unsigned int i = 0; i < Data.size(); i++)
    {
      cout << setw(10) << Data[i].name << setw(20) <<
        Data[i].people << setw(20) <<
        Data[i].duration << setw(20) <<
        Data[i].production << setw(30) <<
        Data[i].production * 30 << endl;
    }
  }
  system("pause");
  menu();
}

void write()
{
  string name;
  int people, duration, production;
  cout << "Введіть ім'я" << endl;
  cin >> name;
  cout << "Введіть кількість людей" << endl;
  cin >> people;
  cout << "Введіть тривалість зміни" << endl;
  cin >> duration;
  cout << "Введіть продуктивність" << endl;
  cin >> production;
  ofstream file("file.txt", ios_base::app);
  file << name << div << people << div << duration << div << production << endl;
  file.close();
  system("pause");
  menu();
}

void menu()
{
  system("cls");
  cout << "Виберіть дію:" << endl;
  cout << "1. Записати у файл" << endl;
  cout << "2. Прочитати з файлу" << endl;
  cout << "3. Вихід" << endl;
  int ch;
  cin >> ch;
  switch (ch)
  {
  case 1:
  {
    write();
    break;
  }
  case 2:
  {
    read();
    break;
  }
  default:
    exit(0);
    break;
  }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    menu();
}
