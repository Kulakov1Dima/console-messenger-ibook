#define _CRT_SECURE_NO_WARNINGS
#include "Messanger.h"
#include <string.h>
#include <stdio.h>
#include "File_manager.h"

extern "C" char* addStr(char* a, char* b, char* c);						// ������� �������� 3-� ����� �� .asm �����

char* send_message_JSON(char* name) {									// ������� ��������� json ������, �� ������� ������ �������� ��������� (���� version)

	char recipient[13];													// ����������
	char message[100];													// ���������
	char* str = new char[100];											// json ������

	get_nickname(recipient);											// ��������� ������ �����������
	scanf("%s", &message);												// ��������� ���������
	save_message(recipient, message);									// ���������� ���������

	str = addStr(
		(char*)"{\n\"request\": {\n\"command\": \" ",
		name, (char*)"\",\n\"phone\": \""
	);																	// �������� ���������� ����� ������: {"request": { "command": " +79270969849","phone" : "

	/*�������!!!*/
	for (int i = 41 + strlen(name); i < 100; i++) {						//��� ��������� ������ expectationCommand() ������ ������-�� ���������� � �������, �������������� ������
		str[i] = 0;
	}

	str = addStr(
		addStr(str, recipient, (char*)"\"\n},\n\"version\": \""),		//�������� ����� ������ ���������� ������: {"request": {"command": " +79270969849","phone" : "+79270969879"},"version" : "hello!"}
		message, (char*)"\"\n}");
	return str;
}

char* get_message_JSON(char* name) {
	char* str = new char[100];

	str = addStr(
		(char*)"{\n\"request\": {\n\"command\": \"getMessage\",\n\"phone\": \"",
		name,
		(char*)"\"\n},\n\"version\": \"\"\n}");
	/*�������!!!*/
	for (int i = 70 + strlen(name); i < 100; i++) {
		str[i] = 0;
	}
	return str;
}