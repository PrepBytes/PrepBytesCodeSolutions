Prerequisite: Digit Dynamic Programming.
If we think every number as a list of digits. Like N = X_1X_2X_3X_4....
Let’s consider the number as a sequence of digits. Let’s name the sequence **sq**. Initially, **sq** is empty. We’ll try to add new digits from left to right to build the sequence. In each recursive call, we’ll place a digit in our current position and will call recursively to add a digit in the next position. But can we place any of the digits from **0** to **9** in our current position? Of course not, because we need to make sure that the number is not getting larger than **b**.
**Information Needed to place a digit at current place -**

 - The first thing which is needed is the position of the current place where we are going to place the digit.
 - We need to keep track of the sum of digits of the non-prime index and prime index
 - We need a to know if we place a digit called **d** at the current position then our number should be less than or equal to the upper range. How to find this?
 Let’s say during the building of the sequence, currently we are at position  **pos**. We have already placed some digits in position from  **1**  to  **pos-1**. So now we are trying to place a digit at the current position  **pos**. If we knew the whole sequence we have built so far till position  **pos-1**  then we could easily find out which digits we can place now. But how?
You can see that in the sequence  **sq**  the left-most digit is actually the most significant digit. And the significance gets decreased from left to right. So if there exist any position  **t**  (1<=t<pos) where sq[t] < b[t] then we can place any digit in our current position. Because the sequence has already become smaller than  **b**  no matter which digit we place in the later positions. Note, b[t] means the digit at position  **t**  at number  **b**.
But if there was no  **t**  that satisfy that condition then at position  **pos**, we can’t place any digit greater than b[pos]. Because then the number will become larger than  **b**.
 - Now to deal with leading zeros like here the numbers which will be created will be like 001, 002, 003,... now if we find non-prime index sum and prime index sum according to this then we will get the wrong answer because the numbers are actually 1, 2, 3, etc. To deal with this problem we need a flag which can tell us whether we have got any non-zero digit so far or not. If we have got it means we can place zero also at the current position otherwise we can't.
 - Now since there can be some leading zeros so to find the exact position of the current position we need an extra thing which can tell us where we have placed the first non-zero digit. Because only according to that we can find a non-prime index and prime index sum.

  **So there are 6 dp states needed to solve this problem.**
  Now to reduce the time and space complexity instead of storing prime-index sum and non-prime index sum we can store them after doing modulo with D.
  Because (A * B ) % M = ((A%M) * (B % M ))%M
  **Calculating Time complexity**
  Since the upper range of the number is 10$^{18}$ so there can be 18 positions. Prime index sum modulo D and non-prime index sum can be upto D.The index where a non-zero digit is placed can be upto 18. To check the upper bound we need a flag i,e 2. For finding whether we have placed any non-zero digit so far or not we need another flag i,e 2. So The time complexity will be O(18 * 30 * 30 * 2 * 18 * 2) =  O(1166400). Space complexity will be the same.
