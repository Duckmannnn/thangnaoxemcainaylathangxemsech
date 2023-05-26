long long sanga[10000068];
void sang(long long k)
{  for(int i=1;i<=k;i++) sanga[i]=1;
    for (int i=2; i<=int(sqrt(k)); i++)
    {      if (sanga[i]==1)
        {          for (int j= 2; j<= k/i;j++)  {sanga[i * j] = 0;}        }
    }
    sanga[1]=0;
}
long long tuoc[1000009];
void sanguoc(long long k)
{
        for(long long i=1;i<=k/2;i++)
    {
        for(long long j=i;j<=k;j+=i)
        {
            tuoc[j]+=i;
        }
    }
            for(long long i=1;i<=k/2;i++)
    {
            tuoc[i]=tuoc[i]-i;
    }
}
