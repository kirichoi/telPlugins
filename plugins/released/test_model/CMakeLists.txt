cmake_minimum_required(VERSION 2.8)
set(target tel_test_model)

set(sources
TestModel.h
test_model_doc.h
TestModel.cpp
test_model_doc.cpp
)

add_library(${target} MODULE ${sources})

add_definitions(
-DEXPORT_TEL_PLUGIN
-DPOCO_STATIC
)

if(WIN32)
target_link_libraries (${target}
roadrunner
telplugins_core
)
else() #UNIX
    if(APPLE)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no_implicit_dylibs -undefined error")
    else()
        set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
    endif()

    set_property(TARGET ${target}
        PROPERTY  COMPILE_DEFINITIONS
        )

    target_link_libraries ( ${target}
        )
endif()

if(${MSVC})
#set (CMAKE_SHARED_LINKER_FLAGS     "${CMAKE_SHARED_LINKER_FLAGS} \"/DEF:${CMAKE_CURRENT_SOURCE_DIR}/add_noise.def\"")
endif()

install (TARGETS ${target}
DESTINATION plugins
COMPONENT plugins
)

install(FILES
DESTINATION plugins
)


