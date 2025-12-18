/**
 * @file      student.c
 * @brief     Implementation of student management logic and file persistence.
 * @details   Contains the core logic for CRUD operations (Create, Read, Update, Delete)
 *            on the linked list, as well as file I/O operations for data persistence.
 *
 * @author    yangshao
 * @date      2025-12-18
 * @version   1.0
 *
 * @copyright Copyright (c) 2025 yangshao
 * @license   MIT License
 *            SPDX-License-Identifier: MIT
 */

#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义全局头指针
// 链表的入口，初始为空，表示没有学生
Student *head = NULL;

// ==================== 界面函数实现 ====================
void displayMenu() {
    // 纯文本菜单，确保在任何终端都能对齐
    printf("\n┌────────────────────────────────────────┐\n");
    printf("│              主菜单                    │\n");
    printf("├────────────────────────────────────────┤\n");
    printf("│  1. 添加学生信息                       │\n");
    printf("│  2. 显示所有学生                       │\n");
    printf("│  3. 查找学生                           │\n");
    printf("│  4. 修改学生信息                       │\n");
    printf("│  5. 删除学生                           │\n");
    printf("│  6. 按GPA排序                          │\n");
    printf("│  7. 统计信息                           │\n");
    printf("│  8. 保存到文件                         │\n");
    printf("│  0. 退出系统                           │\n");
    printf("└────────────────────────────────────────┘\n");
}

// ==================== 链表操作函数实现 ====================

// 创建新学生节点的工厂函数
// 参数：学号、姓名、专业、GPA
// 返回：指向新创建节点的指针
Student* createStudent(const char *id, const char *name, const char *major, float gpa) {
    // 动态分配内存，大小为一个Student结构体
    Student *newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("[错误] 内存分配失败！\n");
        return NULL;
    }

    // 安全拷贝字符串
    // 使用 strncpy 防止缓冲区溢出，保留最后一位给结束符 '\0'
    strncpy(newStudent->id, id, MAX_ID - 1);
    newStudent->id[MAX_ID - 1] = '\0';

    strncpy(newStudent->name, name, MAX_NAME - 1);
    newStudent->name[MAX_NAME - 1] = '\0';

    strncpy(newStudent->major, major, MAX_MAJOR - 1);
    newStudent->major[MAX_MAJOR - 1] = '\0';

    // 赋值数值类型和指针
    newStudent->gpa = gpa;
    newStudent->next = NULL; // 新节点暂时不指向任何地方

    return newStudent;
}

// 释放整个链表的内存，防止内存泄漏
void freeAllStudents() {
    Student *current = head;
    Student *next;

    while (current != NULL) {
        next = current->next; // 先保存下一个节点的地址
        free(current);        // 释放当前节点
        current = next;       // 移动到下一个节点
    }

    head = NULL;              //释放后将头指针置空
}

// ==================== 业务功能函数实现 ====================

// 添加学生
void addStudent() {
    char id[MAX_ID];
    char name[MAX_NAME];
    char major[MAX_MAJOR];
    float gpa;

    printf("┌─────────────────────────────────────┐\n");
    printf("│         添加学生信息                │\n");
    printf("└─────────────────────────────────────┘\n\n");

    printf("请输入学号: ");
    fgets(id, MAX_ID, stdin);             // 使用 fgets 读取字符串，允许包含空格（虽然学号一般没有）
    id[strcspn(id, "\n")] = '\0';       // 去除 fgets 读入的换行符 '\n'

    if (strlen(id) == 0) {
        printf(" [错误] 学号不能为空！\n");
        return;
    }

    // 查重：遍历链表看学号是否已存在
    Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            printf(" [错误] 学号 %s 已存在！请使用其他学号\n", id);
            return;
        }
        temp = temp->next;
    }

    // 输入姓名
    printf("请输入姓名: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf(" [错误] 姓名不能为空！\n");
        return;
    }

    // 输入专业
    printf("请输入专业: ");
    fgets(major, MAX_MAJOR, stdin);
    major[strcspn(major, "\n")] = '\0';

    if (strlen(major) == 0) {
        printf(" [错误] 专业不能为空！\n");
        return;
    }

    // 输入GPA
    printf("请输入GPA (0.0-4.0): ");
    // scanf 返回 1 表示成功读入了一个浮点数
    if (scanf("%f", &gpa) != 1 || gpa < 0.0 || gpa > 4.0) {
        // 清空输入缓冲区，防止死循环
        while (getchar() != '\n') {}
        printf(" [错误] GPA必须在0.0到4.0之间！\n");
        return;
    }

    // 清除输入缓冲区
    while (getchar() != '\n') {}

    // 创建节点
    Student *newStudent = createStudent(id, name, major, gpa);
    if (newStudent == NULL) return;

    // 头插法插入链表
    newStudent->next = head;    // 将新节点的 next 指向当前的头
    head = newStudent;          // 更新头指针指向新节点

    printf("\n [成功] 学生信息添加成功！\n");
    printf("   学号: %s | 姓名: %s | 专业: %s | GPA: %.2f\n", id, name, major, gpa);
}

// 显示所有学生
void displayAllStudents() {
    if (head == NULL) {
        printf(" 暂无学生信息\n");
        printf(" [提示] 请先使用菜单选项1添加学生\n");
        return;
    }

    // 计算总人数
    int count = 0;
    Student *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // 表格头部
    printf("┌──────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                       所有学生信息 (共 %d 人)                                 │\n", count);
    printf("├──────────────────────────────────────────────────────────────────────────────┤\n");

    // 表头列名
    // 关键点讲解：这里去掉了不同列之间的竖线 '|'，改用空格分隔
    // 这样做是为了防止中文字符宽度不一致导致的表格错位问题
    // %-14s: 左对齐，占用14个字符宽
    // %-34s: 给专业预留了很大的空间，防止文字溢出
    printf("│ %-14s  %-14s  %-34s  %-8s │\n", "学号", "姓名", "专业", "GPA");

    // 分割线
    printf("├──────────────────────────────────────────────────────────────────────────────┤\n");

    // 遍历打印数据
    current = head;
    while (current != NULL) {
        printf("│ %-14s  %-14s  %-34s  %-8.2f │\n",
               current->id, current->name, current->major, current->gpa);
        current = current->next;
    }

    // 底部边框
    printf("└──────────────────────────────────────────────────────────────────────────────┘\n");
}

// 查找学生
void searchStudent() {
    // 没有学生时
    if (head == NULL) {
        printf("[提示] 暂无学生信息!\n");
        return;
    }

    char id[MAX_ID];
    printf(" 请输入要查找的学号: ");
    fgets(id, MAX_ID, stdin);
    id[strcspn(id, "\n")] = '\0';

    // 遍历链表查找
    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            // 找到了，打印详情信息卡片
            printf("\n┌─────────────────────────────────────┐\n");
            printf("│         查找结果                    │\n");
            printf("├─────────────────────────────────────┤\n");
            printf("│ 学号: %-29s │\n", current->id);
            printf("│ 姓名: %-29s │\n", current->name);
            printf("│ 专业: %-29s │\n", current->major);
            printf("│ GPA:  %-29.2f │\n", current->gpa);
            printf("└─────────────────────────────────────┘\n");
            return;
        }
        current = current->next;
    }

    printf(" [提示] 未找到学号为 %s 的学生\n", id);
}

// 修改学生信息
void updateStudent() {
    if (head == NULL) {
        printf("[提示] 暂无学生信息\n");
        return;
    }

    // 安全读取字符串
    // fgets 会把换行符 \n 也读进去。
    // id：存储输入的目标数组，MAX_ID：最多读取的字符数（防止溢出），stdin：从标准输入（键盘）读取
    // strcspn 函数的作用是：查找字符串中第一次出现指定字符的位置
    char id[MAX_ID];
    printf("请输入要修改的学号: ");
    fgets(id, MAX_ID, stdin);
    id[strcspn(id, "\n")] = '\0';            //将\n 替换成字符串结束符 \0

    // 创建一个指针 current，让它指向链表的头节点（第一个学生）
    // 遍历整个链表，查找学号匹配的学生。
    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            // 找到了，先显示旧信息
            printf("\n当前学生信息:\n");
            printf("  姓名: %s\n", current->name);
            printf("  专业: %s\n", current->major);
            printf("  GPA:  %.2f\n\n", current->gpa);

            // 输入新信息
            printf("请输入新信息:\n");

            printf("姓名: ");
            fgets(current->name, MAX_NAME, stdin);                  // 更新name
            current->name[strcspn(current->name, "\n")] = '\0';   // 将\n 替换成字符串结束符 \0

            printf("专业: ");
            fgets(current->major, MAX_MAJOR, stdin);
            current->major[strcspn(current->major, "\n")] = '\0';

            printf("GPA (0.0-4.0): ");
            float temp;  // 临时变量
            if (scanf("%f", &temp) != 1 || temp < 0.0 || temp > 4.0) {  //输入的GPA不符合时
                while (getchar() != '\n') {}
                printf(" [错误] GPA输入无效！\n");
                return;
            }
            // 验证通过后，才真正赋值
            current->gpa = temp;

            while (getchar() != '\n') {}

            printf("\n [成功] 学生信息修改成功！\n");
            return;
        }
        current = current->next;
    }

    printf(" [提示] 未找到学号为 %s 的学生\n", id);
}

// 删除学生
void deleteStudent() {
    if (head == NULL) {
        printf("[提示] 暂无学生信息\n");
        return;
    }

    char id[MAX_ID];
    printf("请输入要删除的学号: ");
    fgets(id, MAX_ID, stdin);
    id[strcspn(id, "\n")] = '\0';

    Student *current = head;
    Student *prev = NULL; // 需要一个指针记录"上一个"节点

    while (current != NULL) {
        // 找到了目标
        if (strcmp(current->id, id) == 0) {
            // 确认提示
            printf("\n确认删除以下学生信息？\n");
            printf("  学号: %s\n", current->id);
            printf("  姓名: %s\n", current->name);
            printf("  确认删除？(y/n): ");

            // 获取字符confirm，并清除缓冲区
            char confirm;
            scanf(" %c", &confirm);
            while (getchar() != '\n') {}

            // 不是y或者Y
            if (confirm != 'y' && confirm != 'Y') {
                printf(" 删除操作已取消\n");
                return;
            }

            // 执行删除逻辑
            if (prev == NULL) {
                // 情况1：删除的是头节点
                head = current->next;
            } else {
                // 情况2：删除的是中间或尾部节点
                // 让上一个节点直接指向下一个节点，跳过当前节点
                prev->next = current->next;
            }

            free(current); // 释放内存
            printf(" [成功] 学生信息删除成功！\n");
            return;
        }

        // 继续向后遍历
        prev = current;
        current = current->next;
    }

    printf(" [提示] 未找到学号为 %s 的学生\n", id);
}

// 排序 (使用冒泡排序算法交换节点数据)
void sortStudents() {
    // 学生数量为0或1时
    if (head == NULL || head->next == NULL) {
        printf("[提示] 学生数量不足，无需排序\n");
        return;
    }

    int swapped;                // 每轮开始，假设没有交换
    Student *ptr1;              // 操作最前面的节点开始比较排序
    Student *lptr = NULL;       // 指向上一次冒泡排序结束时的节点
    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            // 降序排列：如果当前GPA < 下一个GPA，则交换
            if (ptr1->gpa < ptr1->next->gpa) {
                // 交换数据域（比交换指针链接更简单）
                char tempId[MAX_ID];
                char tempName[MAX_NAME];
                char tempMajor[MAX_MAJOR];
                float tempGpa;

                // 备份当前节点
                strcpy(tempId, ptr1->id);
                strcpy(tempName, ptr1->name);
                strcpy(tempMajor, ptr1->major);
                tempGpa = ptr1->gpa;

                // 将下一个节点的数据移到当前节点
                strcpy(ptr1->id, ptr1->next->id);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->major, ptr1->next->major);
                ptr1->gpa = ptr1->next->gpa;

                // 将备份的数据移到下一个节点
                strcpy(ptr1->next->id, tempId);
                strcpy(ptr1->next->name, tempName);
                strcpy(ptr1->next->major, tempMajor);
                ptr1->next->gpa = tempGpa;

                swapped = 1;    // 有交换则设置为1
            }
            ptr1 = ptr1->next;  //if完成后指向下一个节点
        }
        lptr = ptr1; // 每一轮冒泡后，最后的元素已经是最大的了
    } while (swapped);

    printf("[成功] 已按GPA从高到低排序完成！\n\n");
    displayAllStudents(); // 排序后直接显示
}

// 统计信息
void calculateStatistics() {
    if (head == NULL) {
        printf("[提示] 暂无学生信息\n");
        return;
    }

    int count = 0;
    float sum = 0.0;
    float maxGpa = head->gpa;
    float minGpa = head->gpa;
    Student *maxStudent = head;
    Student *minStudent = head;

    // 遍历链表收集数据
    Student *current = head;
    while (current != NULL) {
        count++;
        sum += current->gpa;

        // 更新最大值
        if (current->gpa > maxGpa) {
            maxGpa = current->gpa;
            maxStudent = current;
        }
        // 更新最小值
        if (current->gpa < minGpa) {
            minGpa = current->gpa;
            minStudent = current;
        }
        // 到下一个节点
        current = current->next;
    }

    float average = sum / count;

    // 显示统计框
    printf("┌─────────────────────────────────────────────┐\n");
    printf("│              统计信息                       │\n");
    printf("├─────────────────────────────────────────────┤\n");
    // 格式化输出，%-30d 表示左对齐数字，保证右侧边框对齐
    printf("│ 学生总数: %-30d │\n", count);
    printf("│ 平均GPA:  %-30.2f │\n", average);
    printf("│                                             │\n");
    // 这里预留了空格填补之前位置，保持对齐
    printf("│ 最高GPA:  %-33.2f         │\n", maxGpa);
    printf("│    学号: %-12s 姓名: %-16s │\n", maxStudent->id, maxStudent->name);
    printf("│                                             │\n");
    printf("│ 最低GPA:  %-33.2f         │\n", minGpa);
    printf("│    学号: %-12s 姓名: %-16s │\n", minStudent->id, minStudent->name);
    printf("└─────────────────────────────────────────────┘\n");

    // 统计GPA分布区间
    // 优秀，良好，中等，较差
    int excellent = 0, good = 0, average_count = 0, poor = 0;
    current = head;
    while (current != NULL) {
        if (current->gpa >= 3.5) excellent++;
        else if (current->gpa >= 3.0) good++;
        else if (current->gpa >= 2.0) average_count++;
        else poor++;
        current = current->next;
    }

    printf("\nGPA分布情况:\n");
    // 强制转换为float进行百分比计算
    printf("  优秀 (3.5-4.0): %d人 (%.1f%%)\n", excellent, (float)excellent/count*100);
    printf("  良好 (3.0-3.5): %d人 (%.1f%%)\n", good, (float)good/count*100);
    printf("  中等 (2.0-3.0): %d人 (%.1f%%)\n", average_count, (float)average_count/count*100);
    printf("  较差 (0.0-2.0): %d人 (%.1f%%)\n", poor, (float)poor/count*100);
}


// ==================== 文件操作函数实现 ====================

// 保存数据
// 原理：直接将结构体二进制数据块写入文件
void saveToFile() {
    // "wb" 模式：二进制写入，如果文件不存在则创建
    FILE *file = fopen(DATA_FILE, "wb");
    if (file == NULL) {
        printf(" [错误] 无法打开文件进行写入！\n");
        return;
    }

    Student *current = head;
    while (current != NULL) {   // 循环保存
        // fwrite(数据指针, 单个大小, 数量, 文件指针)
        fwrite(current, sizeof(Student), 1, file);

        // 指向下一个节点
        current = current->next;
    }

    fclose(file);
}

// 加载数据
// 原理：程序启动时，从二进制文件中读取结构体，重建链表
void loadFromFile() {
    // "rb" 模式：二进制读取
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        return; // 文件不存在，说明是首次运行
    }

    Student temp;
    // 循环读取，直到文件结束
    while (fread(&temp, sizeof(Student), 1, file) == 1) {
        // 使用读取到的数据创建新节点
        Student *newStudent = createStudent(temp.id, temp.name, temp.major, temp.gpa);

        if (newStudent != NULL) {
            // 将读取到的节点插入到链表中,这里用头插法，顺序会反过来，
            // 如果介意顺序，可以用尾插法，但头插法代码最简单
            newStudent->next = head;
            head = newStudent;
        }
    }

    fclose(file);
}
