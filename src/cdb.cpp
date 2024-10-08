#include "cdb.h"
#include <iostream>

// Constructor: load data from file
CDB::CDB(const std::string& filename) : filename(filename) {
    loadData();
}

// Destructor: save data to file
CDB::~CDB() {
    saveData();
}

// Load data from the file into the in-memory map
void CDB::loadData() {
    std::ifstream file(filename);
    std::string key, value;
    while (file >> key >> value) {
        data[key] = value;
    }
}

// Save data from the in-memory map to the file
void CDB::saveData() {
    std::ofstream file(filename, std::ios::trunc);
    for (const auto& [key, value] : data) {
        file << key << " " << value << "\n";
    }
}

// Create a new record
bool CDB::create(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (data.find(key) != data.end()) {
        return false; // Key already exists
    }
    data[key] = value;
    saveData();
    return true;
}

// Read a record
std::string CDB::read(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    if (data.find(key) != data.end()) {
        return data[key];
    }
    return ""; // Key not found
}

// Update an existing record
bool CDB::update(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (data.find(key) == data.end()) {
        return false; // Key not found
    }
    data[key] = value;
    saveData();
    return true;
}

// Delete a record
bool CDB::deleteRecord(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    if (data.erase(key)) {
        saveData();
        return true;
    }
    return false; // Key not found
}
