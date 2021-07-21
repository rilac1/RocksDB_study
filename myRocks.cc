#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <string>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

using namespace ROCKSDB_NAMESPACE;
using namespace std;

int main() {
// Opening A Database
    DB* db;
    Options options;
    options.create_if_missing = true;
    Status status =
    DB::Open(options, "../../myRocks/data", &db);
    assert(status.ok());

    options.error_if_exists = true;

// Status
    Status s;
    if (!s.ok()) cerr << s.ToString() << endl;

// File open
    ifstream readFile;
    readFile.open("./factory.csv");

    if (readFile.is_open()) {
        while(!readFile.eof()) {
            string str;
            getline(readFile, str);
            cout << str << endl;
        }
        readFile.close();
    }

// Reads And Writes
    string key1 = "123";
    string key2 = "abc";

    string put_value1 = "456"; 
    string put_value2 = "def"; 

    string get_value1; 
    string get_value2; 

    // write
    if (s.ok()) s = db->Put(WriteOptions(), key1, put_value1);
    if (s.ok()) s = db->Put(WriteOptions(), key2, put_value2);

    // read
    s = db->Get(ReadOptions(), key1, &get_value1);
    s = db->Get(ReadOptions(), key2, &get_value2);

    // delete
    if (s.ok()) s = db->Delete(WriteOptions(), key1);

// Closing A Database
    /* open the db as described above */
    /* do something with db */
    delete db;
}

// g++ -fno-rtti simple_example.cc -osimple_example ../librocksdb_debug.a -I../include -O2 -std=c++11 -lpthread -lrt -ldl -lsnappy -lgflags -lz -lbz2 -llz4 -lzstd -std=c++11  -faligned-new -DHAVE_ALIGNED_NEW -DROCKSDB_PLATFORM_POSIX -DROCKSDB_LIB_IO_POSIX  -DOS_LINUX -fno-builtin-memcmp -DROCKSDB_FALLOCATE_PRESENT -DSNAPPY -DGFLAGS=1 -DZLIB -DBZIP2 -DLZ4 -DZSTD -DROCKSDB_MALLOC_USABLE_SIZE -DROCKSDB_PTHREAD_ADAPTIVE_MUTEX -DROCKSDB_BACKTRACE -DROCKSDB_RANGESYNC_PRESENT -DROCKSDB_SCHED_GETCPU_PRESENT -DROCKSDB_AUXV_GETAUXVAL_PRESENT -march=native   -DHAVE_SSE42  -DHAVE_PCLMUL  -DHAVE_AVX2  -DHAVE_BMI  -DHAVE_LZCNT -DHAVE_UINT128_EXTENSION -DROCKSDB_SUPPORT_THREAD_
