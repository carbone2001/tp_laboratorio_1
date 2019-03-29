float fsumar(float x, float y)
{
    float rta;
    rta=x+y;

    return rta;
}
float frestar(float x, float y)
{
    float rta;
    rta=x-y;

    return rta;
}
float fdivision(float x, float y)
{
    float rta;
    rta=(float)x/y;
    return rta;
}

float fmultiplicacion(float x, float y)
{
    float rta;
    rta=x*y;

    return rta;
}

int ffactorial(int x)
{
    int i;
    int fact;
    fact=x;

    if(x<0)
    {
        fact=(-1);
    }
    else if(x==0)
    {
        fact=1;
    }
    else
    {
        int i;
        int fact;
        fact=x;
        for(i=1;i<x;i++)
        {
            fact=fact*i;
        }
    }

    for(i=1;i<x;i++)
    {
        fact=fact*i;
    }

    return fact;
}

