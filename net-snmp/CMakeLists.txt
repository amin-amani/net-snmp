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
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/closedir.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/readdir.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/opendir.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/gettimeofday.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/snmpksm.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/transports/snmpAAL5PVCDomain.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/transports/snmpSTDDomain.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/transports/snmpTLSBaseDomain.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/transports/snmpSSHDomain.c
    /media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_procfs_psinfo.c

    /media/amin/storage/workspace/net-snmp/net-snmp/agent/helpers/table_generic.c
    /media/amin/storage/workspace/net-snmp/net-snmp/snmplib/openssl/openssl_ncbc_enc.c
    /media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_solaris.c

/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/hr_swrun.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/helpers/table_generic.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_kstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_pcp.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_nlist.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_kerndata.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_pstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_sysinfo.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_dynix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_irix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_aix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_solaris.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/sensors/kstat_sensors.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/fsys/fsys_mntctl.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swinst_rpm.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_kvm_proc.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/sensors/lmsensors_v2.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_sysctl.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_kinfo.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_pstat.c
)
list(REMOVE_ITEM AGENT_SOURCES
    /media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_win.c
    /media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_procfs_psinfo.c
    /media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_nlist.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/hr_swrun.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/helpers/table_generic.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_kstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_pcp.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/fsys/fsys_getfsstats.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_perfstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_mach.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_nlist.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_kerndata.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_pstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_sysinfo.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_dynix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_irix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_aix.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/memory/memory_solaris.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/sensors/kstat_sensors.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/fsys/fsys_mntctl.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swinst_rpm.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_kvm_proc.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/sensors/lmsensors_v2.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/hardware/cpu/cpu_sysctl.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_procinfo.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_kinfo.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_pstat.c
/media/amin/storage/workspace/net-snmp/net-snmp/agent/mibgroup/host/data_access/swrun_cygwin.c
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
