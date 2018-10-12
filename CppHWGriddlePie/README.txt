Question 1:
    Pi Estimate values gotten for:
        10: 3.52000
        100: 3.181200
        1000: 3.145544
        10,000: 3.141990

Question 2:
    Run time of the function for values above using time ./pi:
    Seeing as my code is primarily a nested for loop, bets are the total complecity is O(N^2).
        10: 0m0.004s
        100: 0m0.005s
        1000: 0m0.010s
        10,000: 0m0.351s
        I expected it to get significantly bigger as the values increased, but not at the rate it did. 
        Based on the algorithmic complecity, I would have expected the difference between 100 to 1000 to be larger, but also the difference between 1000 to 10000 to be smaller. Seeing as I effectively can't run 1000000, bets are I am underestimating how complex it can get with larger inputs.
Question 3:
    Pi Estimates:
        10: 3.520000
        100: 3.181200
        1000: 3.145544 

    Run Times:
        10: 0m0.004s
        100: 0m0.005s
        1000:  0m0.009s

    My results seem to be the same after the conversion. The runtime may be a bit faster after the conversion, but perhaps not by much. I wasn't able to get it to take in the values directly during compile time, so it's possible that though the general structure compiles faster, since it effectively has to go through the same process again during actual run time, it effectively negates any positive change in speed that might happen. The compilation process was a PAIN, since I couldn't just print out the result of gridpi2 directly to the system in main, and gridpi2 also didn't want to start off by compiling a value.