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
    printf("�������Ա�");
    for (k = 0; k < s->length; k++)
    {
        printf("%d ", s->data[k]);
    }
    printf("\n");
}

/**
 * question 1
 * n�α����ҳ���С��Ԫ�أ���¼�±�
 * ��СԪ���滻Ϊ���һ��Ԫ��ֵ
 * ɾ�����һ��Ԫ�� length--
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
    printf("��СԪ�أ�%d\n", min);
    s.data[minIndex] = s.data[s.length - 1];
    s.length--;
    printf("������Ա�");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
    return s.data[minIndex];
}

/**
 * question 2 ����Ԫ������
 * ȡ��һ��Ԫ��i�����һ��Ԫ��j����ֵ
 * i++, j--, i<j; ִ�еڶ�������
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
    printf("������Ա�");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

/**
 * question 3
 * ʱ�临�Ӷ�ΪO(n)
 * �ⷨһ����k��¼������x��Ԫ�ظ�������ɨ��߼�¼k������������x��Ԫ����ǰ�ƶ�k��λ�ã�����޸�L�ĳ���
 * �ⷨ������k��¼����x��Ԫ�ظ�������ɨ��߼�¼k������������x��Ԫ����ǰ�ƶ�k��λ�ã�����޸�L�ĳ���
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
    printf("������Ա�");
    for (i = 0; i < s.length; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

/**
 * question 4��question 5 ������� s tΪ��ֵ����λ�� ��
 * �жϱ߽� s<t && s>=1 && t<=n(nΪ˳�����)
 * gap = t-s + 1(ɾ��Ԫ�ذ���s t)
 * r[s] = r[s] + gap
 * s++; s<= t
*/

/**
 * question 6 ˼��ɣ���ʵ��
 * ����˳���ɾ���ظ�ֵ��ȥ��
 * O(n^2)
 * ���������Ƚϣ�if�ظ�������ǰ�ƶ�һ��Ԫ��
 * �������ɢ�б�ʵ��
*/

/**
 * question 7
 * ��������˳���ϲ�Ϊһ������˳��� �����Ƚϱ�ͷ
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
    printf("������Ա�");
    for (i = 0; i < C.length; i++)
    {
        printf("%d ", C.data[i]);
    }
    printf("\n");
}

/**
 * question 8
 * ������˳���A,B�洢��һά������(a1,a2,b1,b2),����˳���λ�û���
 * =>(b1,b2,a1,a2)
 * ���������ҵ�B����ֹλ�ñ������븨����C���ҵ�A����ֹλ�ñ������븨����C����ֵ��ԭһά����
 * �����������ռ�ʵ��
 * һά��������Ԫ�����ã�B����ֹλ��Ԫ�����ã�A����ֹλ��Ԫ������
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
    printf("��������˳���AB��һά����:");
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
    printf("\n������Ա�");
    for (i = 0; i < C.length; i++)
    {
        printf("%d ", C.data[i]);
    }
    printf("\n");
}

/**
 * question 9
 * �۰����x, 
 * ���ҳɹ���r[i] == x ���� r[i] = r[i+1]; r[i+1]=x
 * �����ڣ��ƶ�Ԫ�ز���x
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
    printf("\n������Ա�");
    for (k = 0; k < r.length; k++)
    {
        printf("%d ", r.data[k]);
    }
    printf("\n");
}

/**
 * question 10 ?�����r[0]
*/

/**
 * question 11? ͳ��
*/

/**
 * question 13 O(n^2) ��ͳ��
 * n = ��֪�������鳤��
 * for i = 1; i<=n i++ ��������
 * for ������֪����
*/

int main() {
    // printf("����1��ɾ������СԪ�أ��ճ�λ�������һ��Ԫ�ز�λ\n");
    // case1();
    // printf("����2��˳�������Ԫ������\n");
    // case2();
    // printf("����3��ɾ��˳���������ֵΪ%d��Ԫ��\n", 12);
    // case3(12);
    // printf("����7���ϲ���������˳���Ϊһ������˳���\n");
    // case7();
    // case8();
    // case9(5);
    return 0;
}


