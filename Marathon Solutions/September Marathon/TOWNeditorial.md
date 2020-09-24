The problem is to find the maximum sum of prefix sum of path from  **u** to **v**.
While moving from node **u** to node **v**, calculate the prefix sum in the path and add all the elements of prefix
sum array.

The naive solution is very simple. Calcuate the sum of prefix sums of every pair of nodes, **u** and **v**. Then find
the maximum sum.


Prerequisites: Convex HUll, Centroid decomposition



Solution:

If you do not have any idea of Convex Hull or centroid decomposition please read the articles on Centroid
decomposition and convex hull first.

One of the solution of the problem is using centroid decomposition. Our main task is to
compute all paths through each centroid.

Conside a path from vertex **a** to vertx **b** going through a vertex **u** which is a ancestor of both
the vertices in the centroid decomposition tree. Let the sequence of number on path from **a** to **u**
is [a1, a2, a3...] and the sequence of numbers on path from **u** to **b** is [b1, b2 ...]. So our task
is to find the sum of prefix sum. So the sum of prefis sum looks like this:
 a_1 + (a_1+a_2) + (a_1+a_2+a_3) +.... + (a_1+a_2+..a_n) = a_1*n + a_2*(n-1) + ... + a_n.

So lets consider **i** have sum of prefix sum from **a_1** to **a_k** as **sum1** and **a_k+1** to **a_n** as **sum2**.
So the total sum will be sum = sum1 + sum2 + sum1*(n-k). As the sum1 will be present in prefix array
of every element of sum2.

So we can do similarly for vertices **a** to **u** and **u** to **b**.

Here is one more observation if **u** and **b** is fixed the **a** can be represented by a linear function
and find the maximum sum. This can be done by Li Chao tree or Convex Hull.


Time Complexity: **O(N log N)**, centroid decomposition and Convex Hull both taka N log N time .
