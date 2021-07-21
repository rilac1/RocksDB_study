# RocksDB_study

### LFS
Log-Structed File System

### JBOB vs RAID
- JBOB  
: 각각의 디스크마다 독립적인 FS이 존재하는 형태. 그냥 용량만 늘어난 것이 전부
- RAID  
: 여러개의 physical disk를 하나의 logical disk와 같이 사용한다.  
    > Raid는 병렬적으로 여러 개의 physical disk를 사용하는데 logical disk를 통해서 마치 한 개의 디스크를 사용하는 듯한 착각을 준다. (Host system에게는 하나의 커다란 디스크를 사용하는 듯하게 보임)

### Key-Value Store
- Key is a unique identifier
- value can be anything
- Hash function is used to process the key

### Hash-Table
- Hash Collision 발생시 

---
## RocksDB Architecture
### Put

### Get:   
Memory -> Immutable Memory -> LV0 ~ 
Index & Filter Block 확인 -> offset 찾기

### MemTable
: Skip List

### Mem To SST
: Write 작업(fdatasync / fsync)

### Compaction
: Key-range가 겹치는 블럭을 메모리로 올리고 Merge Sorting 후 다시 Flush

## YCSB
> load
```
./bin/ycsb load rocksdb -s -P workloads/workloada -p rocksdb.dir=../ycsb-data -p recordcount=10000
```
> run
```
./bin/ycsb run rocksdb -s -P workloads/workloada -p rocksdb.dir=../ycsb-data -p operationcount=10000
```