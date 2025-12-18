# ==============================================================================
# Project:     Student Information Management System
# Description: CMake build configuration script.
#
# Author:      yangshao
# Version:     1.0
# Date:        2025-12-18
#
# License:     MIT License
# Copyright (c) 2025 yangshao
# ==============================================================================

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
