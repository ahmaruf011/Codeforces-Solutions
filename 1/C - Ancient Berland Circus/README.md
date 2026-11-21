<h2><a href="https://codeforces.com/contest/1/problem/C" target="_blank" rel="noopener noreferrer">1C — Ancient Berland Circus</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1C](https://codeforces.com/contest/1/problem/C) |

## Topics
`geometry` `math`

---

## Problem Statement

<div class="header"><div class="title">C. Ancient Berland Circus</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>64 megabytes</div><div class="input-file input-standard" style="font-weight: bold"><div class="property-title">input</div>stdin</div><div class="output-file output-standard" style="font-weight: bold"><div class="property-title">output</div>stdout</div></div><div><p>Nowadays all circuses in Berland have a round arena with diameter 13 meters, but in the past things were different.</p><p>In Ancient Berland arenas in circuses were shaped as a regular (equiangular) polygon, the size and the number of angles could vary from one circus to another. In each corner of the arena there was a special pillar, and the rope strung between the pillars marked the arena edges.</p><p>Recently the scientists from Berland have discovered the remains of the ancient circus arena. They found only three pillars, the others were destroyed by the time.</p><p>You are given the coordinates of these three pillars. Find out what is the smallest area that the arena could have.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The input file consists of three lines, each of them contains a pair of numbers –– coordinates of the pillar. Any coordinate doesn't exceed 1000 by absolute value, and is given with at most six digits after decimal point.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output the smallest possible area of the ancient arena. This number should be accurate to at least 6 digits after the decimal point. It's guaranteed that the number of angles in the optimal polygon is not larger than 100.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0030959828890645347" id="id002855034204042959" class="input-output-copier">Copy</div></div><pre id="id0030959828890645347">0.000000 0.000000<br>1.000000 1.000000<br>0.000000 1.000000<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0015999190210221792" id="id009652467339106443" class="input-output-copier">Copy</div></div><pre id="id0015999190210221792">1.00000000<br></pre></div></div></div>