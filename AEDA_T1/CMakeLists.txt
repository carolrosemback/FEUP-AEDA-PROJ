cmake_minimum_required(VERSION 3.14)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp Utils/split.h Classes/Funcionario.h Classes/Funcionario.cpp Classes/Aeroporto.h Classes/Aeroporto.cpp Classes/Empresa.h Classes/Empresa.cpp Classes/BinaryTree.h Menu/Menu.cpp Menu/Menu.h Utils/split.cpp Utils/sorts.h Utils/sorts.cpp Menu/MainMenu.cpp Menu/MainMenu.h Menu/ListarAeroportoMenu.cpp Menu/ListarAeroportoMenu.h Menu/AcessarAeroportoMenu.cpp Menu/AcessarAeroportoMenu.h Menu/FuncionariosMenu.cpp Menu/FuncionariosMenu.h Menu/AviaoMenu.cpp Menu/AviaoMenu.h Menu/VooMenu.cpp Menu/VooMenu.h Menu/EmpresaMenu.h Menu/EmpresaMenu.cpp Classes/Aviao.h Classes/Informacao.h Classes/Voo.h Utils/Localizacao.h Utils/Hora.h Utils/Data.h Utils/GPS.h Utils/lower.h Utils/lower.cpp)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
