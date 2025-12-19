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

cmake_minimum_required(VERSION 3.12)
project(student-manager C)

# c11标准
set(CMAKE_C_STANDARD 11)

# 指定.h文件夹
include_directories(include)

# 自动扫描 src 目录下所有的 .c 文件
# CONFIGURE_DEPENDS 的作用是：新建文件时，CMake会自动刷新，这样就不用手动添加.c源文件
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")

# 添加源文件
add_executable(student-manager ${SOURCES})
