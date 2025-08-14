int main()
{
    int N;
    double max=0.0;
    scanf("%d", &N);
    double score[N];
    double sum=0.0, avg;
    for(int i=0;i<N;i++){
        scanf("%lf", &score[i]);
    }
    for(int i=0;i<N;i++){
        if(max<score[i]) max=score[i];
    }
    for(int i=0;i<N;i++){
        sum+=score[i];
    }
    avg=((sum/max)*100.0)/(double)N;

    printf("%0.02lf", avg);
    return 0;
}