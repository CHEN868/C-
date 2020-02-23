/*
 * @Author: your name
 * @Date: 2020-02-21 15:37:42
 * @LastEditTime: 2020-02-21 17:58:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /c-lang/unit-9/10.c
 */
#include <stdio.h>
typedef struct student
{
    int num;
    double grade;
    struct student *next;
} student;
student *merge(student *a, student *b)
{
    //先合并，后排序
    student *head = a;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = b;

    student *pre;
    pre = head;
    while (pre->next != NULL)
    {
        a = pre->next;
        while (a != NULL)
        {
            if (pre->num > a->num)
            {
                int num = pre->num;
                double grade = pre->grade;
                pre->num = a->num;
                pre->grade = a->grade;
                a->num = num;
                a->grade = grade;
            }
            a = a->next;
        }
        pre = pre->next;
    }
    return head;
}
int main()
{
    student a[3] = {{1, 79}, {4, 36}, {5, 79}};
    for (int i = 0; i < 2; i++)
    {
        a[i].next = &a[i + 1];
    }

    student b[2] = {{2, 38}, {6, 98}};
    for (int i = 0; i < 1; i++)
    {
        b[i].next = &b[i + 1];
    }
    student *combine = merge(a, b);
    while (combine != NULL)
    {
        printf("%d -> %.2lf\n", combine->num, combine->grade);
        combine = combine->next;
    }

    return 0;
}