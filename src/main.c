#include <stdio.h>

#include "student.h"

int main() {
    int choice;

    // 程序启动时从文件加载数据
    loadFromFile();

    printf("\n╔════════════════════════════════════════╗\n");
    printf("║     欢迎使用学生信息管理系统 v1.0     ║\n");
    printf("╚════════════════════════════════════════╝\n");

    while (1) {
        displayMenu();
        printf("\n请输入您的选择 [0-8]: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') {}
            printf("\n 输入无效！请输入数字 0-8\n");
            continue;
        }

        // 清空缓冲区
        while (getchar() != '\n') {}

        printf("\n");

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                calculateStatistics();
                break;
            case 8:
                saveToFile();
                printf(" 数据已成功保存到文件！\n");
                break;
            case 0:
                saveToFile();
                freeAllStudents();
                printf("╔════════════════════════════════════════╗\n");
                printf("║       感谢使用，数据已保存！           ║\n");
                printf("╚════════════════════════════════════════╝\n");
                return 0;   // 结束整个程序
            default:
                printf(" 无效选择！请输入 0-8 之间的数字\n");
        }

        printf("\n 按回车键继续...");
        getchar();   // 等待用户按回车
    }

}