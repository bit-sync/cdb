# Cdb

A simple C++ database.

## Create database

First, you need to create a database.

```cpp
CDB db("database.cdb");
```

## Creating records

Now we need data.
```cpp
db.create("key1", "value1");
```

## Reading records

Now to print the record, "key1"
```cpp
cout << db.read("key1");
```

## Updating records

What if you want to update the record? We got you!

```cpp
db.update("key1", "new_value");
```

## Delete records

Ops, wrote the wrong record.

```cpp
db.deleteRecord("key1");
```

**Now you know how to use Cdb!**