#include <bits/stdc++.h>
#include <assert.h>

#include "rocksdb/db.h"
using namespace std;

rocksdb::DB* db;
rocksdb::Options options;
int main() {
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./testdb", &db);
    assert(status.ok());

    string key = "1";
    string value = "hello 1";

    string result;

    rocksdb::Status s;
    if (s.ok()) s = db->Put(rocksdb::WriteOptions(), key, value);
    if (s.ok()) s = db->Get(rocksdb::ReadOptions(), key, &result);

    cout << result;
    delete db;
}
