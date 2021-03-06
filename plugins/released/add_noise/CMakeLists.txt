cmake_minimum_required(VERSION 2.8)
set(target tel_add_noise)

include_directories(
)

set(sources
add_noise.cpp
add_noise_worker.cpp
add_noise_doc.cpp
noise.cpp
add_noise.h
add_noise_worker.h
add_noise_doc.h
noise.h
)

add_library(${target} MODULE ${sources})

add_definitions(
-DEXPORT_TEL_PLUGIN
-DPOCO_STATIC
)

if(WIN32)
target_link_libraries (${target}
roadrunner
telplugins_common
telplugins_core
telplugins_math
)
else() #UNIX
    # OSX flags:
    #"${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no_implicit_dylibs -undefined error")
    # OSX seems to link fine without this flag
    if(APPLE)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no_implicit_dylibs -undefined error")
    else()
        set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
    endif()

    set_property(TARGET ${target}
        PROPERTY  COMPILE_DEFINITIONS
        LIBSBML_STATIC
        LIBLAX_STATIC
        STATIC_PUGI
        STATIC_LIBSTRUCT
        )

    target_link_libraries ( ${target}
        roadrunner-static
        rr-libstruct-static
        nleq-static
        sbml-static
        lapack
        blas
        f2c
        pthread
        #roadrunner_c_api
        telplugins_common-static
        telplugins_core-static
        telplugins_math-static
        )
endif()

if(${MSVC})
#set (CMAKE_SHARED_LINKER_FLAGS     "${CMAKE_SHARED_LINKER_FLAGS} \"/DEF:${CMAKE_CURRENT_SOURCE_DIR}/add_noise.def\"")
endif()

install (TARGETS ${target}
DESTINATION plugins
COMPONENT plugins
)

#install(FILES
#docs/Examples/rrNoisePluginDemo.py
#DESTINATION plugins/Examples
#)


