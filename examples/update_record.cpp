#include <cdb.h>
#include <iostream>

int main() {
    CDB db("data.cdb");
    db.update("key1", "new_value");
    return 0;
}
