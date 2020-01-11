#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    // Test case loop
    while(t-->0)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        int i;
        // Taking array as input
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        // Assigning last element as current leader
        int curr_leader=arr[n-1];
        printf("%d ",curr_leader);

        // Checking each element with the current leader, and updating the leader when required
        for(i=n-2;i>=0;i--)
        {
            if(curr_leader<=arr[i])
            {
                curr_leader=arr[i];
                // Printing the current leader
                printf("%d ",curr_leader);
            }
        }
        printf("\n");
    }
    return 0;
}
