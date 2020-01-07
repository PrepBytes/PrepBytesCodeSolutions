#include <stdio.h>
int main()
{
  int t; // variable for storing test cases
  scanf("%d",&t); // initialize test case variable
  // start test case loop
  while(t--)
  {
    // variable n to store the input, sum and rem for calculation
    int n,sum=0,rem;
    scanf("%d",&n);
    
    //loop to get all the factors and add them
    for(int i=1;i<=n/2;i++)
    {
      rem=n%i;
      if(rem==0)
        sum+=i;
    }
    
    //if the sum is equal to n, print true else false
    if(sum==n)
      printf("true\n");
    else
      printf("false\n");
  }
  return 0;
}
