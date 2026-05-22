#ifndef DATABASE_H
#define DATABASE_H

#include <cstring>
#include <stdexcept>

void connectDatabase() {
    // Implementation of connecting to the database
}

void loadCustomers() {
    // Implementation of loading customers
}

void safeFileParser(char* buffer, const char* data, size_t length) {
    if (length > sizeof(buffer)) {
        throw std::runtime_error("Buffer overflow detected");
    }
    std::memcpy(buffer, data, length);
}

#endif