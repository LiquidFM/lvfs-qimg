project (lvfs-qimg)

# Project header
project_cxx_library_header_default ()

# 3rdparty
list (APPEND ${PROJECT_NAME}_LIBS brolly)
list (APPEND ${PROJECT_NAME}_LIBS efc)
list (APPEND ${PROJECT_NAME}_LIBS lvfs)
list (APPEND ${PROJECT_NAME}_LIBS unrar)

find_package (LibArchive REQUIRED)
include_directories (${LIBARCHIVE_INCLUDE_DIR})
list (APPEND ${PROJECT_NAME}_LIBS ${LIBARCHIVE_LIBRARY})

# Sources
add_subdirectory (src)

# Target - lvfs-qimg
add_library (lvfs-qimg SHARED ${${PROJECT_NAME}_SOURCES})
target_link_libraries (lvfs-qimg ${${PROJECT_NAME}_LIBS})

# Version
build_version_file (lvfs-qimg 0.0.1)

# Documentation
add_documentation ("LVFS-QImg" 0.0.1 "LVFS Plugin for viewing image files")

# Install rules
install_target (lvfs-qimg)
