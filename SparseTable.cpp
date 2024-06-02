/*
                                                   *** Sparse Table ***
      -> for RMQ each query take O(1)
      -> used when there is no update otherwise need to construct sparse table from scratch again
      -> precomputation O(NlogN)
      -> work on all operation which is Idempotent a(.)a = a, e.g. min, max, gcd, and, or, etc
      -> for n<=1e7 no of row is 25 is more than enough
      -> we break n into power of two and store the value accordingly in the table
      -> for answering query we divind its range into TWO value in which overlapping is possible
         each range length is equal to the max power of two possible for length of range
*/
