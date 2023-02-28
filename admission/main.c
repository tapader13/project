#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, i = 0, j = 0, total = 0, dd = 0, k;
    char data[30][20];
    char answer[30][20];
    FILE *fp, *ans, *fwt;
    // student data entry
    fp = fopen("student2.txt", "r");
    if (fp == NULL)
    {
        printf("File is not find");
        return -1;
    }
    while (!feof(fp))
    {
        if (fgets(data[n], 20, fp) != NULL)
        {
            n++;
        }
    }
    fclose(fp);
    // answer sheet entry
    ans = fopen("ans.txt", "r");
    if (ans == NULL)
    {
        printf("File is not find");
        return -1;
    }
    while (!feof(ans))
    {
        if (fgets(answer[j], 20, fp) != NULL)
        {
            j++;
        }
    }
    fclose(ans);
    // comparing student data and answer and find total
    for (k = 2; k <= n; k++)
    {
        if (strlen(data[k]) > 2)
        {
            dd++;
        }
        else
        {
            if (strcmp(answer[k - 2], data[k]) == 0)
            {
                total++;
            }
        }
    }
    // total number in another file
    fwt = fopen("sum.csv", "a");
    fprintf(fwt, "Name :%sRoll :%sTotal :%d\n", data[0], data[1], total);
    fclose(fwt);
    return 0;
}