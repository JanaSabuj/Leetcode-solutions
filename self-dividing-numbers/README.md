<h2>728. Self Dividing Numbers</h2><h3>Easy</h3><hr><div><p>
A <i>self-dividing number</i> is a number that is divisible by every digit it contains.
</p><p>
For example, 128 is a self-dividing number because <code>128 % 1 == 0</code>, <code>128 % 2 == 0</code>, and <code>128 % 8 == 0</code>.
</p><p>
Also, a self-dividing number is not allowed to contain the digit zero.
</p><p>
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
</p>
<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
left = 1, right = 22
<b>Output:</b> [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
</pre>
<p></p>

<p><b>Note:</b>
</p><li>The boundaries of each input argument are <code>1 &lt;= left &lt;= right &lt;= 10000</code>.</li>
<p></p></div>