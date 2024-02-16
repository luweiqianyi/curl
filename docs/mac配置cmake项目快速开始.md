# mac配置cmake项目快速开始
1. 编写项目程序文件，整个项目的目录如下所示：
    ```shell
    mudeMacBook-Pro:curl mu$ tree
    .
    ├── CMakeLists.txt
    ├── docs
    │   └── mac配置cmake项目快速开始.md
    └── src
        ├── CMakeLists.txt
        └── main.cpp

    2 directories, 4 files
    ```
    其中根目录下的`CMakeLists.txt`文件中的内容如下所示：
    ```shell
    cmake_minimum_required(VERSION 3.28)
    project(curldemo)

    add_subdirectory(src)
    ```
    `src`目录下的`CMakeLists.txt`文件中的内容如下所示：
    ```shell
    cmake_minimum_required(VERSION 3.28)
    project(curlex)

    set(EXE_NAME "curlex")
    set(
        SOURCE_FILES
        main.cpp
    )

    find_package(CURL REQUIRED)
    if(CURL_FOUND)
        message(STATUS "CURL found.")
    else()
        message(FATAL_ERROR "CURL not found")
    endif()

    add_executable(
        ${EXE_NAME}
        ${SOURCE_FILES}
    )
    target_include_directories(${EXE_NAME} PRIVATE ${CURL_INCLUDE_DIRS})
    target_link_libraries(${EXE_NAME} PRIVATE ${CURL_LIBRARIES})
    ```
    `src`目录下的源文件`main.cpp`内容如下所示：
    ```cpp
    #include <cstdio>

    int main()
    {
        printf("%s\n","Hello world!");
        return 0;
    }
    ```
2. 完成程序及`CMake`项目配置文件的编写之后，开始对项目进行构建。打开`Command Palette`,选择`CMake: Open CMake Tools Extension Settings`,在配置项`Cmake: Generator`下填写生成器为`Unix Makefiles`，关于`CMake Generator`的种类可以参见[https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)。
3. 打开`Command Palette...`,选择`CMake: Configure`。整个执行过程如下所示：
    ```shell
    [main] 正在配置项目: curl 
    [proc] 执行命令: /usr/local/bin/cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S/Users/mu/Desktop/curl -B/Users/mu/Desktop/curl/build -G "Unix Makefiles"
    [cmake] Not searching for unused variables given on the command line.
    [cmake] -- The C compiler identification is AppleClang 15.0.0.15000100
    [cmake] -- The CXX compiler identification is AppleClang 15.0.0.15000100
    [cmake] -- Detecting C compiler ABI info
    [cmake] -- Detecting C compiler ABI info - done
    [cmake] -- Check for working C compiler: /usr/bin/clang - skipped
    [cmake] -- Detecting C compile features
    [cmake] -- Detecting C compile features - done
    [cmake] -- Detecting CXX compiler ABI info
    [cmake] -- Detecting CXX compiler ABI info - done
    [cmake] -- Check for working CXX compiler: /usr/bin/clang++ - skipped
    [cmake] -- Detecting CXX compile features
    [cmake] -- Detecting CXX compile features - done
    [cmake] -- Found CURL: /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libcurl.tbd (found version "8.4.0")  
    [cmake] -- CURL found.
    [cmake] -- Configuring done (2.5s)
    [cmake] -- Generating done (0.0s)
    [cmake] -- Build files have been written to: /Users/mu/Desktop/curl/build
    ```
    执行后会自动生成`build`目录，执行过程中生成的项目构建文件如下所示：
    ```shell
    .
    ├── CMakeCache.txt
    ├── CMakeFiles
    │   ├── 3.28.3
    │   │   ├── CMakeCCompiler.cmake
    │   │   ├── CMakeCXXCompiler.cmake
    │   │   ├── CMakeDetermineCompilerABI_C.bin
    │   │   ├── CMakeDetermineCompilerABI_CXX.bin
    │   │   ├── CMakeSystem.cmake
    │   │   ├── CompilerIdC
    │   │   │   ├── CMakeCCompilerId.c
    │   │   │   ├── a.out
    │   │   │   └── tmp
    │   │   └── CompilerIdCXX
    │   │       ├── CMakeCXXCompilerId.cpp
    │   │       ├── a.out
    │   │       └── tmp
    │   ├── CMakeConfigureLog.yaml
    │   ├── CMakeDirectoryInformation.cmake
    │   ├── CMakeScratch
    │   ├── Makefile.cmake
    │   ├── Makefile2
    │   ├── TargetDirectories.txt
    │   ├── cmake.check_cache
    │   ├── pkgRedirects
    │   └── progress.marks
    ├── Makefile
    ├── cmake_install.cmake
    ├── compile_commands.json
    └── src
        ├── CMakeFiles
        │   ├── CMakeDirectoryInformation.cmake
        │   ├── curlex.dir
        │   │   ├── DependInfo.cmake
        │   │   ├── build.make
        │   │   ├── cmake_clean.cmake
        │   │   ├── compiler_depend.make
        │   │   ├── compiler_depend.ts
        │   │   ├── depend.make
        │   │   ├── flags.make
        │   │   ├── link.txt
        │   │   └── progress.make
        │   └── progress.marks
        ├── Makefile
        └── cmake_install.cmake

    12 directories, 33 files
    ```
4. 进入`build`目录执行`make`命令。执行结果如下所示：
    ```shell
    mudeMacBook-Pro:build mu$ make
    [ 50%] Building CXX object src/CMakeFiles/curlex.dir/main.cpp.o
    [100%] Linking CXX executable curlex
    [100%] Built target curlex
    ```
    执行后`build`下目录结构如下所示：
    ```shell
    .
    ├── CMakeCache.txt
    ├── CMakeFiles
    │   ├── 3.28.3
    │   │   ├── CMakeCCompiler.cmake
    │   │   ├── CMakeCXXCompiler.cmake
    │   │   ├── CMakeDetermineCompilerABI_C.bin
    │   │   ├── CMakeDetermineCompilerABI_CXX.bin
    │   │   ├── CMakeSystem.cmake
    │   │   ├── CompilerIdC
    │   │   │   ├── CMakeCCompilerId.c
    │   │   │   ├── a.out
    │   │   │   └── tmp
    │   │   └── CompilerIdCXX
    │   │       ├── CMakeCXXCompilerId.cpp
    │   │       ├── a.out
    │   │       └── tmp
    │   ├── CMakeConfigureLog.yaml
    │   ├── CMakeDirectoryInformation.cmake
    │   ├── CMakeScratch
    │   ├── Makefile.cmake
    │   ├── Makefile2
    │   ├── TargetDirectories.txt
    │   ├── cmake.check_cache
    │   ├── pkgRedirects
    │   └── progress.marks
    ├── Makefile
    ├── cmake_install.cmake
    ├── compile_commands.json
    └── src
        ├── CMakeFiles
        │   ├── CMakeDirectoryInformation.cmake
        │   ├── curlex.dir
        │   │   ├── DependInfo.cmake
        │   │   ├── build.make
        │   │   ├── cmake_clean.cmake
        │   │   ├── compiler_depend.make
        │   │   ├── compiler_depend.ts
        │   │   ├── depend.make
        │   │   ├── flags.make
        │   │   ├── link.txt
        │   │   ├── main.cpp.o
        │   │   ├── main.cpp.o.d
        │   │   └── progress.make
        │   └── progress.marks
        ├── Makefile
        ├── cmake_install.cmake
        └── curlex

    12 directories, 36 files
    ```
    > 相较于构建过程多出了`main.cpp.o`，`main.cpp.o.d`，`curlex`三个文件，其中前两个是用于链接的目标文件,第三个是生成的可执行文件。
5. 在`build`目录下运行可执行程序：`./src/curlex`,结果如下：
    ```shell
    mudeMacBook-Pro:build mu$ ./src/curlex
    Hello world!
    ```