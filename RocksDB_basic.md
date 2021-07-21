# [RocksDB 기본](https://meeeejin.gitbooks.io/rocksdb-wiki-kr/content/overview.html)

## 1. 서론
RocksDB는 Facebook에서 시작된 오픈소스 데이터베이스 개발 프로젝트로, 서버 워크로드와 같은 대용량 데이터 처리에 적합하고 빠른 저장장치, 특히 플래시 저장장치에서 높은 성능을 내도록 최적화되어있다. RocksDB는 C++ 라이브러리 형태로 제공되고 key-value 저장 방식을 취한다. 그리고 원자 읽기/쓰기(atomic read/write)를 지원한다.

RocksDB는 메모리, 플래시, 하드디스크, HDFS 등 다양한 환경에서 실행 가능하고, 그에 따라 환경 설정을 유연하게 조정할 수 있다. 그리고 다양한 압축 알고리즘과 제작 지원, 디버깅을 위한 툴들도 제공한다.

RocksDB는 오픈 소스 프로젝트인 LevelDB를 기반으로 하고, Apache HBase에서도 아이디어를 채용했다. 최초 코드는 LevelDB 1.5 버전에서 fork 되었다. 또한 RocksDB 전에 Facebook에서 개발된 코드와 아이디어를 토대로 개발되었다.

## 2. 가정과 목표

### 성능(Performance):
RocksDB의 주요한 디자인 포인트는 빠른 저장장치와 서버 워크로드에 적합해야 한다는 것이다. 즉, flash나 RAM이 제공하는 높은 읽기/쓰기 성능을 완전히 활용할 수 있어야 한다. 그리고 효율적인 포인트 검색(point lookup)은 물론 범위 스캔(range scan)도 제공해야 한다. 또한 랜덤한 읽기가 많은 워크로드, 업데이트가 많은 워크로드, 이 둘을 합친 워크로드를 지원하기 위해 설정 가능(configurable)해야 한다. 마지막으로, Read/Write/Space Amplification을 쉽게 튜닝할 수 있는 아키텍처를 제공해야 한다.

### w


operation: ```Get```, ```Put```, ```Delete```, ```Scan```  
구조: ```memtable```, ```sstfile```, ```logfile```  
> memtable(메모리) -> logfile(선택적) -> sstfile(디스크 파일시스템)  

### API
- ```get```
  - DB에서 하나의 Key-value를 가져올 수 있도록 함.  
- ```MultiGet```
  -  : 여러 개의 key를 검색할 수 있음.  
  - ```MultiGet``` 을 통해 반환된 모든 key-value는 서로 consisitent하다.)
---
- ```Iterator```
  - DB에서 RangeScan을 할 수 있게 함.  
  - ```Iterator```가 특정 key를 찾으면, 그 시점부터 한 번에 key 하나씩 스캔을 시작함.
  - key를 역순으로 탐색하는 데에도 사용될 수 있음
  - Iterator가 만들어지면, DB의 *consistent-point-in-time* 이 만들어짐.
  - 특정 시점 뷰에 해당하는 모든 파일에 대한 참조횟수(reference count)를 유지함.  
  (이 파일들은 Iterator가 release될 때까지 삭제되지 않음)
- ```Snapshot```
  - DB의 특정 시점뷰를 생성할 수 있게 함.
  - 파일 삭제를 막지 않는 대신 compaction 프로세스는 snapshot의 존재를 인식하고, 기존 snapshot에서 볼 수 있는 키들은 절대 삭제하지 않음을 보장함.
> 단시간 스캔은 ```Iterator```를 통해 수행하는 것이 가장 좋으며,  
> 장기간 스캔은 ```Snapshot``` 통해 수행하는 것이 좋다.  
