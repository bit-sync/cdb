#include <cdb.h>
#include <iostream>

int main() {
    CDB db("data.cdb");
    std::cout << "key1: " << db.read("key1") << std::endl;
    return 0;
}
