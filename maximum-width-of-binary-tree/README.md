<h2>662. Maximum Width of Binary Tree</h2><h3>Medium</h3><hr><div><p>Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.</p>

<p>The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the <code>null</code> nodes between the end-nodes are also counted into the length calculation.</p>

<p>It is <strong>guaranteed</strong> that the answer will in the range of 32-bit signed integer.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

<b>Output:</b> 4
<b>Explanation:</b> The maximum width existing in the third level with the length 4 (5,3,null,9).
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> 

          1
         /  
        3    
       / \       
      5   3     

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the third level with the length 2 (5,3).
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> 

          1
         / \
        3   2 
       /        
      5      

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the second level with the length 2 (3,2).
</pre>

<p><b>Example 4:</b></p>

<pre><b>Input:</b> 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
<b>Output:</b> 8
<b>Explanation:</b>The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The&nbsp;given binary tree will have between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>3000</code>&nbsp;nodes.</li>
</ul>
</div>