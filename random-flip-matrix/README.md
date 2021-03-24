<h2>519. Random Flip Matrix</h2><h3>Medium</h3><hr><div><p>You are given the number of rows <code>n_rows</code>&nbsp;and number of columns <code>n_cols</code>&nbsp;of a&nbsp;2D&nbsp;binary matrix&nbsp;where all values are initially 0.&nbsp;Write a function <code>flip</code>&nbsp;which chooses&nbsp;a 0 value&nbsp;<a href="https://en.wikipedia.org/wiki/Discrete_uniform_distribution" target="_blank">uniformly at random</a>,&nbsp;changes it to 1,&nbsp;and then returns the position <code>[row.id, col.id]</code> of that value. Also, write a function <code>reset</code> which sets all values back to 0.&nbsp;<strong>Try to minimize the number of calls to system's Math.random()</strong> and optimize the time and&nbsp;space complexity.</p>

<p>Note:</p>

<ol>
	<li><code>1 &lt;= n_rows, n_cols&nbsp;&lt;= 10000</code></li>
	<li><code>0 &lt;= row.id &lt; n_rows</code> and <code>0 &lt;= col.id &lt; n_cols</code></li>
	<li><code>flip</code>&nbsp;will not be called when the matrix has no&nbsp;0 values left.</li>
	<li>the total number of calls to&nbsp;<code>flip</code>&nbsp;and <code>reset</code>&nbsp;will not exceed&nbsp;1000.</li>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">["Solution","flip","flip","flip","flip"]
</span><span id="example-input-1-2">[[2,3],[],[],[],[]]</span>
<strong>Output: </strong><span id="example-output-1">[null,[0,1],[1,2],[1,0],[1,1]]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-2-1">["Solution","flip","flip","reset","flip"]
</span><span id="example-input-2-2">[[1,2],[],[],[],[]]</span>
<strong>Output: </strong><span id="example-output-2">[null,[0,0],[0,1],null,[0,0]]</span></pre>
</div>

<p><strong>Explanation of Input Syntax:</strong></p>

<p>The input is two lists:&nbsp;the subroutines called&nbsp;and their&nbsp;arguments. <code>Solution</code>'s constructor&nbsp;has two arguments, <code>n_rows</code> and <code>n_cols</code>.&nbsp;<code>flip</code>&nbsp;and <code>reset</code> have&nbsp;no&nbsp;arguments.&nbsp;Arguments&nbsp;are&nbsp;always wrapped with a list, even if there aren't any.</p>
</div>