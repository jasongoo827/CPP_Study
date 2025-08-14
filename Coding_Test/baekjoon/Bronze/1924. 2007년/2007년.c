int main()
{
    char *dayOfTheWeek[7]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int date[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y;

    scanf("%d %d", &x, &y);

    for(int i=0;i<x-1;i++){
        y+=date[i];
    }
    printf("%s", dayOfTheWeek[y%7]);


    return 0;
}