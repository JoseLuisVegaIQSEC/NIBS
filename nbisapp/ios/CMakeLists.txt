cmake_minimum_required(VERSION 3.13)
project(NBISiOS)

set(CMAKE_C_STANDARD 99)

# Incluir encabezados
include_directories(
    ../NBIS/commonnbis/include
    ../NBIS/imgtools/include
    ../NBIS/imgtools/src/lib/wsq
)

# Buscar archivos fuente y encabezados (solo .c y .h)
file(GLOB UTIL_SRC "../NBIS/commonnbis/src/lib/util")
file(GLOB COMMON_SRC "../NBIS/commonnbis/src/lib/util/*.c")
file(GLOB COMMON_HEADERS "../NBIS/commonnbis/src/lib/util/*.h")
file(GLOB IMGTOOLS_SRC "../NBIS/imgtools/src/*.c")
file(GLOB IMGTOOLS_HEADERS "../NBIS/imgtools/include/*.h")
file(GLOB WSQ_SRC "../NBIS/imgtools/src/lib/wsq/*.c")
file(GLOB WSQ_HEADERS "../NBIS/imgtools/src/lib/wsq/*.h")

# Mensajes de depuración
message(STATUS "UTIL_SRC: ${UTIL_SRC}")
message(STATUS "COMMON_SRC: ${COMMON_SRC}")
message(STATUS "COMMON_HEADERS: ${COMMON_HEADERS}")
message(STATUS "JPEG_SRC: ${JPEG_SRC}")
message(STATUS "JPEG_HEADERS: ${JPEG_HEADERS}")
message(STATUS "IMGTOOLS_SRC: ${IMGTOOLS_SRC}")
message(STATUS "IMGTOOLS_HEADERS: ${IMGTOOLS_HEADERS}")
message(STATUS "WSQ_SRC: ${WSQ_SRC}")
message(STATUS "WSQ_HEADERS: ${WSQ_HEADERS}")

# Validar que haya archivos fuente
list(APPEND ALL_SOURCES
    ${COMMON_SRC}
    ${JPEG_SRC}
    ${IMGTOOLS_SRC}
    ${WSQ_SRC}
    ${COMMON_HEADERS}
    ${JPEG_HEADERS}
    ${IMGTOOLS_HEADERS}
    ${WSQ_HEADERS}
)

if(ALL_SOURCES)
    add_library(nbis STATIC ${ALL_SOURCES})
else()
    message(FATAL_ERROR "No source files found for NBIS. Verifica las rutas.")
endif()
