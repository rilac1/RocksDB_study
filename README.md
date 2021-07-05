# RocksDB_study

### LFS
Log-Structed File System

### JBOB vs RAID
- JBOB  
: 각각의 디스크마다 독립적인 FS이 존재하는 형태. 그냥 용량만 늘어난 것이 전부
- RAID  
: 여러개의 physical disk를 하나의 logical disk와 같이 사용한다.  
    > Raid는 병렬적으로 여러 개의 physical disk를 사용하는데 logical disk를 통해서 마치 한 개의 디스크를 사용하는 듯한 착각을 준다. (Host system에게는 하나의 커다란 디스크를 사용하는 듯하게 보임)

