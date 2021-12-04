#include<stdio.h>
#include<stdlib.h>
int *allocate(int);
char *allocate1(int);
int **allocate2(int,int);
char **allocate3(int,int);
int check(int**,int**,int,int,int,int);
int check2(int**,int **,int,int,int,int);
int call_check(int **,int **,int,int,int,int,int);
int call_check2(int **,int **,int,int,int,int,int);
int main()
{
int i,j,m,n,row,col,set=0,set1=0,set2=0,n_row,l=0,x=0,q,r,s,t,*a,*b,*c,*a1,*b1,*c1,count_rev=0,count_rev_final,count_irrev=0,count_irrev_final,count=0,flag=0;
float k,k1,k3;
int *rev,*irrev,**stoimat2,**stoimat,**elementary_mode,**elementary_mode2;
 printf("Enter the number of rows:-\n\n");
 scanf("%d",&row);
 printf("Enter the number of columns:-\n\n");
 scanf("%d",&col);
 stoimat2=allocate2((row*col),(row*col));
 stoimat=allocate2((row*col),(row*col));
 elementary_mode=allocate2((row*row),(row*row));
 elementary_mode2=allocate2((row*row),(row*row));
 a=allocate(col);
 b=allocate(col);
 c=allocate(col);
 a1=allocate(row);
 b1=allocate(row);
 c1=allocate(row);
 printf("Enter the elements of matrix row wise:- \n\n");
 for(i=0;i<row;i++)
   for(j=0;j<col;j++)
      scanf("%d",&stoimat[i][j]);
  for(i=0;i<row;i++)
  {
    for(j=0;j<row;j++)
     {
       if(i==j)
	  elementary_mode[i][j]=1;
       else
	   elementary_mode[i][j]=0;
     }
  }
 n_row=row;
 printf("\nEnter the number of reversible reaction:-\n");
 scanf("%d",&count_rev_final);
 printf("Calculation\n\n");
  for(j=0;j<col;j++)
  {
    rev=allocate(row*col);
    irrev=allocate(row*col);
    for(i=0;i<n_row;i++)
      {
	if(stoimat[i][j]==0)
	  continue;
	else
	 {
	   if(i>=0&&i<=(count_rev_final-1))
	   {
	     rev[l++]=i;
	   }
	   else if(i>=count_rev_final&&i<=(n_row-1))
	   {
	     irrev[x++]=i;
	   }

	 }
      }
    l--;
    x--;
    for(r=0;r<n_row;r++)
    {
      for(s=0;s<col;s++)
	 stoimat2[r][s]=0;
    }
    for(r=0;r<n_row;r++)
    {
      for(s=0;s<col;s++)
	 elementary_mode2[r][s]=0;
    }
    for(i=0;i<count_rev_final;i++)
    {
      if(count_rev_final==0)
      {
	break;
      }
      for(t=0;t<=l;t++)
      {
	 if(i!=rev[t]&&t!=l)
	      continue;
	 else if(i!=rev[t]&&t==l)
	   {
	     flag=1;
	     break;
	   }
	 else if(i==rev[t])
	    break;
       }

      if(flag==1)
       {
	   for(q=0;q<col;q++)
	       stoimat2[count][q]=stoimat[i][q];
	   for(r=0;r<row;r++)
	       elementary_mode2[count][r]=elementary_mode[i][r];
	 count++;
	 count_rev++;
       }
      else
	 continue;
      flag=0;
    }

    if(l>0)
    {
     for(r=0;r<=(l-1);r++)
     {
       for(s=(r+1);s<=l;s++)
       {
	  set1=call_check(elementary_mode2,elementary_mode,0,count,rev[r],rev[s],row);
	  set2=call_check2(elementary_mode2,elementary_mode,0,count,rev[r],rev[s],row);
	  if(set1==0||set2==0)
	   {

	     continue;
	   }
	  else
	   {
	     if(stoimat[rev[r]][j]>0&&stoimat[rev[s]][j]>0&&stoimat[rev[r]][j]>=stoimat[rev[s]][j])
	     {
	       k=((float)stoimat[rev[r]][j])/((float)stoimat[rev[s]][j]);
	       for(q=0;q<col;q++)
		{
		 a[q]=stoimat[rev[r]][q]-(k*stoimat[rev[s]][q]);
		 stoimat2[count][q]=a[q];
		}
	       for(q=0;q<row;q++)
	       {
		a1[q]=elementary_mode[rev[r]][q]-(k*elementary_mode[rev[s]][q]);
		elementary_mode2[count][q]=a1[q];
	       }

	    count_rev++;
	    count++;
	    }
	    else if(stoimat[rev[r]][j]>0&&stoimat[rev[s]][j]>0&&stoimat[rev[r]][j]<=stoimat[rev[s]][j])
	    {
	      k=((float)stoimat[rev[s]][j])/((float)stoimat[rev[r]][j]);
	      for(q=0;q<col;q++)
	       {
		a[q]=k*stoimat[rev[r]][q]-stoimat[rev[s]][q];
		stoimat2[count][q]=a[q];
	       }
	      for(q=0;q<row;q++)
	      {
	       a1[q]=k*elementary_mode[rev[r]][q]-elementary_mode[rev[s]][q];
	       elementary_mode2[count][q]=a1[q];
	      }
	     count_rev++;
	     count++;
	    }
	    else if(stoimat[rev[r]][j]<0&&stoimat[rev[s]][j]<0&&stoimat[rev[r]][j]>=stoimat[rev[s]][j])
	     {
	       k=((float)((-1)*stoimat[rev[s]][j]))/((float)((-1)*stoimat[rev[r]][j]));
	       for(q=0;q<col;q++)
	      {
		a[q]=k*stoimat[rev[r]][q]-stoimat[rev[s]][q];
		stoimat2[count][q]=a[q];
	       }
	     for(q=0;q<row;q++)
	      {
		a1[q]=k*elementary_mode[rev[r]][q]-elementary_mode[rev[s]][q];
		elementary_mode2[count][q]=a1[q];
	       }
	      count_rev++;
	      count++;
	     }
	   else if(stoimat[rev[r]][j]<0&&stoimat[rev[s]][j]<0&&stoimat[rev[r]][j]<=stoimat[rev[s]][j])
	   {
	      k=((float)((-1)*stoimat[rev[r]][j]))/((float)((-1)*stoimat[rev[s]][j]));
	      for(q=0;q<col;q++)
	      {
		a[q]=stoimat[rev[r]][q]-k*stoimat[rev[s]][q];
		stoimat2[count][q]=a[q];
	       }
	      for(q=0;q<row;q++)
	      {
		a1[q]=elementary_mode[rev[r]][q]-k*elementary_mode[rev[s]][q];
		elementary_mode2[count][q]=a1[q];
	      }
	    count_rev++;
	    count++;
	   }
	   else if(stoimat[rev[r]][j]>0&&stoimat[rev[s]][j]<0&&((-1)*stoimat[rev[s]][j])>=stoimat[rev[r]][j])
	    {
	       k=((float)((-1)*stoimat[rev[s]][j]))/((float)stoimat[rev[r]][j]);
	       for(q=0;q<col;q++)
	       {
		 a[q]=k*stoimat[rev[r]][q]+stoimat[rev[s]][q];
		 stoimat2[count][q]=a[q];
		}
	       for(q=0;q<row;q++)
	       {
		 a1[q]=k*elementary_mode[rev[r]][q]+elementary_mode[rev[s]][q];
		 elementary_mode2[count][q]=a1[q];
	       }
	     count_rev++;
	     count++;
	   }
	   else if(stoimat[rev[r]][j]>0&&stoimat[rev[s]][j]<0&&((-1)*stoimat[rev[s]][j])<=stoimat[rev[r]][j])
	    {
	      k=((float)stoimat[rev[r]][j])/((float)((-1)*stoimat[rev[s]][j]));
	      for(q=0;q<col;q++)
	      {
		a[q]=stoimat[rev[r]][q]+k*stoimat[rev[s]][q];
		stoimat2[count][q]=a[q];
	      }
	     for(q=0;q<row;q++)
	      {
		a1[q]=elementary_mode[rev[r]][q]+k*elementary_mode[rev[s]][q];
		elementary_mode2[count][q]=a1[q];
	      }
	     count_rev++;
	     count++;
	    }
	    else if(stoimat[rev[r]][j]<0&&stoimat[rev[s]][j]>0&&((-1)*stoimat[rev[r]][j])>=stoimat[rev[s]][j])
	    {
	      k=((float)((-1)*stoimat[rev[r]][j]))/((float)stoimat[rev[s]][j]);
	      for(q=0;q<col;q++)
	      {
		a[q]=stoimat[rev[r]][q]+k*stoimat[rev[s]][q];
		stoimat2[count][q]=a[q];
	      }
	     for(q=0;q<row;q++)
	     {
	       a1[q]=elementary_mode[rev[r]][q]+k*elementary_mode[rev[s]][q];
	       elementary_mode2[count][q]=a1[q];
	     }
	    count_rev++;
	    count++;
	   }
	  else if(stoimat[rev[r]][j]<0&&stoimat[rev[s]][j]>0&&((-1)*stoimat[rev[r]][j])<=stoimat[rev[s]][j])
	  {
	    k=((float)stoimat[rev[s]][j])/((float)((-1)*stoimat[rev[r]][j]));
	    for(q=0;q<col;q++)
	    {
	     a[q]=k*stoimat[rev[r]][q]+stoimat[rev[s]][q];
	    stoimat2[count][q]=a[q];
	     }
	    for(q=0;q<row;q++)
	    {
	     a1[q]=k*elementary_mode[rev[r]][q]+elementary_mode[rev[s]][q];
	    elementary_mode2[count][q]=a[q];
	     }
	   count_rev++;
	   count++;
	  }
	 }
	}
      }
     }
  flag=0;
  for(i=count_rev_final;i<n_row;i++)
    {
      for(t=0;t<=x;t++)
      {
	 if(i!=irrev[t]&&t!=x)
	      continue;
	 else if(i!=irrev[t]&&t==x)
	   {
	     flag=1;
	     break;
	   }
	 else if(i==irrev[t])
	    break;
       }
      if(flag==1)
       {
	   for(q=0;q<col;q++)
	       stoimat2[count][q]=stoimat[i][q];
	   for(q=0;q<row;q++)
	       elementary_mode2[count][q]=elementary_mode[i][q];
	 count++;
	 count_irrev++;
       }
      else
	 continue;
      flag=0;
    }
  if(l>=0&&x>=0)
  {
   for(r=0;r<=l;r++)
   {
    for(s=0;s<=x;s++)
    {
      set=call_check(elementary_mode2,elementary_mode,count_rev,count,rev[r],irrev[s],row);
      set2=call_check2(elementary_mode2,elementary_mode,count_rev,count,rev[r],irrev[s],row);
     if(set==0||set2==0)
      {

	continue;
       }
     else
     {
       if(stoimat[rev[r]][j]>0&&stoimat[irrev[s]][j]>0&&stoimat[rev[r]][j]>=stoimat[irrev[s]][j])
	  {
	    k3=((float)stoimat[rev[r]][j])/((float)stoimat[irrev[s]][j]);
	    for(q=0;q<col;q++)
	    {
	      c[q]=k3*stoimat[irrev[s]][q]-stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      c1[q]=k3*elementary_mode[irrev[s]][q]-elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]>0&&stoimat[irrev[s]][j]>0&&stoimat[rev[r]][j]<=stoimat[irrev[s]][j])
	  {
	    k3=((float)stoimat[irrev[s]][j])/((float)stoimat[rev[r]][j]);
	    for(q=0;q<col;q++)
	    {
	      c[q]=stoimat[irrev[s]][q]-k3*stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      c1[q]=elementary_mode[irrev[s]][q]-k3*elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]<0&&stoimat[irrev[s]][j]<0&&stoimat[rev[r]][j]>=stoimat[irrev[s]][j])
	  {
	    k3=((float)((-1)*stoimat[irrev[s]][j]))/((float)((-1)*stoimat[rev[r]][j]));
	    for(q=0;q<col;q++)
	    {
	     c[q]=stoimat[irrev[s]][q]-k3*stoimat[rev[r]][q];
	     stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	     c1[q]=elementary_mode[irrev[s]][q]-k3*elementary_mode[rev[r]][q];
	     elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]<0&&stoimat[irrev[s]][j]<0&&stoimat[rev[r]][j]<=stoimat[irrev[s]][j])
	  {
	    k3=((float)((-1)*stoimat[rev[r]][j]))/((float)((-1)*stoimat[irrev[s]][j]));
	    for(q=0;q<col;q++)
	    {
	      c[q]=k3*stoimat[irrev[s]][q]-stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      c1[q]=k3*elementary_mode[irrev[s]][q]-elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]>0&&stoimat[irrev[s]][j]<0&&((-1)*stoimat[irrev[s]][j])>=stoimat[rev[r]][j])
	  {
	    k3=((float)((-1)*stoimat[irrev[s]][j]))/((float)stoimat[rev[r]][j]);
	    for(q=0;q<col;q++)
	    {
	     c[q]=stoimat[irrev[s]][q]+k3*stoimat[rev[r]][q];
	     stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	     c1[q]=elementary_mode[irrev[s]][q]+k3*elementary_mode[rev[r]][q];
	     elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]>0&&stoimat[irrev[s]][j]<0&&((-1)*stoimat[irrev[s]][j])<=stoimat[rev[r]][j])
	  {
	    k3=((float)stoimat[rev[r]][j])/((float)((-1)*stoimat[irrev[s]][j]));
	    for(q=0;q<col;q++)
	    {
	      c[q]=k3*stoimat[irrev[s]][q]+stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	   for(q=0;q<row;q++)
	    {
	      c1[q]=k3*elementary_mode[irrev[s]][q]+elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]<0&&stoimat[irrev[s]][j]>0&&((-1)*stoimat[rev[r]][j])>=stoimat[irrev[s]][j])
	  {
	    k3=((float)((-1)*stoimat[rev[r]][j]))/((float)stoimat[irrev[s]][j]);
	    for(q=0;q<col;q++)
	    {
	      c[q]=k3*stoimat[irrev[s]][q]+stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      c1[q]=k3*elementary_mode[irrev[s]][q]+elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	  else if(stoimat[rev[r]][j]<0&&stoimat[irrev[s]][j]>0&&((-1)*stoimat[rev[r]][j])<=stoimat[irrev[s]][j])
	  {
	    k3=((float)stoimat[irrev[s]][j])/((float)((-1)*stoimat[rev[r]][j]));
	    for(q=0;q<col;q++)
	    {
	      c[q]=stoimat[irrev[s]][q]+k3*stoimat[rev[r]][q];
	      stoimat2[count][q]=c[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      c1[q]=elementary_mode[irrev[s]][q]+k3*elementary_mode[rev[r]][q];
	      elementary_mode2[count][q]=c1[q];
	    }
	    count++;
	    count_irrev++;
	  }

	}
      }
     }
    }
   
 if(x>0)
  {
   for(r=0;r<=(x-1);r++)
   {
     for(s=(r+1);s<=x;s++)
     {
      set=call_check(elementary_mode2,elementary_mode,count_rev,count,irrev[r],irrev[s],row);
     set2=call_check2(elementary_mode2,elementary_mode,count_rev,count,irrev[r],irrev[s],row);
     if(set==0||set2==0)
      {
	continue;
       }
      else
      {
       if(stoimat[irrev[r]][j]>0&&stoimat[irrev[s]][j]>0)
	 continue;
       else if(stoimat[irrev[r]][j]<0&&stoimat[irrev[s]][j]<0)
	 continue;
       else if(stoimat[irrev[r]][j]>0&&stoimat[irrev[s]][j]<0&&((-1)*stoimat[irrev[s]][j])<=stoimat[irrev[r]][j])
       {
	    k1=((float)stoimat[irrev[r]][j])/((float)((-1)*stoimat[irrev[s]][j]));
	    for(q=0;q<col;q++)
	    {
	      b[q]=stoimat[irrev[r]][q]+k1*stoimat[irrev[s]][q];
	      stoimat2[count][q]=b[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      b1[q]=elementary_mode[irrev[r]][q]+k1*elementary_mode[irrev[s]][q];
	      elementary_mode2[count][q]=b1[q];
	    }
	    count++;
	    count_irrev++;
	  }
       else if(stoimat[irrev[r]][j]>0&&stoimat[irrev[s]][j]<0&&((-1)*stoimat[irrev[s]][j])>=stoimat[irrev[r]][j])
	  {
	    k1=((float)((-1)*stoimat[irrev[s]][j]))/((float)stoimat[irrev[r]][j]);
	    for(q=0;q<col;q++)
	    {
	      b[q]=k1*stoimat[irrev[r]][q]+stoimat[irrev[s]][q];
	      stoimat2[count][q]=b[q];
	    }
	   for(q=0;q<row;q++)
	    {
	      b1[q]=k1*elementary_mode[irrev[r]][q]+elementary_mode[irrev[s]][q];
	      elementary_mode2[count][q]=b1[q];
	    }
	    count++;
	    count_irrev++;
	  }
       else if(stoimat[irrev[r]][j]<0&&stoimat[irrev[s]][j]>0&&((-1)*stoimat[irrev[r]][j])>=stoimat[irrev[s]][j])
	  {
	    k1=((float)((-1)*stoimat[irrev[r]][j]))/((float)stoimat[irrev[s]][j]);
	    for(q=0;q<col;q++)
	    {
	      b[q]=stoimat[irrev[r]][q]+k1*stoimat[irrev[s]][q];
	       stoimat2[count][q]=b[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      b1[q]=elementary_mode[irrev[r]][q]+k1*elementary_mode[irrev[s]][q];
	      elementary_mode2[count][q]=b1[q];
	    }
	    count++;
	    count_irrev++;
	  }
       else if(stoimat[irrev[r]][j]<0&&stoimat[irrev[s]][j]>0&&((-1)*stoimat[irrev[r]][j])<=stoimat[irrev[s]][j])
	  {
	    k1=((float)stoimat[irrev[s]][j])/((float)((-1)*stoimat[irrev[r]][j]));
	    for(q=0;q<col;q++)
	    {
	      b[q]=k1*stoimat[irrev[r]][q]+stoimat[irrev[s]][q];
	      stoimat2[count][q]=b[q];
	    }
	    for(q=0;q<row;q++)
	    {
	      b1[q]=k1*elementary_mode[irrev[r]][q]+elementary_mode[irrev[s]][q];
	      elementary_mode2[count][q]=b1[q];
	    }
	    count++;
	    count_irrev++;
	  }
	}
       }
     }
  }
 for(r=0;r<count;r++)
   for(s=0;s<col;s++)
     stoimat[r][s]=stoimat2[r][s];
 for(r=0;r<count;r++)
   for(s=0;s<row;s++)
      elementary_mode[r][s]=elementary_mode2[r][s];
 count_rev_final=count_rev;
  n_row=count;
    l=0;
    x=0;
    count=0;
    flag=0;
    count_rev=0;
    count_irrev=0;
 }
 printf("\n\nThe resultant matrix is as follows:");
  printf("\n\n");
  for(i=0;i<n_row;i++)
  {
    for(j=0;j<col;j++)
      printf("%d\t",stoimat[i][j]);
   printf("\n");
  }
 printf("\n\n");
 printf("\n\nThe resultant elementary mode matrix is as follows:");
  printf("\n\n");
  for(i=0;i<n_row;i++)
  {
    for(j=0;j<row;j++)
      printf("%d\t",elementary_mode[i][j]);
   printf("\n");
  }
 printf("\n\nThe Number of Elementary modes are:- %d\n",n_row);
return 0;
}


int *allocate(int n)
{
     int *in_data;
     int i;
     in_data=(int *)calloc(n,sizeof(int));
     return(in_data);
}
 char *allocate1(int n)
 {
     char *in_data;
     int i;
     in_data=(char *)calloc(n,sizeof(char));
     return(in_data);
 }
int **allocate2(int n,int m)
{
	int **in_data;
     int i;
     in_data=(int **)calloc(n,sizeof(int *));
     for(i=0;i<n;i++)
     in_data[i]=(int *)calloc(m,sizeof(int));
     return(in_data);
}
 char **allocate3(int n,int m)
 {
	char **in_data;
     int i;
     in_data=(char **)calloc(n,sizeof(char *));
     for(i=0;i<n;i++)
     in_data[i]=(char *)calloc(m,sizeof(char));
     return(in_data);
 }
 int call_check(int **elementary_mode2,int **elementary_mode,int m,int k,int j,int h,int i2)
 {
   int i,flag=0,s1;
   for(i=m;i<k;i++)
    {
	s1=check(elementary_mode2,elementary_mode,i,j,h,i2);
	if(s1==0)
	{
	  flag=1;
	  break;
	 }
	 else
	    continue;
     }
   if(flag==1)
       return 0;
   else
       return 1;
    }
 int call_check2(int **elementary_mode2,int **elementary_mode,int m,int k,int j,int h,int i2)
 {
   int i,flag=0,s1;
   for(i=m;i<k;i++)
    {
	s1=check2(elementary_mode2,elementary_mode,i,j,h,i2);
	if(s1==0)
	{
	  flag=1;
	  break;
	 }
	 else
	    continue;
     }
   if(flag==1)
       return 0;
   else
       return 1;
    }

 int check(int **a3,int **a8,int i,int j,int h,int i2)
 {
   int l,s,flag=0,*a4,*a5,*a6,*a7,k=0,m=0,n=0,o=0,count1=0,count2=0,count3=0,count4=0;
   a4=allocate(45);
   a5=allocate(45);
   a6=allocate(45);
   a7=allocate(45);
   for(l=0;l<i2;l++)
      {
	if(a3[i][l]!=0)
	       continue;
	else
	 {
	    a4[k++]=l;
	    count1++;
	 }
      }
   for(l=0;l<i2;l++)
      {
	if(a8[j][l]!=0)
	       continue;
	else
	  {
	    a5[m++]=l;
	    count2++;
	  }
      }
      for(l=0;l<i2;l++)
      {
	if(a8[h][l]!=0)
	       continue;
	else
	   {
	     a6[n++]=l;
	     count3++;
	   }
      }
      for(l=0;l<count2;l++)
       {
	 for(s=0;s<count3;s++)
	  {
	     if(a5[l]==a6[s])
	      {
		a7[o++]=a5[l];
		count4++;
	      }
	     else
	       continue;
	  }
	}
       s=0;
       for(l=0;l<count4;l++)
       {
	  for(s=0;s<count1;s++)
	   {
	      if(a7[l]!=a4[s])
		 continue;
	      else
		break;
	   }
	  if(s==count1)
	  {
	      flag=1;
	      break;
	  }
       }

     if(flag==1)
	 return 1;
     else
	 return 0;

 }

 int check2(int **a3,int **a8,int i,int j,int h,int i2)
 {
   int l,s,flag=0,*a4,*a5,*a6,*a7,k=0,m=0,n=0,o=0,count1=0,count2=0,count3=0,count4=0;
   a4=allocate(i2*i2);
   a5=allocate(i2*i2);
   a6=allocate(i2*i2);
   a7=allocate(i2*i2);
   for(l=0;l<i2;l++)
      {
	if(a3[i][l]!=0)
	       continue;
	else
	 {
	    a4[k++]=l;
	    count1++;
	 }
      }
   for(l=0;l<i2;l++)
      {
	if(a8[j][l]!=0)
	       continue;
	else
	  {
	    a5[m++]=l;
	    count2++;
	  }
      }
      for(l=0;l<i2;l++)
      {
	if(a8[h][l]!=0)
	       continue;
	else
	   {
	     a6[n++]=l;
	     count3++;
	   }
      }
      for(l=0;l<count2;l++)
       {
	 for(s=0;s<count3;s++)
	  {
	     if(a5[l]==a6[s])
	      {
		a7[o++]=a5[l];
		count4++;
	      }
	     else
	       continue;
	  }
	}
       s=0;
       for(l=0;l<count1;l++)
       {
	  for(s=0;s<count4;s++)
	   {
	      if(a4[l]!=a7[s])
		 continue;
	      else
		break;
	   }
	  if(s==count4)
	  {
	      flag=1;
	      break;
	  }
       }

     if(flag==1)
	 return 1;
     else
	 return 0;

 }
