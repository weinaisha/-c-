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
        // printf("������%d\n", vexnum);
        // fscanf(fp, "%d", &arcnum);
        // printf("����%d\n", arcnum);
        // fscanf(fp, "%d", &IncInfo);
        // printf("���Ƿ����������Ϣ%d\n", IncInfo);
    }
    fclose(fp);
    fp = NULL;
    
    return 0;
}