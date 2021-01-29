class Solution {
	public int lastStoneWeight(int[] stones) {
		PriorityQueue<Integer> pq = new PriorityQueue<>(31, Collections.reverseOrder());
		for (int x : stones)
			pq.add(x);

		while (pq.size() >= 2) {
			int a = pq.poll();
			int b = pq.poll();

			if (a == b)
				continue;
			else
				pq.add(a - b);
		}

		if (pq.size() == 0)
			return 0;
		else
			return pq.peek();
	}
}