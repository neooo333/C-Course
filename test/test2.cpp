#include <stdio.h>


int main (){


    FILE *fp = fopen("data.txt", "w");

    fprintf(fp, "Hello World!\n");
    fprintf(fp, "Age = %d\n", 25);

    fclose(fp);



    return 0;
};