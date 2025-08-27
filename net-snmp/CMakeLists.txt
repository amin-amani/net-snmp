cmake_minimum_required(VERSION 3.16)
project(NetSNMP VERSION 5.8 LANGUAGES C)

# Compiler flags from Makefile
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -DNETSNMP_ENABLE_IPV6 -fno-strict-aliasing -DNETSNMP_REMOVE_U64 -Ulinux -Dlinux=linux")
message("+++++++++++${CMAKE_CURRENT_SOURCE_DIR}+++++++++++")
add_definitions(-DHAVE_GETTIMEOFDAY=1)
add_definitions(-DHAVE_SYS_TYPES_H=1)
add_definitions(-DHAVE_STDDEF_H=1)
# Top-level include dirs
include_directories(
    /media/amin/storage/workspace/net-snmp/net-snmp/build/include/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/
    /media/amin/storage/workspace/net-snmp/net-snmp/build/snmplib/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/
    /media/amin/storage/workspace/net-snmp/net-snmp/build/agent/mibgroup/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/agent/
    /media/amin/storage/workspace/net-snmp/net-snmp/include/net-snmp/


    ${CMAKE_CURRENT_SOURCE_DIR}/snmplib
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/agent
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/agent/mibgroup
    /usr/include/libnl3   # from Makefile
)

# Collect all sources recursively
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
# Create snmplib shared library
add_library(snmplib SHARED ${SNMPLIB_SOURCES})

## Create agent library
#add_library(agentlib SHARED ${AGENT_SOURCES})
#target_link_libraries(agentlib PRIVATE snmplib)

## Example apps (add others similarly)
#add_executable(snmpget apps/snmpget.c)
#target_link_libraries(snmpget PRIVATE agentlib snmplib)

#add_executable(snmpwalk apps/snmpwalk.c)
#target_link_libraries(snmpwalk PRIVATE agentlib snmplib)

#add_executable(snmptrapd apps/snmptrapd.c)
#target_link_libraries(snmptrapd PRIVATE agentlib snmplib)

## Install rules (simplified from Makefile)
#install(TARGETS snmplib agentlib snmpget snmpwalk snmptrapd
#    RUNTIME DESTINATION bin
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib
#)

install(DIRECTORY include/ DESTINATION include/net-snmp FILES_MATCHING PATTERN "*.h")
