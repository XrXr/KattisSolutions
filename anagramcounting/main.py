import sys
from collections import Counter
from math import factorial as fac

lines = sys.stdin.readlines()
lines = [l.strip() for l in lines]
for l in lines:
    full = fac(len(l))
    counter = Counter(l)
    for count in counter.values():
        full //= fac(count)
    print(full)
