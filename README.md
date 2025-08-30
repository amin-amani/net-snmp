# snmp library fork

## RUN unit tests
```
autoreconf -fiv
mkdir build
cd build/
../configure
make
../../testing/RUNFULLTESTS -g unit-tests
cd testing/
../../testing/RUNFULLTESTS -g unit-tests
```
