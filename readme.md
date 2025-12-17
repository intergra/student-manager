# 🎓 学生信息管理系统




**一个功能完整、代码规范的C语言课程设计项目**

[功能特性](#-功能特性) • [快速开始](#-快速开始) • [使用指南](#-使用指南) • [项目结构](#-项目结构)


## 📖 项目简介

这是一个基于**纯C语言**开发的命令行学生信息管理系统，专为C语言课程设计打造。项目采用**模块化设计**，代码结构清晰，注释详尽，充分展示了C语言的核心特性。

### 💡 核心技术点

<table>
<tr>
<td width="50%">

**数据结构**
- ✅ 单向链表的实现
- ✅ 动态内存管理（malloc/free）
- ✅ 指针的灵活运用

</td>
<td width="50%">

**核心功能**
- ✅ 完整的CRUD操作
- ✅ 冒泡排序算法
- ✅ 二进制文件I/O

</td>
</tr>
</table>

---

## ✨ 功能特性

### 🎯 主要功能

| 功能 | 描述 | 特点 |
|:---:|:---|:---|
| 📝 **添加学生** | 录入学生基本信息 | • 学号唯一性检查<br>• 支持字母+数字学号<br>• 输入验证 |
| 📋 **显示学生** | 表格化展示所有数据 | • 美观的表格布局<br>• 自动统计人数<br>• 清晰的列对齐 |
| 🔍 **查找学生** | 按学号精确查询 | • 快速定位<br>• 详细信息卡片<br>• 友好的提示 |
| ✏️ **修改信息** | 更新学生记录 | • 显示当前信息<br>• 逐项修改<br>• 确认机制 |
| 🗑️ **删除学生** | 移除学生记录 | • 二次确认<br>• 安全删除<br>• 内存自动释放 |
| 📊 **智能排序** | GPA降序排列 | • 冒泡排序算法<br>• 即时显示结果 |
| 📈 **数据统计** | 多维度分析 | • 平均GPA<br>• 最高/最低分<br>• 成绩分布 |
| 💾 **持久化** | 数据保存与加载 | • 二进制存储<br>• 自动加载<br>• 退出自动保存 |

### 📊 数据字段

```
学号 (ID)      : 支持字母+数字组合，如 WB2314012
姓名 (Name)    : 最长50字符，支持中英文
专业 (Major)   : 最长50字符
GPA           : 0.0 - 4.0 浮点数
```

---

## 🚀 快速开始

### 📋 环境要求

<table>
<tr>
<td><b>编译器</b></td>
<td>GCC 5.0+ / Clang 3.4+ / MSVC 2015+</td>
</tr>
<tr>
<td><b>构建工具</b></td>
<td>CMake 3.10+</td>
</tr>
<tr>
<td><b>操作系统</b></td>
<td>Windows / Linux</td>
</tr>
</table>

### 💻 方法一：CLion

```
1️⃣ 打开CLion → File → Open
2️⃣ 选择 student-manager 文件夹
3️⃣ 等待CMake自动配置完成
4️⃣ 点击绿色运行按钮 ▶️
```



### 🖥️ 方法二：命令行编译

#### Windows

```bash
# 进入项目目录
cd student-manager

# 创建构建目录
mkdir cmake-build-debug
cd cmake-build-debug

# 配置并编译
cmake ..
cmake --build .

# 设置UTF-8编码（避免中文乱码）
chcp 65001

# 运行程序
student-manager.exe
```

#### Linux

```bash
# 进入项目目录
cd student-manager

# 创建并进入构建目录
mkdir -p cmake-build-debug
cd cmake-build-debug

# 配置并编译
cmake ..
make

# 运行程序
./student-manager
```

### 🔧 方法三：VS Code

**安装必要插件：**
- C/C++ Extension Pack
- CMake Tools

**打开项目：**
```
File → Open Folder → 选择 student-manager
```

**配置和运行：**
- `Ctrl+Shift+P` → "CMake: Configure"
- `F7` 编译
- `Shift+F5` 运行

---

## 📂 项目结构

```
student-manager/
│
├── 📄 CMakeLists.txt              # CMake构建配置
├── 📘 README.md                   # 项目文档（本文件）
│
├── 📁 include/                    # 头文件目录
│   └── 📄 student.h               # 结构体定义、函数声明
│
├── 📁 src/                        # 源代码目录
│   ├── 📄 main.c                  # 程序入口、主循环
│   └── 📄 student.c               # 核心功能实现
│
└── 📁 cmake-build-debug/          # 构建输出目录（自动生成）
    ├── ⚙️ student-manager(.exe)   # 可执行文件
    └── 💾 students.dat            # 数据文件
```

### 🗂️ 模块说明

| 文件 | 行数 | 职责 |
|:---|:---:|:---|
| `student.h` | ~80 | 📌 接口定义：结构体、宏、函数声明 |
| `student.c` | ~450 | 🔧 核心实现：所有业务逻辑和算法 |
| `main.c` | ~70 | 🎯 程序入口：主循环和用户交互 |

---

## 📖 使用指南

### 🎮 基本操作流程

**1. 启动程序**
```bash
# 在cmake-build-debug目录下执行
./student-manager   
```
程序会自动加载之前保存的数据

**2. 添加学生数据**
- 选择菜单 `1`
- 按提示输入学号、姓名、专业、GPA
- 学号支持 `WB2314012` 这样的字母+数字格式

**3. 查看所有学生**
- 选择菜单 `2`
- 以表格形式显示所有记录

**4. 数据统计**
- 选择菜单 `7`
- 查看平均GPA、最高最低分、分布统计

**5. 保存退出**
- 选择菜单 `0`
- 数据自动保存到 `students.dat`

### 🎬 使用示例

**添加学生：**

```
请输入您的选择 [0-8]: 1

┌─────────────────────────────────────┐
│         添加学生信息                │
└─────────────────────────────────────┘

请输入学号: WB1234567
请输入姓名: 张三
请输入专业: 计算机科学与技术
请输入GPA (0.0-4.0): 3.85

✅ [成功] 学生信息添加成功！
   学号: WB1234567 | 姓名: 张三 | 专业: 计算机科学与技术 | GPA: 3.85
```

**显示所有学生：**

```
┌──────────────────────────────────────────────────────────────────────────────┐
│                       所有学生信息 (共 3 人)                                 │
├──────────────────────────────────────────────────────────────────────────────┤
│ 学号            姓名            专业                              GPA      │
├──────────────────────────────────────────────────────────────────────────────┤
│ WB1234567       张三            计算机科学与技术                  3.85     │
│ WB2222222       李四            软件工程                          3.92     │
│ WB3333333       王五            人工智能                          3.67     │
└──────────────────────────────────────────────────────────────────────────────┘
```

**统计信息：**

```
┌─────────────────────────────────────────────┐
│              统计信息                       │
├─────────────────────────────────────────────┤
│ 📊 学生总数: 3                              │
│ 📈 平均GPA:  3.81                           │
│                                             │
│ 🏆 最高GPA:  3.92                           │
│    学号: WB2222222   姓名: 李四             │
│                                             │
│ 📉 最低GPA:  3.67                           │
│    学号: WB2222222   姓名: 王五             │
└─────────────────────────────────────────────┘

📊 GPA分布情况:
  优秀 (3.5-4.0): 3人 (100.0%)
  良好 (3.0-3.5): 0人 (0.0%)
  中等 (2.0-3.0): 0人 (0.0%)
  较差 (0.0-2.0): 0人 (0.0%)
```

---

## 🔬 核心技术实现

### 1️⃣ 数据结构设计

```c
typedef struct Student {
    char id[20];              // 学号（支持字母+数字）
    char name[50];            // 姓名
    char major[50];           // 专业
    float gpa;                // 绩点
    struct Student *next;     // 指向下一个节点的指针
} Student;
```

**设计亮点：**
- 使用字符数组存储学号，支持 `WB1234567` 等复杂格式
- 单向链表结构，动态内存管理
- 结构体自引用实现链式存储

### 2️⃣ 链表操作

```c
// 头插法添加节点
newStudent->next = head;
head = newStudent;

// 遍历链表
Student *current = head;
while (current != NULL) {
    // 处理当前节点
    current = current->next;
}

// 删除节点
if (prev == NULL) {
    head = current->next;  // 删除头节点
} else {
    prev->next = current->next;  // 删除中间节点
}
free(current);
```

### 3️⃣ 冒泡排序算法

```c
do {
    swapped = 0;
    ptr1 = head;
    while (ptr1->next != lptr) {
        if (ptr1->gpa < ptr1->next->gpa) {
            // 交换数据域（降序）
            swap(ptr1, ptr1->next);
            swapped = 1;
        }
        ptr1 = ptr1->next;
    }
    lptr = ptr1;
} while (swapped);
```

**时间复杂度：** O(n²)  
**空间复杂度：** O(1)

### 4️⃣ 文件持久化

```c
// 保存（二进制写入）
FILE *file = fopen("students.dat", "wb");
while (current != NULL) {
    fwrite(current, sizeof(Student), 1, file);
    current = current->next;
}

// 加载（二进制读取）
Student temp;
while (fread(&temp, sizeof(Student), 1, file) == 1) {
    // 重建链表
    Student *newStudent = createStudent(...);
    newStudent->next = head;
    head = newStudent;
}
```

---

## 🛠️ 常见问题

### ❓ 编译问题

**Q: CMake not found**

**Windows解决方案：**
- 从 https://cmake.org/download/ 下载安装包
- 安装时选择"Add CMake to system PATH"

**Linux解决方案：**
```bash
# Ubuntu/Debian
sudo apt-get install cmake

# CentOS/RHEL
sudo yum install cmake
```

**Q: 找不到编译器**

**Windows解决方案：**
- 安装 MinGW：https://sourceforge.net/projects/mingw/
- 或安装 Visual Studio 2022

**Linux解决方案：**
```bash
# Ubuntu/Debian
sudo apt-get install build-essential
```

### ❓ 运行问题

**Q: Windows终端中文乱码**

**解决方案1 - 运行前设置：**
```bash
chcp 65001
student-manager.exe
```

**解决方案2 - 修改CLion终端设置：**
```
Settings → Tools → Terminal → Shell path
改为: cmd.exe /k chcp 65001
```

**Q: 数据文件损坏**

**解决方案：删除文件**
```bash
# Windows
del cmake-build-debug\students.dat

# Linux
rm cmake-build-debug/students.dat
```

**Q: 输入学号报错**

如果你的学号包含字母（如 WB2314012），本系统完全支持！确保：
- 学号长度不超过19个字符
- 可以包含字母、数字、连字符等

---

## 📊 性能分析

### ⚡ 算法复杂度

| 操作 | 时间复杂度 | 空间复杂度 |
|:---|:---:|:---:|
| 添加学生 | O(1) | O(1) |
| 显示所有 | O(n) | O(1) |
| 查找学生 | O(n) | O(1) |
| 修改信息 | O(n) | O(1) |
| 删除学生 | O(n) | O(1) |
| 冒泡排序 | O(n²) | O(1) |
| 统计分析 | O(n) | O(1) |

### 💾 存储特点

- **链表存储：** 动态分配，无需预留空间
- **二进制文件：** 紧凑存储，读写高效
- **内存管理：** 程序退出时自动清理，无内存泄漏

---

## 🎯 代码规范

### ✅ 编码规范

- **命名规范：** 驼峰命名法，函数名动词开头
- **注释规范：** 关键代码均有详细注释
- **模块化设计：** 头文件和源文件分离
- **错误处理：** 完善的输入验证和错误提示

### 📝 函数注释示例

```c
/**
 * @brief 创建新的学生节点
 * @param id 学号
 * @param name 姓名
 * @param major 专业
 * @param gpa 绩点
 * @return 指向新创建学生节点的指针，失败返回NULL
 */
Student* createStudent(const char *id, const char *name, 
                      const char *major, float gpa);
```

---

## 🎓 学习要点

### 适合学习的知识点

<table>
<tr>
<td width="50%">

**基础知识**
- ✅ 结构体的定义和使用
- ✅ 指针的概念和操作
- ✅ 动态内存分配
- ✅ 文件I/O操作
- ✅ 字符串处理

</td>
<td width="50%">

**进阶知识**
- ✅ 链表的实现和遍历
- ✅ 排序算法（冒泡）
- ✅ 模块化编程
- ✅ 头文件设计
- ✅ 代码规范

</td>
</tr>
</table>

### 📚 代码亮点

**1. 安全的字符串处理**
```c
// 使用 strncpy 防止缓冲区溢出
strncpy(newStudent->id, id, MAX_ID - 1);
newStudent->id[MAX_ID - 1] = '\0';  // 确保字符串结束

// 使用 fgets 安全读取输入
fgets(id, MAX_ID, stdin);
id[strcspn(id, "\n")] = '\0';  // 移除换行符
```

**2. 完善的输入验证**
```c
// GPA范围检查
if (scanf("%f", &gpa) != 1 || gpa < 0.0 || gpa > 4.0) {
    while (getchar() != '\n') {}  // 清空缓冲区
    printf(" [错误] GPA必须在0.0到4.0之间！\n");
    return;
}
```

**3. 学号唯一性检查**
```c
// 遍历链表检查重复
Student *temp = head;
while (temp != NULL) {
    if (strcmp(temp->id, id) == 0) {
        printf(" [错误] 学号 %s 已存在！\n", id);
        return;
    }
    temp = temp->next;
}
```

---

## 🔮 未来改进

**可扩展功能：**
- 🔍 支持按姓名模糊查询
- ⚡ 实现更高效的排序算法（快速排序）
- 📤 添加数据导出功能（CSV格式）
- 📥 支持批量导入数据
- ↩️ 添加撤销/重做功能
- 🖼️ 图形化界面（可选）

---

## 👨‍💻 项目信息

<table>
<tr>
<td><b>课程</b></td>
<td>程序设计实训(软件部分)</td>
</tr>
<tr>
<td><b>语言</b></td>
<td>C11</td>
</tr>
<tr>
<td><b>构建工具</b></td>
<td>CMake 3.10+</td>
</tr>
<tr>
<td><b>代码行数</b></td>
<td>~600 行</td>
</tr>
<tr>
<td><b>许可证</b></td>
<td>MIT License</td>
</tr>
</table>

---

## 📄 许可证

本项目采用 [MIT License](LICENSE) 开源协议，仅用于学习交流。


---

## 🙏 致谢

感谢所有为这个项目提供帮助和建议的同学和老师！

---

**⭐ 如果这个项目对你有帮助，请给一个星标！**

