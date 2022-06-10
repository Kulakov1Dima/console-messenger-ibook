#define _CRT_SECURE_NO_WARNINGS
#include "Configuration.h"
#include <curl/curl.h>
#include "�heckServer.h"
#include "ibook.h"
#include "FormatJSON_String.h"
#include "File_manager.h"


void get_nickname(char* name) {											// ������� ��� ����� ��������
	printf("������� ���: ");
	scanf("%s", name);
}

bool send_message_command(char* command) {								// �������� ����� ������
	char ifCommand[] = sendMessageCommand;
	return strcmp(ifCommand, command);
}

bool get_message_command(char* command) {								// �������� ����� ������
	char ifCommand[] = getMessageCommand;
	return strcmp(ifCommand, command);
}

bool get_history(char* command) {										// �������� ����� ������
	char ifCommand[] = history;
	return strcmp(ifCommand, command);
}

void sendMessage(CURL* curl, char* name) {								// �������� JSON ������� (�� send_message_JSON()) �� ������
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, send_message_JSON(name));
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);
	CURLcode res = curl_easy_perform(curl);
	expectationCommand(curl, name);										// ����� ������� �� ibook.cpp ��� ������ ������� �����������
}

void getMessage(CURL* curl, char* name) {								// �������� JSON ������� (�� get_message_JSON()) �� ������
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, get_message_JSON(name));
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);
	CURLcode res = curl_easy_perform(curl);								// ����� ������� �� ibook.cpp ��� ������ ������� �����������
	expectationCommand(curl, name);
}