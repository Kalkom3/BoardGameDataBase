cmake_minimum_required(VERSION 3.14)


if (WIN32)
    project(BoadrGameDataBase LANGUAGES CXX)
elseif(UNIX)
    project(BoadrGameDataBase)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)



#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Sql REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS Sql REQUIRED)



#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${MYSQL_INCLUDE_DIR})


file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)


#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable(BoadrGameDataBase WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(BoadrGameDataBase ${SOURCES})
endif()

# Add the target includes for BoadrGameDataBase
target_include_directories(BoadrGameDataBase PRIVATE ${FORMS_DIR})
target_include_directories(BoadrGameDataBase PRIVATE ${INCLUDE_DIR})
target_include_directories(BoadrGameDataBase PRIVATE ${SOURCE_DIR})


#===================== LINKING LIBRARIES =======================#
target_link_libraries(BoadrGameDataBase Qt6::Widgets)
target_link_libraries(BoadrGameDataBase Qt6::Sql)

