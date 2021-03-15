<h2>76. Minimum Window Substring</h2><h3>Hard</h3><hr><div><p>Given two strings <code>s</code> and <code>t</code>, return <em>the minimum window in <code>s</code> which will contain all the characters in <code>t</code></em>. If there is no such window in <code>s</code> that covers all characters in <code>t</code>, return <em>the empty string <code>""</code></em>.</p>

<p><strong>Note</strong> that If there is such a window, it is&nbsp;guaranteed that there will always be only one unique minimum window in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
<strong>Output:</strong> "BANC"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> "a"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(n)</code> time?</div>