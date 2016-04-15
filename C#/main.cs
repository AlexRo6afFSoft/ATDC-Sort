using System;
using System.Collections.Generic;

static class ATDC_Sort
{
	static Random rnd = new Random();
	static void Main()
	{
		List<int> L = new List<int> ();
		for (int i = 0; i < 10; i++)
		{
			L.Add (rnd.Next (-100, 100));
			Console.Write (L [i].ToString () + " ");
		}
		Console.WriteLine ();
	}
}
