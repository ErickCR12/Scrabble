<<<<<<< Updated upstream
<<<<<<< HEAD
# Install script for directory: /home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/lib/googletest-master/googletest
=======
<<<<<<< HEAD
# Install script for directory: /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googletest
=======
# Install script for directory: /home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/lib/googletest-master/googletest
>>>>>>> master
>>>>>>> master
=======
# Install script for directory: /home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googletest
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest/GTestTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest/GTestTargets.cmake"
<<<<<<< Updated upstream
<<<<<<< HEAD
         "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
=======
<<<<<<< HEAD
         "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
=======
         "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
>>>>>>> master
>>>>>>> master
=======
         "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
>>>>>>> Stashed changes
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest/GTestTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest/GTestTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
<<<<<<< Updated upstream
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets-debug.cmake")
=======
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets-debug.cmake")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets-debug.cmake")
>>>>>>> master
>>>>>>> master
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/Export/lib/cmake/GTest/GTestTargets-debug.cmake")
>>>>>>> Stashed changes
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/GTest" TYPE FILE FILES
<<<<<<< Updated upstream
<<<<<<< HEAD
    "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfigVersion.cmake"
    "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfig.cmake"
=======
<<<<<<< HEAD
    "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfigVersion.cmake"
    "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfig.cmake"
=======
    "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfigVersion.cmake"
    "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfig.cmake"
>>>>>>> master
>>>>>>> master
=======
    "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfigVersion.cmake"
    "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/GTestConfig.cmake"
>>>>>>> Stashed changes
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< Updated upstream
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/lib/googletest-master/googletest/include/")
=======
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/lib/googletest-master/googletest/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/libgtestd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/libgtest_maind.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/gtest.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/erickcr12/Documents/AyEDII/Proyectos/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/gtest_main.pc")
<<<<<<< Updated upstream
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/lib/googletest-master/googletest/include/")
>>>>>>> master
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/libgtestd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/libgtest_maind.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/gtest.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/gtest_main.pc")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/oscar_araya_x/Escritorio/GitKraken Repositories/Scrabble/ServerProject/cmake-build-debug/lib/googletest-master/googlemock/gtest/generated/gtest_main.pc")
>>>>>>> master
>>>>>>> master
=======
>>>>>>> Stashed changes
endif()

