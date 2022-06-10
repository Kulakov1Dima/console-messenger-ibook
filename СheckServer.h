#pragma once
#include <curl/curl.h>

CURL* checkServer();
void getResponseData(char* data, size_t size, size_t n);