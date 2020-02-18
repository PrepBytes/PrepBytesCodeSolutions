import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static final int N =4;
    static final int M =4;
   static int maxValue= Integer.MIN_VALUE;
  static   long sum=0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int movie[][]=new int[N][M];
            for(int i=0;i<n;i++)
            {

                char ch = sc.next().charAt(0);
                int value=sc.nextInt();
                if(ch=='A')
                {
                    if(value==12)
                        movie[0][0]++;
                    else if(value==3)
                        movie[0][1]++;
                    else if(value==6)
                        movie[0][2]++;
                    else
                        movie[0][3]++;
                }
                if(ch=='B')
                {
                    if(value==12)
                        movie[1][0]++;
                    else if(value==3)
                        movie[1][1]++;
                    else if(value==6)
                        movie[1][2]++;
                    else
                        movie[1][3]++;
                }
                if(ch=='C')
                {
                    if(value==12)
                        movie[2][0]++;
                    else if(value==3)
                        movie[2][1]++;
                    else if(value==6)
                        movie[2][2]++;
                    else
                        movie[2][3]++;
                }
                if(ch=='D')
                {
                    if(value==12)
                        movie[3][0]++;
                    else if(value==3)
                        movie[3][1]++;
                    else if(value==6)
                        movie[3][2]++;
                    else
                        movie[3][3]++;
                }
            }
            ArrayList<Integer> arrayList = new ArrayList<>();
            ArrayList<Integer> res = new ArrayList<>();
            movieSelect(movie,arrayList,true,0,0,0);
            System.out.println(maxValue);
            res.add(maxValue);
            maxValue=Integer.MIN_VALUE;

            for(int i=0;i<res.size();i++)
                sum+=res.get(i);

        }
        System.out.println(sum);
    }

    private static void movieSelect(int[][] movie, ArrayList<Integer> select, boolean flag, int col, int row, int value)
    {
        int movieArr[][]= new int[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                movieArr[i][j]=movie[i][j];
        ArrayList<Integer> selectArr= new ArrayList<>(select);
        if(!flag)
        {
            selectArr.add(value);
            for(int i=0;i<N;i++)
                movieArr[i][col-1]=-1;
            for(int i=0;i<M;i++)
                movieArr[row][i]=-1;
        }
        if(selectArr.size()==4)
        {
            int sum=0;
            Collections.sort(selectArr);
            if(selectArr.get(3)==0)
                sum+= (-100);
            else
                sum+= selectArr.get(3)*100;
            if(selectArr.get(2)==0)
                sum+=(-100);
            else
                sum+= selectArr.get(2)*75;
            if(selectArr.get(1)==0)
                sum+=(-100);
            else
                sum+= selectArr.get(1)*50;
            if(selectArr.get(0)==0)
                sum+=(-100);
            else
                sum+= selectArr.get(0)*25;
            if(sum>maxValue)
                maxValue=sum;
            return;
        }
        for(int i=0;i<N;i++)
        {
            if(movieArr[i][col]!=-1)
            {
                movieSelect(movieArr,selectArr,false,col+1,i, movieArr[i][col]);
            }
        }
    }
}
