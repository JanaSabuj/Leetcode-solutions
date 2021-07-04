<h2>834. Sum of Distances in Tree</h2><h3>Hard</h3><hr><div><p>An undirected, connected&nbsp;tree with <code>n</code> nodes labelled <code>0...n-1</code> and <code>n-1</code> <code>edges</code>&nbsp;are&nbsp;given.</p>

<p>The <code>i</code>th edge connects nodes&nbsp;<code>edges[i][0] </code>and<code>&nbsp;edges[i][1]</code>&nbsp;together.</p>

<p>Return a list <code>ans</code>, where <code>ans[i]</code> is the sum of the distances between node <code>i</code> and all other nodes.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
<strong>Output: </strong>[8,12,6,10,10,10]
<strong>Explanation: </strong>
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
</pre>

<p>Note:<font face="monospace">&nbsp;<code>1 &lt;= n &lt;= 10000</code></font></p>
</div>