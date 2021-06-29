# RocksDB_study

### JBOB vs RAID
- JBOB  
: 각각의 디스크마다 독립적인 FS이 존재하는 형태. 그냥 용량만 늘어난 것이 전부
- RAID  
: 여러개의 physical disk를 하나의 logical disk와 같이 사용한다.  
user application과 FS 상에서는 마치 한 개의 disk만 다루는 듯하게 보임.