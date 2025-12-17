#include <stdio.h>

#include "student.h"

int main() {
    int choice;

    // 程序启动时从文件加载数据
    loadFromFile();

    // 显示欢迎界面
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║     欢迎使用学生信息管理系统 v1.0     ║\n");
    printf("╚════════════════════════════════════════╝\n");

    // 主循环
    while (1) {
        // 显示Menu和提示
        displayMenu();
        printf("\n请输入您的选择 [0-8]: ");

        // 如果数据无效，则重新循环
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') {}    // 清除缓冲区
            printf("\n [错误] 输入无效！请输入数字 0-8\n");
            continue;
        }

        // 清除缓冲区
        while (getchar() != '\n') {}
        printf("\n");

        switch (choice) {
            case 1:
                addStudent();               // 按下1：添加学生信息
                break;
            case 2:
                displayAllStudents();       // 按下2：显示所有学生信息
                break;
            case 3:
                searchStudent();            // 按下3：搜索学生信息(输入学号)
                break;
            case 4:
                updateStudent();            // 按下4：修改学生信息(输入学号)
                break;
            case 5:
                deleteStudent();            // 按下5：删除学生(输入学号)
                break;
            case 6:
                sortStudents();             // 按下6：给学生排序(根据GPA)
                break;
            case 7:
                calculateStatistics();      // 按下7：计算并显示统计信息
                break;
            case 8:
                saveToFile();               // 按下8：保存数据到student.dat文件
                printf(" 数据已成功保存到文件！\n");
                break;
            case 0:                         // 按下0：退出程序
                saveToFile();
                freeAllStudents();
                printf("╔════════════════════════════════════════╗\n");
                printf("║       感谢使用，数据已保存！           ║\n");
                printf("╚════════════════════════════════════════╝\n");
                return 0;   // 结束整个程序
            default:
                printf("[错误] 无效选择！请输入 0-8 之间的数字\n");
        }

        printf("\n 按回车键继续...");
        getchar();   // 等待用户按回车
    }

}