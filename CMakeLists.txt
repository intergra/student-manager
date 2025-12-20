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



# =========================================================
#  项目基本配置 (Basic)
# =========================================================

cmake_minimum_required(VERSION 3.12)
project(student-manager C)

# c11标准
set(CMAKE_C_STANDARD 11)

if(MSVC)
    # 下面的命令只对Windows环境有效：

    # 强制 MSVC 使用 UTF-8 读取源代码 (解决乱码问题)
    add_compile_options("/utf-8")
    # 屏蔽 scanf 不安全警告
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# 指定.h文件夹
include_directories(include)

# 自动扫描 src 目录下所有的 .c 文件
# CONFIGURE_DEPENDS 的作用是：新建文件时，CMake会自动刷新，这样就不用手动添加.c源文件
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")

# 添加源文件
add_executable(student-manager ${SOURCES})



# =========================================================
#  安装配置 (Install)
# =========================================================

# 把 exe 放入 bin 文件夹 (为了配合代码里的 ../data)
install(TARGETS student-manager DESTINATION bin)

# 把 data 文件夹放入安装根目录
install(DIRECTORY data DESTINATION .)

# 把 License 文件放进去
if(EXISTS "${CMAKE_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE DESTINATION .)
endif()



# =========================================================
#  打包配置 (CPack + NSIS)
# =========================================================

# 基础信息
set(CPACK_PACKAGE_NAME "StudentManager")
set(CPACK_PACKAGE_VENDOR "yangshao")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "这是一个简单的C语言学生信息管理系统")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "StudentManager") # 默认安装在 C:/Program Files/StudentManager

# 关键点：指定生成器为 NSIS
set(CPACK_GENERATOR "NSIS")

# NSIS 特有配置 (让安装包看起来更专业)
set(CPACK_NSIS_DISPLAY_NAME "学生信息管理系统")  # 控制面板里显示的名字
set(CPACK_NSIS_HELP_LINK "https://github.com/intergra/student-manager")
set(CPACK_NSIS_CONTACT "3240457157@qq.com")

# LICENSE 文件是否同意界面
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# 创建开始菜单快捷方式
# 格式： "相对路径/exe名字" "快捷方式名字"
set(CPACK_NSIS_MENU_LINKS "bin/student-manager.exe" "运行学生管理系统")

# 桌面快捷方式配置
set(CPACK_NSIS_CREATE_ICONS_EXTRA "
    ; 第一步：设置工作目录 (SetOutPath) 为 exe 所在的目录
    ; 这一步非常关键: 否则程序找不到旁边的 student.dat
    SetOutPath '$INSTDIR\\\\bin'

    ; 第二步：创建快捷方式
    CreateShortCut '$DESKTOP\\\\学生信息管理系统.lnk' '$INSTDIR\\\\bin\\\\student-manager.exe'
")

# 卸载时：删除桌面的快捷方式 (否则卸载后桌面还有个废图标)
set(CPACK_NSIS_DELETE_ICONS_EXTRA "
    Delete '$DESKTOP\\\\学生信息管理系统.lnk'
")

# 启用 CPack
include(CPack)
