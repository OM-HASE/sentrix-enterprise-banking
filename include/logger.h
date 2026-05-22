#ifndef LOGGER_H
#define LOGGER_H

#include <string>

void logMessage(
    std::string message
);

void startConcurrentLogging();

#endif