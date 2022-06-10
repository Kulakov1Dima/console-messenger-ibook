#define _CRT_SECURE_NO_WARNINGS
#include "Messanger.h"
#include <string.h>
#include <stdio.h>
#include "File_manager.h"

extern "C" char* addStr(char* a, char* b, char* c);						// функци€ сложени€ 3-х строк из .asm файла

char* send_message_JSON(char* name) {									// функци€ формирует json строку, из которой сервер сохранит сообщение (поле version)

	char recipient[13];													// получатель
	char message[100];													// сообщение
	char* str = new char[100];											// json строка

	get_nickname(recipient);											// получение номера отправител€
	scanf("%s", &message);												// получение сообщени€
	save_message(recipient, message);									// сохранение сообщени€

	str = addStr(
		(char*)"{\n\"request\": {\n\"command\": \" ",
		name, (char*)"\",\n\"phone\": \""
	);																	// сложение полученных строк пример: {"request": { "command": " +79270969849","phone" : "

	/* остыль!!!*/
	for (int i = 41 + strlen(name); i < 100; i++) {						//при повторном вызове expectationCommand() строка почему-то получаетс€ с мусором, форматирование строки
		str[i] = 0;
	}

	str = addStr(
		addStr(str, recipient, (char*)"\"\n},\n\"version\": \""),		//сложение строк пример полученной строки: {"request": {"command": " +79270969849","phone" : "+79270969879"},"version" : "hello!"}
		message, (char*)"\"\n}");
	return str;
}

char* get_message_JSON(char* name) {
	char* str = new char[100];

	str = addStr(
		(char*)"{\n\"request\": {\n\"command\": \"getMessage\",\n\"phone\": \"",
		name,
		(char*)"\"\n},\n\"version\": \"\"\n}");
	/* остыль!!!*/
	for (int i = 70 + strlen(name); i < 100; i++) {
		str[i] = 0;
	}
	return str;
}