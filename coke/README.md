Key observations:
There are only two ways of saving coins:
 - Paying one 10 and one 3, then paying a 5 and three 1's uses 1 less coin than
   using a 10 and 8 1's
 - Paying a 5 and three 1's twice is better than paying two 5's then eight 1's.
   This saves 2 coins.

Both efficient methods return the same amount of change as their inefficient
counter part.
To find out the least amount of coins required, we find the amount of coins
that would be spent when not using any coin saving tricks, and then "swap" the
occurrences of inefficient methods with their efficient counter part.
The amount of saving is kept track when swapping.

An interesting thing about the solution is that since there are no tricks which
correspond to buying with one 5 and three 1's, the number of purchases for
that type is not kept track.