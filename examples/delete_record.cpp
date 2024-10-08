#include <cdb.h>
#include <iostream>

int main() {
    CDB db("data.cdb");
    db.deleteRecord("key1");
    return 0;
}
