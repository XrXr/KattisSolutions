#!/usr/bin/python

import os
import subprocess
from subprocess import PIPE, TimeoutExpired

def join(a):
    return os.path.join("tests", a)

for e in sorted(os.listdir("tests")):
    if e[-2::] == "in":
        p = subprocess.Popen("a.out", stdin=PIPE, stdout=PIPE, universal_newlines=True)
        with open(join(e), "r") as f:
            out = ""
            try:
                out, _ = p.communicate(f.read(), timeout=15)
            except TimeoutExpired:
                print(e, "failed, timeout")
                p.kill()
                continue
            with open(join(e[0:-2] + "ans"), "r") as af:
                if af.read() != out:
                    print(e, "failed, wrong answer")
                else:
                    print(e, "passed")
        p.kill()

