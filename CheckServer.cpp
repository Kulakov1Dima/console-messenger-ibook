#include <curl/curl.h>
#include "Configuration.h"
#include "File_manager.h"

void getResponseData(char* data, size_t size, size_t n) {
	/*������� ������ ������ ��� �� ����� � ������� ����� CURLOPT_WRITEFUNCTION, data - ��������� �� ����������� ������, size - ������ ������������ ����� ������, n - ����������� ������ ������*/
	char* response;
	response = (char*)(data), (size * n);
	response[strlen(response) - 5] = 0;									// �������� ������� ������ ����������� � ������ ������� (��� ������� ���������� ������ � ����)
	if (response[1] == '+') {
		save_message(response + 1, response);							//���������� ���������� ���������
	}
	use_UTF_8;
	printf("%s", response);												// ����� ������ �������
}

CURL* checkServer() {
	/*��� ������� �������������� ������ curl � ��������� ����������� �������*/
	use_Unicode;
	CURL* curl = curl_easy_init();										// �������� easy(�������) curl-������, ���������� � ����������, � ������ ������� NULL.
	if (curl) {															// �� ����� �������� �� NULL
		curl_easy_setopt(curl, CURLOPT_URL, url);						// ����� url ������� � ������� � ����� ��������
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseData);	// �������� ����� ������� getResponseData ��� ������ ����������� ������ �� �������
		if (curl_easy_perform(curl)) {									// ���� curl_easy_perform(curl) ���������� 0, �� ���������� ������ ������
			printf("��������� ����������� � ���������!\n");
		}
		// ���� ������ ������� ���: https://curl.se/libcurl/c/libcurl-errors.html
	}
	else {
		printf("������! ����������: NULL\n");
	}
	return curl;
}