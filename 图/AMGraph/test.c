#include <stdio.h>

int main() {
    int kind, vexnum, arcnum, IncInfo;
    char buff[255];
    FILE* fp = NULL;
    fp = fopen("TestData_DG.txt", "a+");
    if(fp) {
        // fprintf(fp, "%s\n", 12);
        fscanf(fp, "%s\n", &buff);
        printf("%s\n", buff);
        fscanf(fp, "%s\n", &buff);
        printf("%s\n", buff);
        fscanf(fp, "%s\n", &buff);
        printf("%s\n", buff);
        fgets(buff, 255, fp);
        printf("%s\n", buff);
        // fscanf(fp, "%d", &vexnum);
        // printf("顶点数%d\n", vexnum);
        // fscanf(fp, "%d", &arcnum);
        // printf("弧数%d\n", arcnum);
        // fscanf(fp, "%d", &IncInfo);
        // printf("弧是否带有其他信息%d\n", IncInfo);
    }
    fclose(fp);
    fp = NULL;
    
    return 0;
}