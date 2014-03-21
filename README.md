NxN Tic Tac Toe
===============
-----------------

Abstract
--------
NxN Tic Tac Toe is but a natural extension to the normal, well known 3x3 version and it
would seem trivial to extend the 3x3 strategy and naïvely search through the complete state
space. However, if one were to check the state space of a general NxN Tic Tac Toe, it is
obvious that it blows up exponentially. Hence, it is intractable to use a naïve search.
However, one can use clever pruning techniques and heuristic methods to either reduce the
state space or reduce the time spent at each state. This project aims to use a version of
Minimax Algorithm [1] combined with Alpha Beta Pruning [2] to create a working Artificial
Intelligence for this game which can play reasonably well within reasonable amount of time
(i.e. time taken by AI per move to “think”). As a heuristic, a function which maps the counts of X or O in each row/column/diagonal to a value is used.

References
----------

[1] [http://en.wikipedia.org/wiki/Minimax](http://en.wikipedia.org/wiki/Minimax)

[2] [http://en.wikipedia.org/wiki/Alpha_beta_pruning](http://en.wikipedia.org/wiki/Alpha_beta_pruning)