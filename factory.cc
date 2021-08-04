#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <assert.h>
#include "rocksdb/db.h"
using namespace std;

rocksdb::DB* db;
rocksdb::Options options;

int main() {
//Opening A Database
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./db", &db);
    assert(status.ok());

// Status
    rocksdb::Status s;
    if (!s.ok()) cerr << s.ToString() << endl;

// File open
    ifstream readFile;
    readFile.open("./data/plating_rowdata.csv");
    
    if (readFile.is_open()) {
        while(!readFile.eof()) {
            string str;
            getline(readFile, str);
            cout << str << endl;
        }
        readFile.close();
    }

// Write
    // if (s.ok()) s = db->Put(rocksdb::WriteOptions(), key, value);
// Read
    // if (s.ok()) s = db->Get(rocksdb::ReadOptions(), key, &result);

    delete db;
}
