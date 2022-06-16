/*Консольный мессенджер ibook 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include "СheckServer.h"
#include "Configuration.h"
#include "Messanger.h"
#include "File_manager.h"

void screensaver() {
	printf("\n            bbbbbbbb\n");
	printf("  IIIIIIIIIIb::::::b                                             kkkkkkkk\n");
	printf("  I::::::::Ib::::::b                                             k::::::k\n");
	printf("  I::::::::Ib::::::b                                             k::::::k\n");
	printf("  II::::::II b:::::b                                             k::::::k\n");
	printf("    I::::I   b:::::bbbbbbbbb       ooooooooooo     ooooooooooo    k:::::k    kkkkkkk\n");
	printf("    I::::I   b::::::::::::::bb   oo:::::::::::oo oo:::::::::::oo  k:::::k   k:::::k\n");
	printf("    I::::I   b::::::::::::::::b o:::::::::::::::o:::::::::::::::o k:::::k  k:::::k\n");
	printf("    I::::I   b:::::bbbbb:::::::bo:::::ooooo:::::o:::::ooooo:::::o k:::::k k:::::k\n");
	printf("    I::::I   b:::::b    b::::::bo::::o     o::::o::::o     o::::ok::::::k:::::k\n");
	printf("    I::::I   b:::::b     b:::::bo::::o     o::::o::::o     o::::ok:::::::::::k\n");
	printf("    I::::I   b:::::b     b:::::bo::::o     o::::o::::o     o::::ok:::::::::::k\n");
	printf("    I::::I   b:::::b     b:::::bo::::o     o::::o::::o     o::::ok::::::k:::::k\n");
	printf("  II::::::II b:::::bbbbbb::::::bo:::::ooooo:::::o:::::ooooo:::::ok::::::k k:::::k\n");
	printf("  I::::::::I b::::::::::::::::b o:::::::::::::::o:::::::::::::::ok::::::k  k:::::k\n");
	printf("  I::::::::I b:::::::::::::::b   oo:::::::::::oo oo:::::::::::oo k::::::k   k:::::k\n");
	printf("  IIIIIIIIII bbbbbbbbbbbbbbbb      ooooooooooo     ooooooooooo   kkkkkkkk    kkkkkkk\n\n");

	for (int i = 0; i <= 110; i++) {
		printf(".");
	};
	use_Unicode;
	printf("\n\n\n Кулаков Дмитрий Алексеевич 2022.\n\n\n");

}

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
	screensaver();
	char my_name[13];
	CURL* curl = checkServer();			        // вызов функции проверки сервера
	use_Unicode;
	get_nickname(my_name);
	expectationCommand(curl, my_name);
	curl_easy_cleanup(curl);			        // завершение работы curl
}