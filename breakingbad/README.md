#Postmortem

This question took me about an entire day to do. While I do feel a little
embarrassed, it is a tricky question.

I first tried starting with full list of items for both shoppers and removing
from the sets as rules are read in. This meant for a rule `a b`, remove `a`
from Walter's set and `b` from Jesse's set. This approached doesn't seem
obviously wrong; a good amount of thinking is required to come up with a test
case which breaks this approach.

After thinking about the question some more, I made an important observation.
For a word `a`, every other element in rules which contain `a` must be on a different shopping list than `a`. The observation is not much deeper than the definition of the problem, however looking at rules as a map of string to list
is much more helpful.

At this point I came up with an algorithm which checks for rule violation in
the image of the map. I quickly abandoned the idea since it has a worst case of
n^2. Abandoning the algorithm proved to be a big mistake, since my AC solution
also has a worst case of n^2. What made it worse is that I also abandoned the
idea of looking at the rules as a map, and went off to try different (wrong)
things, in attempt to come up with a linear time solution. This wandering
wasted at least 4 hours.

In summary, if the solution is very simple, spend some time coming up with
test cases which could potentially prove the solution to be wrong. Also, when
a solution is obviously more correct than every other solution so far,
implement it, even if it might be too slow. Sacrificing a submission is not
a big deal; the fast solution is probably in the same direction.