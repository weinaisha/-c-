#include <stdio.h>
#include <stdlib.h>

int main() {
    int kind, vexnum, *arcnum, *IncInfo;
    char buff[255];
    char StrLine[1024];
    FILE* fp = NULL;
    fp = fopen("TestData_DG.txt", "a+");
    if(fp) {
        fscanf(fp, "%d\n", &kind);
        printf("图类型=%d\n", kind);
        // fscanf(fp, "%d", vexnum);
        // printf("顶点数=%d\n", vexnum);
        // fscanf(fp, "%d", arcnum);
        // printf("弧数%d\n", *arcnum);
        // fscanf(fp, "%d", IncInfo);
        // printf("弧是否带有其他信息%d\n", *IncInfo);
    }
    fclose(fp);
    // fp = NULL;
    
    return 0;
}