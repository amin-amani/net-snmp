# snmp library fork

## install
```
mkdir build && cd  build
./configure LIBS="-lcrypto -lssl"
make -j12
sudo make install
```
## RUN unit tests
```
autoreconf -fiv
mkdir build
cd build/
../configure
make
cd testing/
../../testing/RUNFULLTESTS -g unit-tests
```
