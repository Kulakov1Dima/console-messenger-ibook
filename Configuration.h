#pragma once
/*���� ��������� ���������
*/
#include <locale.h>
#define use_UTF_8 setlocale(LC_ALL, "ru_RU.UTF-8")
#define use_Unicode setlocale(LC_ALL, "ru")
#define url "http://checkers24.ru/ibook/"
#define manual "��� ���������� ����������� ��������� �������:\n"
#define manualexCommand "��� ������: "
#define manualMessangerCommand ", ��� �������� ���������: "
#define manualMessangerGetCommand ", ��� �������� ��������� ���������: "
#define sendMessageCommand "send"
#define getMessageCommand "get"
#define exitCommand "exit"
#define history "lookhistory"
#define gethistory "��� ������ ���������:\n"
#define manualhistory ", ��� ��������� ������� ���������: "