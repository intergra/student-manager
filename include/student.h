#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50
#define MAX_MAJOR 50
#define MAX_ID 20
#define DATA_FILE "students.dat"

// Student结构体
typedef struct Student {
    char id[MAX_ID];
    char name[MAX_NAME];
    char major[MAX_MAJOR];
    float gpa;
    struct Student *next;
} Student;

// 全局变量声明
extern Student *head;


/**
 * @brief 显示界面函数
 */
void displayMenu();


// 链表操作函数声明
/**
 * 创建新的学生节点
 * @param id 学号
 * @param name 姓名
 * @param major 专业
 * @param gpa 绩点
 * @return 指向新创建学生节点的指针
 */
Student* createStudent(const char *id, const char *name, const char *major, float gpa);


/**
 * @brief 释放链表所有节点的内存
 */
void freeAllStudents();


/**
 * @brief 添加新学生
 */
void addStudent();


/**
 * @brief 显示所有学生信息
 */
void displayAllStudents();


/**
 * @brief 按学号或姓名搜索学生
 */
void searchStudent();


/**
 * @brief 修改学生信息
 */
void updateStudent();


/**
 * @brief 删除指定学生
 */
void deleteStudent();


/**
 * @brief 按GPA降序排序
 */
void sortStudents();


/**
 * @brief 计算并显示统计信息（平均分、最高分、最低分等）
 */
void calculateStatistics();


/**
 * @brief 将学生数据保存到文件
 */
void saveToFile();


/**
 * @brief 从文件加载学生数据
 */
void loadFromFile();

#endif // STUDENT_H
