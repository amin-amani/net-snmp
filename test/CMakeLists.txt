cmake_minimum_required(VERSION 3.16)
project(RunAllTests VERSION 1.0 LANGUAGES C)

# Compiler flags from Makefile
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -DNETSNMP_ENABLE_IPV6 -fno-strict-aliasing -DNETSNMP_REMOVE_U64 -Ulinux -Dlinux=linux")
message("+++++++++++${CMAKE_CURRENT_SOURCE_DIR}+++++++++++")
add_definitions(-DHAVE_GETTIMEOFDAY=1)
add_definitions(-DHAVE_SYS_TYPES_H=1)
add_definitions(-DHAVE_STDDEF_H=1)

find_package(Threads REQUIRED)

# Top-level include dirs
include_directories(
    /media/amin/storage/workspace/net-snmp/net-snmp/build/include/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/
    /media/amin/storage/workspace/net-snmp/net-snmp/build/snmplib/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/
    /media/amin/storage/workspace/net-snmp/net-snmp/build/agent/mibgroup/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/agent/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/

    ${CMAKE_SOURCE_DIR}/lib/Unity/src/
    ${CMAKE_SOURCE_DIR}/lib/Unity/extras/fixture/src
    ${CMAKE_SOURCE_DIR}/lib/Unity/extras/memory/src/


    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/agent
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup
    /usr/include/libnl3   # from Makefile
)

# Collect all sources recursively

file(GLOB SRC_TEST
    ${CMAKE_SOURCE_DIR}/test/*.c

    )
file(GLOB_RECURSE SNMPLIB_SOURCES snmplib/*.c)
file(GLOB_RECURSE AGENT_SOURCES agent/*.c)

#file(GLOB_RECURSE APP_SOURCES apps/*.c)

list(REMOVE_ITEM SNMPLIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/broken_file.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/legacy_debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/closedir.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/readdir.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/opendir.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/gettimeofday.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/snmpksm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/transports/snmpAAL5PVCDomain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/transports/snmpSTDDomain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/transports/snmpTLSBaseDomain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/transports/snmpSSHDomain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_procfs_psinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers/table_generic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib/openssl/openssl_ncbc_enc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_solaris.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/hr_swrun.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers/table_generic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_kstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_pcp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_nlist.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_kerndata.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_pstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_sysinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_dynix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_irix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_aix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_solaris.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/sensors/kstat_sensors.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/fsys/fsys_mntctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swinst_rpm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_kvm_proc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/sensors/lmsensors_v2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_sysctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_kinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_pstat.c
)
list(REMOVE_ITEM AGENT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_win.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_procfs_psinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_nlist.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/hr_swrun.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers/table_generic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_kstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_pcp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/fsys/fsys_getfsstats.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_perfstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_mach.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_nlist.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_kerndata.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_pstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_sysinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_dynix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_irix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_aix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/memory/memory_solaris.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/sensors/kstat_sensors.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/fsys/fsys_mntctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swinst_rpm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_kvm_proc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/sensors/lmsensors_v2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/hardware/cpu/cpu_sysctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_procinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_kinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_pstat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup/host/data_access/swrun_cygwin.c
    )
# Link against the necessary libraries
add_executable(${PROJECT_NAME} ${SRC_TEST}  ${SRC_COMMON} ${SNMPLIB_SOURCES})
target_link_libraries(${PROJECT_NAME} -L${CMAKE_BINARY_DIR}/lib/Unity -lunity sqlite3 sinalog sinapkt sinalog
                        config   crypto ssl
                        sinatimer sinastdreg sinamsg sinaalert st6x00util m Threads::Threads)

#cmake_minimum_required(VERSION 3.5)

#project(RunAllTests LANGUAGES C)
#find_package(Threads REQUIRED)
#include_directories(${CMAKE_SOURCE_DIR}/src)
#file(GLOB SRC_COMMON ${CMAKE_SOURCE_DIR}/src/*.c)
#list(REMOVE_ITEM SRC_COMMON ${CMAKE_SOURCE_DIR}/src/main.c ${CMAKE_SOURCE_DIR}/src/main_test.c)


## Define UNIT_TEST_BUILD_PATH with proper escaping and trailing slash
#add_definitions(-DUNIT_TEST_BUILD_PATH="${CMAKE_BINARY_DIR}/")
#add_definitions(-DPROJECT_DIR="${CMAKE_SOURCE_DIR}/")
##add_definitions(-D_DEFAULT_SOURCE -D_BSD_SOURCE)
##add_definitions(-DNETSNMP_USE_KERBEROS_MIT)
#add_definitions(-DHAVE_GETTIMEOFDAY=1)
#add_definitions(-DHAVE_SYS_TYPES_H=1)
#add_definitions(-DHAVE_STDDEF_H=1)
#file(GLOB SRC_TEST
#    ${CMAKE_SOURCE_DIR}/test/*.c

#    )
#file(GLOB_RECURSE SRC_SNMP

#        ${CMAKE_SOURCE_DIR}/net-snmp/*.c
##    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/*.c
##    ${CMAKE_SOURCE_DIR}/net-snmp/agent/*.c
##    ${CMAKE_SOURCE_DIR}/net-snmp/agent/helpers/*.c
##    ${CMAKE_SOURCE_DIR}/net-snmp/build/agent/mibgroup/mib_module_shutdown.h
##    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/*.c


#    )
#list(REMOVE_ITEM SRC_SNMP
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/system.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/winpipe.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/winservice.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/opendir.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/closedir.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/readdir.c

#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/snmp_secmod.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/gettimeofday.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/snmplib/gettimeofday.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/agent/snmp_perl.c
#    ${CMAKE_SOURCE_DIR}/net-snmp/agent/helpers/table_generic.c


#)
#include_directories(
#    /media/amin/storage/workspace/net-snmp/net-snmp/build/include/
#    /media/amin/storage/workspace/net-snmp/net-snmp/include/
#    /media/amin/storage/workspace/net-snmp/net-snmp/build/snmplib/
#    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/
#    /media/amin/storage/workspace/net-snmp/net-snmp/build/agent/mibgroup/
#    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/agent/
#    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/

#    ${CMAKE_SOURCE_DIR}/lib/Unity/src/
#    ${CMAKE_SOURCE_DIR}/lib/Unity/extras/fixture/src
#    ${CMAKE_SOURCE_DIR}/lib/Unity/extras/memory/src/
#    ${CMAKE_SOURCE_DIR}/src

#    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib
##     ${CMAKE_CURRENT_SOURCE_DIR}/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/agent
#    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers
#    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup
#    /usr/include/libnl3   # from Makefile
#)
##include_directories(
##     /usr/local/include/
##     /usr/include/
##     /opt/sqlite3-custom/include/
##     /usr/include/linux/
##     ${CMAKE_SOURCE_DIR}/lib/Unity/src/
##     ${CMAKE_SOURCE_DIR}/lib/Unity/extras/fixture/src
##     ${CMAKE_SOURCE_DIR}/lib/Unity/extras/memory/src/
##     ${CMAKE_SOURCE_DIR}/src
##     ${CMAKE_SOURCE_DIR}/net-snmp/build/include/
##     ${CMAKE_SOURCE_DIR}/net-snmp/include/
##     ${CMAKE_SOURCE_DIR}/net-snmp/agent/mibgroup/
##     ${CMAKE_SOURCE_DIR}/net-snmp/build/snmplib/
##     ${CMAKE_SOURCE_DIR}/net-snmp/build/agent/mibgroup/
##     ${CMAKE_SOURCE_DIR}/net-snmp/agent/
##     ${CMAKE_SOURCE_DIR}/net-snmp/include/net-snmp/agent/

##    )
#link_directories(
#    /opt/sqlite3-custom/lib/
#    /usr/local/lib/
#    /usr/lib
#    )
#message(${CMAKE_SOURCE_DIR}/net-snmp/build/snmplib/transports/ "============================")
## Add the target for the tests
#add_executable(${PROJECT_NAME} ${SRC_TEST}  ${SRC_COMMON} ${SRC_SNMP})
#target_compile_definitions(${PROJECT_NAME} PRIVATE UNIT_TEST_BUILD_PATH="${UNIT_TEST_BUILD_PATH}")
## Set compiler flags for coverage
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic -fPIC -g -I${CMAKE_PREFIX_PATH}/include/ --coverage")

## Link against the necessary libraries
#target_link_libraries(${PROJECT_NAME} -L${CMAKE_BINARY_DIR}/lib/Unity -lunity sqlite3 sinalog sinapkt sinalog
#                        config   crypto ssl
#                        sinatimer sinastdreg sinamsg sinaalert st6x00util m Threads::Threads)
## Enable testing
#enable_testing()

## Add a test target
#add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

## Create coverage report
#add_custom_target(coverage
#  COMMAND lcov --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info
#  COMMAND lcov --remove coverage.info '/usr/*' --output-file coverage.info
#  COMMAND lcov --remove coverage.info '${CMAKE_BINARY_DIR}/test/*' --output-file coverage.info
#  COMMAND lcov --remove coverage.info '${CMAKE_BINARY_DIR}/lib/Unity/*' --output-file coverage.info  # Exclude Unity library if needed
#  COMMAND genhtml coverage.info --output-directory coverage-report
#  COMMAND cutycapt --url=file://${CMAKE_BINARY_DIR}/coverage-report/src/index.html --out=${CMAKE_BINARY_DIR}/coverage-screenshot.png
#  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/coverage-screenshot.png ${CMAKE_SOURCE_DIR}/coverage-screenshot.png
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#)

## Add a custom target to run tests and generate coverage
#add_custom_target(run_tests_with_coverage
#  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
#  COMMAND make coverage
#  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/coverage-report ${CMAKE_SOURCE_DIR}/coverage-report
#  DEPENDS ${PROJECT_NAME}
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#)
