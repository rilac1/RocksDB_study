#include <bits/stdc++.h>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

using namespace ROCKSDB_NAMESPACE;
using namespace std;

const char* filename = "../../myRocks/Sample.mp4";

int main() {
    DB* db;

    Options options;
    options.create_if_missing = true;
    Status status = DB::Open(options, "../../myRocks/data", &db);
    assert(status.ok());

    options.error_if_exists = true;

    // Status
    Status s;
    if (!s.ok()) cerr << s.ToString() << endl;

   const char* filename = "./media/temp0.mp4";

    ifstream fin;
    fin.open(filename, ios::in | ios::binary);

    if (!fin) {
        cout << "FILE OPEN EXCEPTION" << endl;
        return 0;
    }

    int count = 0;
    char s[1024];
    while (!fin.eof()) {
        fin.read(s, 1024);      // 최대  1024 바이트 읽어 배열 s에 저장. 
        int n = fin.gcount();   // 실제 읽은 바이트 수 반환
        cout.write(s, n);
        count += n;
    }
    cout << endl << "읽은 바이트 수: " << count << endl;
    fin.close();

    return 0;
}
