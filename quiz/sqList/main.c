#include <stdio.h>
#include "./sqList.c"

void create(SqList *s, int n) {
    elementType a;
    int k = 0;
    InitSqList(s);
    while (k < n )
    {
        scanf("%d", &a);
        Insert(s, 1, a);
        k++;
    }
    printf("输入线性表：");
    for (k = 0; k < s->length; k++)
    {
        printf("%d ", s->data[k]);
    }
    printf("\n");
}

/**
 * question 1
 * n次遍历找出最小的元素，记录下标
 * 最小元素替换为最后一个元素值
 * 删除最后一个元素 length--
*/
elementType case1() {
    SqList s;
    int i, min, minIndex = 0;
    create(&s, 10);
    if(s.length == 0) return -1;
    min = s.data[0];
    for (i = 1; i < s.length; i++)
    {
        if(min > s.data[i]) {
            min = s.data[i];
            minIndex = i;
        }   
    }
    printf("最小元素：%d\n", min);
    s.data[minIndex] = s.data[s.length - 1];
    s.length--;
    printf("输出线性表：");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
    return s.data[minIndex];
}

/**
 * question 2 所有元素逆序
 * 取第一个元素i和最后一个元素j交换值
 * i++, j--, i<j; 执行第二步操作
*/
void case2() {
    SqList s;
    elementType temp;
    int i = 0, j;
    create(&s, 10);
    j = s.length - 1;
    while (i < j)
    {
        temp = s.data[i];
        s.data[i++] = s.data[j];
        s.data[j--] = temp;
    }
    printf("输出线性表：");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

/**
 * question 3
 * 时间复杂度为O(n)
 * 解法一：用k记录不等于x的元素个数，边扫描边记录k，并将不等于x的元素向前移动k个位置，最后修改L的长度
 * 解法二：用k记录等于x的元素个数，边扫描边记录k，并将不等于x的元素向前移动k个位置，最后修改L的长度
*/
void case3(elementType e) {
    SqList s;
    elementType temp;
    int i = 0, j = 0;
    create(&s, 10);
    for (i = 0; i < s.length; i++)
    {
        if (s.data[i] != e)
        {
            s.data[j] = s.data[i];
            j++;   
        }
    }
    s.length = j; 
    printf("输出线性表：");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

/**
 * question 4，question 5 题意错误 s t为数值不是位置 ？
 * 判断边界 s<t && s>=1 && t<=n(n为顺序表长度)
 * gap = t-s + 1(删除元素包含s t)
 * r[s] = r[s] + gap
 * s++; s<= t
*/

/**
 * question 6 思想可，待实现
 * 有序顺序表删除重复值，去重
 * O(n^2)
 * 相邻两两比较，if重复整体向前移动一个元素
 * 无序表用散列表实现
*/

/**
 * question 7
 * 两个有序顺序表合并为一个有序顺序表 两两比较表头
*/
void case7() {
    SqList A;
    SqList B;
    SqList C;
    int i = 0, j = 0, k = 0;
    create(&A, 3);
    create(&B, 3);
    InitSqList(&C);
    if (A.length + B.length > MAXSIZE) return;
    while (i < A.length && j < B.length)
    {
        if(A.data[i] <= B.data[j]) C.data[k++] = A.data[i++];
        else
        {
            C.data[k++] = B.data[j++];
        }
    }
    if(i < A.length) {
        for (; i < A.length; i++)
        {
            C.data[k++] = A.data[i];
        }
    }
    if(j < B.length) {
        for (; j < B.length; j++)
        {
            C.data[k++] = B.data[j];
        }
    }
    C.length = k;
    printf("输出线性表：");
    for (i = 0; i < C.length; i++)
    {
        printf("%d ", C.data[i]);
    }
    printf("\n");
}

/**
 * question 8
 * 把两个顺序表A,B存储在一维数组中(a1,a2,b1,b2),两个顺序表位置互换
 * =>(b1,b2,a1,a2)
 * 笨方法：找到B表起止位置遍历放入辅助表C，找到A表起止位置遍历放入辅助表C，赋值给原一维数组
 * 不借助辅助空间实现
 * 一维数组所有元素逆置，B表起止位置元素逆置，A表起止位置元素逆置
*/
void case8() {
    SqList A;
    SqList B;
    SqList C;
    int i = 0, m = 0, n = 0, mid;
    elementType temp;
    create(&A, 3);
    create(&B, 3);
    m = A.length;
    n = B.length;
    InitSqList(&C);
    printf("包含两个顺序表AB的一维数组:");
    for (i = 0; i < m + n; i++)
    {
        if(i < m) C.data[i] = A.data[i];
        else
        {
            C.data[i] = B.data[i - m];
        }
        printf("%d ", C.data[i]);
    }
    C.length = m + n;
    mid = (m + n) / 2;
    for (i = 0; i < mid; i++) {
        temp = C.data[i];
        C.data[i] = C.data[m + n - 1 - i];
        C.data[m + n - 1 - i] = temp;
    }
    for (i = 0; i < n/2; i++) {
        temp = C.data[i];
        C.data[i] = C.data[n - 1 - i];
        C.data[n - 1 - i] = temp;
    }
    for (i = 0; i < m/2; i++) {
        temp = C.data[n+i];
        C.data[n+i] = C.data[m + n - 1 - i];
        C.data[m + n - 1 - i] = temp;
    }
    printf("\n输出线性表：");
    for (i = 0; i < C.length; i++)
    {
        printf("%d ", C.data[i]);
    }
    printf("\n");
}

/**
 * question 9
 * 折半查找x, 
 * 查找成功：r[i] == x 交换 r[i] = r[i+1]; r[i+1]=x
 * 不存在：移动元素插入x
*/
void case9(int x) {
    SqList r;
    create(&r, 7);
    int low = 0, high = r.length - 1, mid = 0, k;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(r.data[mid] == x) break;
        if(r.data[mid] < x) low = mid + 1;
        else
        {
            high = mid - 1;
        }  
    }
    if(r.data[mid] == x && mid != r.length - 1) {
        r.data[mid] = r.data[mid + 1];
        r.data[mid + 1] = x;
    }
    if(low > high) {
        for (k = r.length - 1; k > high; k--)
        {
            r.data[k+1] = r.data[k];
        }
        r.data[k + 1] = x;
        r.length++;
    }
    printf("\n输出线性表：");
    for (k = 0; k < r.length; k++)
    {
        printf("%d ", r.data[k]);
    }
    printf("\n");
}

/**
 * question 10 ?借借助r[0]
*/

/**
 * question 11? 统考
*/

/**
 * question 13 O(n^2) ？统考
 * n = 已知整数数组长度
 * for i = 1; i<=n i++ 遍历查找
 * for 遍历已知数组
*/

int main() {
    // printf("例题1：删除的最小元素，空出位置油最后一个元素补位\n");
    // case1();
    // printf("例题2：顺序表所有元素逆序\n");
    // case2();
    // printf("例题3：删除顺序表中所有值为%d的元素\n", 12);
    // case3(12);
    // printf("例题7：合并两个有序顺序表为一个有序顺序表\n");
    // case7();
    // case8();
    // case9(5);
    return 0;
}


