#include "FilePro.h"

void FilePro::setCreated(time_t time) {
	struct tm tm;
	localtime_s(&tm, &time);
	char tChars[50] = { 0 };
	std::strftime(tChars, sizeof(tChars) , "%Y-%m-%d %H:%M:%S", &tm);
	created = std::string(tChars);
	return;
}

void FilePro::setModified(time_t time) {
	struct tm tm;
	localtime_s(&tm, &time);
	char tChars[50] = { 0 };
	std::strftime(tChars, sizeof(tChars), "%Y-%m-%d %H:%M:%S", &tm);
	modified = std::string(tChars);
	return;
}

void FilePro::setAttached(time_t time) {
	struct tm tm;
	localtime_s(&tm, &time);
	char tChars[50] = { 0 };
	std::strftime(tChars, sizeof(tChars), "%Y-%m-%d %H:%M:%S", &tm);
	attached = std::string(tChars);
	return;
}