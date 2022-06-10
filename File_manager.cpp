#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <Windows.h>
#include "Configuration.h"

extern "C" char* addStr(char* a, char* b, char* c);						// функция сложения 3-х строк из .asm файла

void save_message(char* nameFile, char* message) {

	char fileName[13]{};

	for (int i = 0; i < 12; i++) {
		fileName[i] = nameFile[i];
	}

	nameFile = addStr(fileName, (char*)".", (char*)"txt");				// получение имени файла
	/*Костыль!!!*/
	for (int i = strlen(fileName) + 4; i < 20; i++) {					// при повторном вызове expectationCommand() строка почему-то получается с мусором, форматирование строки
		nameFile[i] = 0;
	}
	FILE* file;
	file = fopen(nameFile, "a");										// открытие файла
	fprintf(file, "%s\n", message);										// запись
	fclose(file);
}

void readMessages(char* file) {											//чтение сообщений
	FILE* fp;
	char string[1000] = "";
	if ((fp = fopen(file, "r")) == NULL)
	{
		printf("Не удалось открыть файл\n");
	}
	bool otherMessage = 0;
	while (!feof(fp)) {
		if (otherMessage) {												// сообщения отправителя
			otherMessage = 0;
			printf("						 %s\n", string);
		}
		else {
			if (string[0] == '+') {
				otherMessage = 1;											// обнаружение сообщений отправителя
				printf("%s", string);										// имя отправителя
			}
			else {
				printf("%s\n", string);										// мои сообщения
			}
		}
		fscanf(fp, "%s[\n]", &string);
	}
	printf("\n");
}

void get_list_file() {													// получение списка файлов
	const char fileTypes[] = "*.txt";

	WIN32_FIND_DATAA FindFileData;
	HANDLE hf = FindFirstFileA(fileTypes, &FindFileData);

	use_Unicode;
	printf(gethistory);

	if (hf != INVALID_HANDLE_VALUE) {
		do {
			printf("%s  ", FindFileData.cFileName);
		} while (FindNextFileA(hf, &FindFileData));
		FindClose(hf);
	}
	printf("\nВведите интересуемое имя чата:\n");
	char file[17];
	scanf("%s", file);
	readMessages(file);
}

