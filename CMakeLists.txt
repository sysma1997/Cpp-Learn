cmake_minimum_required(VERSION 3.8)

# Version c++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(opts)

# Creamos la variable y le asignamos el valor "src/main.cpp" que es la ubicación de nuestro archivo.
# Por defecto las variables son listas o arrays
# Si tenemos dos archivos sería SET(<NOMBRE_VARIABLE> "src/main.cpp" "src/segundo.cpp")
# Se permite multilínea
set(opts_src "src/main.cpp")

# ----- LIBRERIAS EXTERNAS ----- #

# Una de las características más interesantes de CMake es que es capaz de encontrar librerías externas 
# que necesite nuestro programa. Esta característica se implementa con plugins de CMake

# Windows graphics
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# JSON LIBRARY
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

# SQLITE3
find_package(SQLite3 REQUIRED)

# En grandes librerías, podemos pedir solo ciertos componentes
# con el comando COMPONENTS
# find_package(wxWidgets COMPONENTS core gl html base net)
# Si todo va bien, tenemos las variables wxWidgets_FOUND, wxWidgets_LIBRARIES y wxWidgets_INCLUDE_DIR

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${SQLite3_INCLUDE_DIRS})

# ----- FIN LIBRERIAS EXTERNAS ----- #

# ----- CONDICIONALES ----- #

# option(NOMBRE_VARIABLE DESCRIPCION_LEGIBLE VALOR_POR_DEFECTO)
# on/off es la pareja de valores booleanos en CMake. TRUE/FALSE también es correcto
option(EXPERIMENTAL_FEATURE "Activar característica experimental" off)

# El condicional más básico
if(EXPERIMENTAL_FEATURE)
# Añadimos un elemento a la lista
list(APPEND opts_src "experimental_feature.cpp")
# También se puede hacer con SET
# SET(opts_src ${opts_src} "experimental_feature.cpp")
endif()

# ----- FIN CONDICIONALES ----- #

# ----- FILES ----- #

# FILE GLOB selecciona todos los archivos que cumplan la característica y los almacena en libs_src
# GLOB no es recursivo. Si lo necesitas, usa GLOB_RECURSE
file(GLOB libs_src 
    "libs/*.h" "libs/*.cpp"
    "libs/*/*.h" "libs/*/*.hpp" "libs/*/*.cpp"
    "src/*/*.h" "src/*/*.cpp"
    "src/*/*/*.h" "src/*/*/*.cpp"
    "src/*/*/*/*.h" "src/*/*/*/*.cpp"
    "src/*/*/*/*/*.h" "src/*/*/*/*/*.cpp"
    )

# ----- FIN FILES ----- #

# Se creará un ejecutable llamado opts en Linux o opts.exe en Windows
# Se hace referencia a las variables con ${NOMBRE_VARIABLE}
add_executable(opts ${opts_src} ${libs_src})
target_link_libraries(opts ${OPENGL_gl_LIBRARY} ${GLEW_LIBRARIES} glfw ${JSONCPP_LIBRARIES} ${SQLite3_LIBRARIES})