#include <curl/curl.h>
#include "Configuration.h"
#include "File_manager.h"

void getResponseData(char* data, size_t size, size_t n) {
	/*Функция записи данных при их приёме с помощью опции CURLOPT_WRITEFUNCTION, data - указатель на принимаемые данные, size - размер принимаемого блока данных, n - колличество блоков данных*/
	char* response;
	response = (char*)(data), (size * n);
	response[strlen(response) - 5] = 0;									// удаление лишнего сивола приходящего в ответе сервера (для будущей корректной записи в файл)
	if (response[1] == '+') {
		save_message(response + 1, response);							//сохранение полученных сообщений
	}
	use_UTF_8;
	printf("%s", response);												// вывод ответа сервера
}

CURL* checkServer() {
	/*Эта функция инициализирует объект curl и проверяет доступность сервера*/
	use_Unicode;
	CURL* curl = curl_easy_init();										// начинает easy(простую) curl-сессию, возвращает её дескриптор, в случае неудачи NULL.
	if (curl) {															// та самая проверка на NULL
		curl_easy_setopt(curl, CURLOPT_URL, url);						// задаём url сервера с которым и будем работать
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);	// обратный вызов функции getResponseData для записи полученного ответа от сервера
		if (curl_easy_perform(curl)) {									// если curl_easy_perform(curl) возфращает 0, то соединение прошло удачно
			printf("Проверьте подключение к интернету!\n");
		}
		// коды ошибок смотрел тут: https://curl.se/libcurl/c/libcurl-errors.html
	}
	else {
		printf("Ошибка! дескриптор: NULL\n");
	}
	return curl;
}