<<<<<<< Updated upstream
<<<<<<< HEAD
# Install script for directory: /home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject
=======
<<<<<<< HEAD
# Install script for directory: /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject
=======
# Install script for directory: /home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject
>>>>>>> master
>>>>>>> master
=======
# Install script for directory: /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject
>>>>>>> Stashed changes

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
<<<<<<< Updated upstream
<<<<<<< HEAD
  include("/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/cmake_install.cmake")
=======
<<<<<<< HEAD
  include("/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/cmake_install.cmake")
=======
  include("/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/cmake_install.cmake")
>>>>>>> master
>>>>>>> master
=======
  include("/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/cmake_install.cmake")
>>>>>>> Stashed changes

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< Updated upstream
<<<<<<< HEAD
file(WRITE "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
<<<<<<< HEAD
file(WRITE "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> master
>>>>>>> master
=======
file(WRITE "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> Stashed changes
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
