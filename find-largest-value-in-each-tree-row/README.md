<h2>515. Find Largest Value in Each Tree Row</h2><h3>Medium</h3><hr><div><p>Given the <code>root</code> of a binary tree, return <em>an array of the largest value in each row</em> of the tree <strong>(0-indexed)</strong>.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 450px; height: 258px;">
<pre><strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> [1,3,9]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> [1,3]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> [1,2]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>