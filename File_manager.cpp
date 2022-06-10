#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <Windows.h>
#include "Configuration.h"

extern "C" char* addStr(char* a, char* b, char* c);						// ������� �������� 3-� ����� �� .asm �����

void save_message(char* nameFile, char* message) {

	char fileName[13]{};

	for (int i = 0; i < 12; i++) {
		fileName[i] = nameFile[i];
	}

	nameFile = addStr(fileName, (char*)".", (char*)"txt");				// ��������� ����� �����
	/*�������!!!*/
	for (int i = strlen(fileName) + 4; i < 20; i++) {					// ��� ��������� ������ expectationCommand() ������ ������-�� ���������� � �������, �������������� ������
		nameFile[i] = 0;
	}
	FILE* file;
	file = fopen(nameFile, "a");										// �������� �����
	fprintf(file, "%s\n", message);										// ������
	fclose(file);
}

void readMessages(char* file) {											//������ ���������
	FILE* fp;
	char string[1000] = "";
	if ((fp = fopen(file, "r")) == NULL)
	{
		printf("�� ������� ������� ����\n");
	}
	bool otherMessage = 0;
	while (!feof(fp)) {
		if (otherMessage) {												// ��������� �����������
			otherMessage = 0;
			printf("						 %s\n", string);
		}
		else {
			if (string[0] == '+') {
				otherMessage = 1;											// ����������� ��������� �����������
				printf("%s", string);										// ��� �����������
			}
			else {
				printf("%s\n", string);										// ��� ���������
			}
		}
		fscanf(fp, "%s[\n]", &string);
	}
	printf("\n");
}

void get_list_file() {													// ��������� ������ ������
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
	printf("\n������� ������������ ��� ����:\n");
	char file[17];
	scanf("%s", file);
	readMessages(file);
}

