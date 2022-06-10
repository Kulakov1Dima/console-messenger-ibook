#pragma once
/*Файл настройки программы
*/
#include <locale.h>
#define use_UTF_8 setlocale(LC_ALL, "ru_RU.UTF-8")
#define use_Unicode setlocale(LC_ALL, "ru")
#define url "http://checkers24.ru/ibook/"
#define manual "для управления используйте следующие команды:\n"
#define manualexCommand "Для выхода: "
#define manualMessangerCommand ", для отправки сообщения: "
#define manualMessangerGetCommand ", для проверки пришедших сообщений: "
#define sendMessageCommand "send"
#define getMessageCommand "get"
#define exitCommand "exit"
#define history "lookhistory"
#define gethistory "Моя исторя сообщений:\n"
#define manualhistory ", для получения истории сообщений: "