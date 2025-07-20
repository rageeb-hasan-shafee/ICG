int main()
{
  int i,j,k,l,x;
  i=3;
  j=11;
  l=20;
  k=30;
  if(i==3)
  {
    if (j<5)
    {
      println(i);
    }
    else
    {
      if (l>20)
      {
        println(k);
      }
      else{
        if(j%5==0)
        {
          println(j);
        }
        else
        {
          x = i + j;
          println(x);
        }
      }      
    }
    
  }
  else 
  {
    println(l);
  }

  return 0;
}