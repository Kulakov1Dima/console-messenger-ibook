/*Консольный мессенджер ibook 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include "СheckServer.h"
#include "Configuration.h"
#include "Messanger.h"
#include "File_manager.h"

void expectationCommand(CURL* curl, char* my_name) {
    char command[20];
    use_Unicode;
    printf(manual);
    printf(manualexCommand);
    printf(exitCommand);
    printf(manualMessangerCommand);
    printf(sendMessageCommand);
    printf(manualMessangerGetCommand);
    printf(getMessageCommand);
    printf(manualhistory);
    printf(history);
    printf(".\n");
    scanf("%s", command);

    if (!send_message_command(command)) {       // если введена команда sendMessageCommand (смотреть в Configuration.h) запустить функцию отправки сообщения
        sendMessage(curl, my_name);
    }
    if (!get_message_command(command)) {        // если введена команда getMessageCommand (смотреть в Configuration.h) запустить функцию проверки сообщений
        getMessage(curl, my_name);
    }

    if (!get_history(command)) {                // если введена команда history (смотреть в Configuration.h) запустить функцию проверки истории сообщений
        get_list_file();
        expectationCommand(curl, my_name);      // повторный запуск
    }
}

void main() {
    char my_name[13];
	CURL* curl = checkServer();			        // вызов функции проверки сервера
    use_Unicode;
    get_nickname(my_name);
    expectationCommand(curl, my_name);
	curl_easy_cleanup(curl);			        // завершение работы curl
}