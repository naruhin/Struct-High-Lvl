
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>



struct birthDate //Структура хранит значения даты рождения 
{
	unsigned short day;			//день
	unsigned short month;			//месяц
	unsigned short year;			//год
};

struct GROUP {
	char Name[32];		   //Фамилия и инициалы
	birthDate DAT;         //Дата рождения
	unsigned short SES;		       //Успеваемость	
};

void fillingArray(GROUP *GR5, int N){          //Ввод с клавиатуры данных в массив GR5, состоящий из 10 структур типа GROUP 
	std::cout << "\t\tЗаполнение списка:(Для начала нажмите Enter)" << std::endl;
	std::cin.ignore();
	for (int i = 0; i < N; i++)
	{
		std::cout << "Фамилия и инициалы: ";
		gets_s(GR5[i].Name);
		std::cout << "Дата рождения: " << std::endl;

		DAY:
		std::cout << "День: ";
		std::cin >> GR5[i].DAT.day;
		if ( GR5[i].DAT.day < 0 || GR5[i].DAT.day > 31) {
			std::cout << "Ошибка! Значение должно быть в промежутке от 0 до 31." << std::endl;
			goto DAY;
		}
		
		
		
		MONTH:
		std::cout << "Месяц: ";
		std::cin >> GR5[i].DAT.month;
		if (GR5[i].DAT.month > 12 || GR5[i].DAT.month < 0) {
			std::cout << "Ошибка! Значение должно быть в промежутке от 0 до 12." << std::endl;
			goto MONTH;
		}
		

		YEAR:
		std::cout << "Год: ";
		std::cin >> GR5[i].DAT.year;
		if (GR5[i].DAT.year > 2019) {
			std::cout << "Ошибка! Видимо он ещё не родился!" << std::endl;
			goto YEAR;
		}
		
		SES:
		std::cout << "Успеваемость: ";
		std::cin >> GR5[i].SES;
		if (GR5[i].SES > 100 || GR5[i].SES < 0) {
			std::cout << "Ошибка! Значение успеваемости должно быть в промежутке от 0 до 100" << std::endl;
			goto SES;
		}
		
		std::cin.ignore();
		std::cout << std::endl;
	}
	
}

void displayingEntriesOrdereByAscendingOfSES(GROUP *GR5, int N) {  //Вывод записей, упорядоченных по возростянию поля SES

	for (int i = N - 1; i >= 0; i--){			//сортировка по SES-успеваемости
		for (int j = 0; j < i; j++){
			if (GR5[j].SES > GR5[j + 1].SES){
				GROUP tmp = GR5[j];
				GR5[j] = GR5[j + 1];
				GR5[j + 1] = tmp;
			}
		}
	}
	std::cout << "\t\tУпорядоченый список по успеваемости:" << std::endl;			//Вывод упорядоченого списка 
	for (int i = 0; i < N; i++){        
		
		std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

		std::cout << "|Фамилия и инициалы: "  << std::setw(strlen(GR5[i].Name)) <<GR5[i].Name << '|' << std::endl;

		std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

		std::cout << "|Дата рождения: " << std::setw(strlen(GR5[i].Name) - 2) << std::setfill(' ') << GR5[i].DAT.day << '/' << GR5[i].DAT.month << '/' << GR5[i].DAT.year << '|' << std::endl;

		std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

		std::cout << "|Успеваемость: " << std::setw(5 + strlen(GR5[i].Name)) << std::setfill(' ') << GR5[i].SES << "%|"  << std::endl;

		std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl << std::endl;
	}
	
}

void displayStudentsWhoAreLessThan20Years(GROUP *GR5, int N) {                     
	std::cout << "\t\tСтуденты, которым на 01/12/2010 меньше 20 лет" << std::endl;
	bool check = false;//Булевая переменная.Нужна для того , чтоб мы могли определить есть ли студенты которым меньше 20 лет.
	for (int i = 0; i < N; i++)
	{
		//Находим разницу между датой 01/12/2010, переведённой в дни и датой рождения ,переведённой в дни.
		//Полученное число дней делим на количество дней в году тем самым находим количество лет и сравниваем с 20.
		if ((float)((1 + 12 * 31 + 2010 * 365) - (GR5[i].DAT.day + GR5[i].DAT.month * 31 + GR5[i].DAT.year * 365)) / 365 <= 20) {
			std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

			std::cout << "|Фамилия и инициалы: " << std::setw(strlen(GR5[i].Name)) << GR5[i].Name << '|' << std::endl;

			std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

			std::cout << "|Дата рождения: " << std::setw(strlen(GR5[i].Name) - 2) << std::setfill(' ') << GR5[i].DAT.day << '/' << GR5[i].DAT.month << '/' << GR5[i].DAT.year << '|' << std::endl;

			std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl;

			std::cout << "|Успеваемость: " << std::setw(5 + strlen(GR5[i].Name)) << std::setfill(' ') << GR5[i].SES << "%|" << std::endl;

			std::cout << std::setw(21 + strlen(GR5[i].Name)) << std::setfill('-') << '-' << std::ends << std::endl << std::endl;

			check = true; //Если условие выполнится хотя-бы раз булевое значение изменится на true, тем самым показывая наличия студентов которым меньше 20 лет.
		}
	}
	if (check == false) //Если булевая переменная не поменялась это значит,что условие не выполнилось.Итог - на экран выведется сообщение о неналичии нужных студентов.
		std::cout << "Нет студентов, которым меньше 20 лет." << std::endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	const int N = 3;
	GROUP *GR5 = new GROUP[N];//Выделение памяти под динамический массив
	fillingArray(GR5, N);//Вызов функции заполнения
	
	while (true) //Своеобразное меню опций для удобной работы со списком.
	{
		std::cout << "Выберите функцию\n 1 - заполнить список заново,\n 2 - вывести список по упорядоченный по успеваемости,\n 3 - вывести список студентов, которым меньше 20 лет на 01/12/2010,\n 4 - закончить работу: ";
		int choose;
		std::cin >> choose;
		switch (choose) {
		case 1:
			fillingArray(GR5, N);
			break;
		case 2:
			displayingEntriesOrdereByAscendingOfSES(GR5, N);
			break;
		case 3:
			displayStudentsWhoAreLessThan20Years(GR5, N);
			break;
		case 4:
			return 0;
		default:
			std::cout << "Ошибка!Некорректный ввод!";
			continue;
		}
	}
	

	delete[]GR5; //Очистка зарезервированной памяти

	return 0;
}

