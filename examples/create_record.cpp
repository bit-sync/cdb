#include <cdb.h>
#include <iostream>

int main() {
    CDB db("data.cdb");

    db.create("key1", "value1");
    return 0;
}
