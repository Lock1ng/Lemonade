
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


struct UP {
	int numberbook{};
	int evaluations[5];
	string surname{};
	string numbergroup{};
};

UP input_nap(UP s) {
	cout << "Фамилию и инициалы: ";
	getline(cin, s.surname);
	cout << "Номер группы ";
	getline(cin, s.numbergroup);
	cout << "Введите номер зачетной книжки: ";
	cin >> s.numberbook;
	cout << "Введите оценки: ";
	cin >> s.evaluations[0];
	cin >> s.evaluations[1];
	cin >> s.evaluations[2];
	cin >> s.evaluations[3];
	cin >> s.evaluations[4];
	return s;
}

bool compareTwoStudents(UP a, UP b)
{
	return a.numberbook < b.numberbook;
}

void computeRanks(UP a[], int cnt)
{
	sort(a, a + cnt, compareTwoStudents);
}

void output_massiv_nap(UP *users, int cnt) {
	int j = 0;
	cout.width(25);
	cout << left << "Фамилию и инициалы: ";
	cout.width(25);
	cout << left << "Номер группы ";
	cout.width(25);
	cout << left << "Номер зачетной книжки: ";
	cout.width(25);
	cout << left << "Оценки: " << endl;
	cout.width(25);
	for (j; j < cnt; j++) {
		if (users[j].numberbook != 0) {
			cout.width(25);
			cout << left << users[j].surname;
			cout.width(25);
			cout << left << users[j].numbergroup;
			cout.width(25);
			cout << left << users[j].numberbook;
			cout << left << users[j].evaluations[0] << left << users[j].evaluations[1] << left << users[j].evaluations[2] << left << users[j].evaluations[3] << left << users[j].evaluations[4] << endl;
		}
	}
};
int find_index(UP* s, UP d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if (s[i].numberbook == d.numberbook) {
			return i;
		}
	}
}
int find_index_first(UP* s, int d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if (s[i].numberbook == d) {
			return i;
		}
	}
}
int find_index_last(UP* s, int d, int maxx) {
	int i = 0;
	for (i; i < maxx; i++) {
		if ((s[i].numberbook == d) && (s[i + 1].numberbook != d)) {
			return i;
		}
	}
}
int delete_year(UP *one, int cnt, string n) {
	int i = 0;
	int d = cnt;
	for (i; i < cnt; i++) {
		if (one[i].numbergroup == n) {
			one[i].numbergroup = '0';
			one[i].surname = '0';
			one[i].numberbook = 0;
			one[i].evaluations[0] = 0;
			one[i].evaluations[1] = 0;
			one[i].evaluations[2] = 0;
			one[i].evaluations[3] = 0;
			one[i].evaluations[4] = 0;
			d = d - 1;
		}
	}
	return d;
}
void permutations(UP *s, UP d, int j, int cnt) {
	int i = 0;
	for (i = cnt; i >= j; i--) {
			s[i + 1] = s[i];
	}
	s[j] = d;
}
int main() {

	system("chcp 1251");
	system("cls");
	int cnt = 0;
	int i = 0;
	int otvet;
	const int maxx = 99;
	bool a = true;
	UP one;
	UP users[maxx + 1];
	UP test;
	UP users_test;
	cout << "Выберите режим:\n1.Заполнить запись по одному учебному плану с клавиатуры.\n\
2.Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления.\
\n3.Вывести названия профилей и год начала действия учебного плана заданного направления\n\
4.Удалить планы срок действия которых истек при прошествии 4-х лет.\n\
5.Вывести все данные\n\
6.Завершить работу\n" << endl;
	while (a) {
		cin >> otvet;
		cin.get();
			if (otvet == 1) {
				users[i] = input_nap(one);
				cnt++;
				i++;
				cout << "Запись добавлена!" << endl;
				computeRanks(users, cnt);
			}
			if (otvet == 2) {
				users[i] = input_nap(one);
				cnt++;
				i++;
				cout << "Запись добавлена!" << endl;
				computeRanks(users, cnt);
			}
			if (otvet == 3) {
				int maxxx = -1;
				for (int j = 0; j < cnt; j++) {
					float us = (users[j].evaluations[0] + users[j].evaluations[1] + users[j].evaluations[2] + users[j].evaluations[3] + users[j].evaluations[4]) / 5;
					if (us > maxxx) {
						maxxx = us;
					}
				}
				for (int j = 0; j < cnt; j++) {
					float us = (users[j].evaluations[0] + users[j].evaluations[1] + users[j].evaluations[2] + users[j].evaluations[3] + users[j].evaluations[4]) / 5;
					if (us == maxxx) {
						cout  << users[j].numberbook << endl;
					}
				}
			}
			if (otvet == 4) {
				string book;
				cout << "Введите номер группы!" << endl;
				cin >> book;
				delete_year(users, cnt, book);
				computeRanks(users, cnt);
				cout << "Записи удалены!" << endl;
			}
			if (otvet == 5) {
				output_massiv_nap(users, cnt);
			}
			if (otvet == 6) {
				return 0;
			}
			cout << "\nВыберите режим:\n1.Заполнить запись по одному учебному плану с клавиатуры.\n\
2.Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления.\
\n3.Вывести названия профилей и год начала действия учебного плана заданного направления\n\
4.Удалить планы срок действия которых истек при прошествии 4-х лет.\n\
5.Вывести все данные\n\
6.Завершить работу\n" << endl;
	}
}
