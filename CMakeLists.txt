cmake_minimum_required(VERSION 3.10)
project(student-manager C)

# c11标准
set(CMAKE_C_STANDARD 11)

# 指定.h文件夹
include_directories(include)

# 将.c源文件设置成变量
set(SOURCES
        src/main.c
        src/student.c
)

# 添加源文件
add_executable(student-manager ${SOURCES})
