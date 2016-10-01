project (lvfs-qimg)

# Project header
project_header_default ("POSITION_INDEPENDENT_CODE:YES")

# 3rdparty
find_package (Lvfs-Core REQUIRED)
include_directories (${LVFS_CORE_INCLUDE})

list (APPEND ${PROJECT_NAME}_LIBS ${EFC_LIB})
list (APPEND ${PROJECT_NAME}_LIBS ${LVFS_LIB})
list (APPEND ${PROJECT_NAME}_LIBS ${QT_LIBRARIES})
list (APPEND ${PROJECT_NAME}_LIBS ${LVFS_CORE_LIB})

# Sources
add_subdirectory (src)
QT4_WRAP_CPP (${PROJECT_NAME}_MOC_SOURCES ${${PROJECT_NAME}_HEADERS} OPTIONS "-nw")
list (APPEND ${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_MOC_SOURCES})

# Target - lvfs-qimg
add_library (lvfs-qimg SHARED ${${PROJECT_NAME}_SOURCES})
target_link_libraries (lvfs-qimg ${${PROJECT_NAME}_LIBS})

# Documentation
add_documentation ("LVFS-QImg" 0.0.1 "LVFS Plugin to view image files")

# Install rules
install_target (lvfs-qimg)
