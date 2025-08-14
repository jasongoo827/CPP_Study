int main()
{
    char s[21];
    int num, R;

    scanf("%d", &num);

    for(int i=0;i<num;i++){
        scanf("%d %s", &R, s);
        for(int j=0;s[j]!='\0';j++){
            for(int k=0;k<R;k++){
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
