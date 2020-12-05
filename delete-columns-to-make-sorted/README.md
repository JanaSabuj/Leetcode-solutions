<h2>unknown-problem</h2><h3>Easy</h3><hr><div><p>We are given an array&nbsp;<code>A</code> of <code>N</code> lowercase letter strings, all of the same length.</p>

<p>Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.</p>

<p>For example, if we have an array <code>A = ["abcdef","uvwxyz"]</code> and deletion indices <code>{0, 2, 3}</code>, then the final array after deletions is <code>["bef", "vyz"]</code>,&nbsp;and the remaining columns of <code>A</code> are&nbsp;<code>["b","v"]</code>, <code>["e","y"]</code>, and <code>["f","z"]</code>.&nbsp; (Formally, the <code>c</code>-th column is <code>[A[0][c], A[1][c], ..., A[A.length-1][c]]</code>).</p>

<p>Suppose we chose a set of deletion indices <code>D</code> such that after deletions, each remaining column in A is in <strong>non-decreasing</strong> sorted order.</p>

<p>Return the minimum possible value of <code>D.length</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> A = ["cba","daf","ghi"]
<strong>Output:</strong> 1
<strong>Explanation: </strong>
After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in non-decreasing sorted order.
If we chose D = {}, then a column ["b","a","h"] would not be in non-decreasing sorted order.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> A = ["a","b"]
<strong>Output:</strong> 0
<strong>Explanation: </strong>D = {}
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> A = ["zyx","wvu","tsr"]
<strong>Output:</strong> 3
<strong>Explanation: </strong>D = {0, 1, 2}
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 100</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 1000</code></li>
</ul>
</div>