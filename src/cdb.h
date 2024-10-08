#ifndef CDB_H
#define CDB_H

#include <string>
#include <unordered_map>
#include <fstream>
#include <mutex>

class CDB {
public:
    CDB(const std::string& filename);
    ~CDB();

    bool create(const std::string& key, const std::string& value);
    std::string read(const std::string& key);
    bool update(const std::string& key, const std::string& value);
    bool deleteRecord(const std::string& key);

private:
    std::unordered_map<std::string, std::string> data;
    std::string filename;
    std::mutex mtx;

    void loadData();
    void saveData();
};

#endif
