
#pragma once
#include <curl/curl.h>
void get_nickname(char* name);
bool send_message_command(char* command);
bool get_message_command(char* command);
bool get_history(char* command);
void sendMessage(CURL* curl, char* name);
void getMessage(CURL* curl, char* name);
