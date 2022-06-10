#define _CRT_SECURE_NO_WARNINGS
#include "Configuration.h"
#include <curl/curl.h>
#include "СheckServer.h"
#include "ibook.h"
#include "FormatJSON_String.h"
#include "File_manager.h"


void get_nickname(char* name) {											// функция для ввода телефона
	printf("Введите имя: ");
	scanf("%s", name);
}

bool send_message_command(char* command) {								// проверка ввода команд
	char ifCommand[] = sendMessageCommand;
	return strcmp(ifCommand, command);
}

bool get_message_command(char* command) {								// проверка ввода команд
	char ifCommand[] = getMessageCommand;
	return strcmp(ifCommand, command);
}

bool get_history(char* command) {										// проверка ввода команд
	char ifCommand[] = history;
	return strcmp(ifCommand, command);
}

void sendMessage(CURL* curl, char* name) {								// отправка JSON стрроки (из send_message_JSON()) на сервер
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, send_message_JSON(name));
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);
	CURLcode res = curl_easy_perform(curl);
	expectationCommand(curl, name);										// вызов функции из ibook.cpp для нового запуска мессенджера
}

void getMessage(CURL* curl, char* name) {								// отправка JSON стрроки (из get_message_JSON()) на сервер
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, get_message_JSON(name));
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);
	CURLcode res = curl_easy_perform(curl);								// вызов функции из ibook.cpp для нового запуска мессенджера
	expectationCommand(curl, name);
}