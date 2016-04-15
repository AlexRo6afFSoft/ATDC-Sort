namespace AlexRo6afF
{
	using System;
	using System.Collections.Generic;

	public delegate int Comp<T> (T a, T b);

	public static class ATDC
	{
		private static void Merge<T> (T what, int b1, int e1, int b2, int e2,Comp comp)
		{
			T __arr = new T ();
			int it1 = b1, it2 = b2;
			while (it1 != e1 && it2 != e2) 
			{
				if (comp (what [it1], what [it2]) == 1)
				{
					__arr.Add (what [it1]);
					it1++;
				}
				else
				{
					__arr.Add (what [it2]);
					it2++;
				}
			}
			if (it1 == e1)
			{
				while (it2 != e2)
				{
					__arr.Add (what [it2]);
					it2++;
				}
			}
			if (it2 == e2)
			{
				while (it1 != e1)
				{
					__arr.Add (what [it1]);
					it1++;
				}
			}
			it1 = b1;
			for(int i = 0; i < e1 - b1; i++)
			{
				what [it1] = __arr [i];
				it1++;
			}
			it2 = b2;
			for (int i = e1 - b1; i < __arr.lenght; i++)
			{
				what [it2] = __arr [i];
				it2++;
			}
		}

		public static void Sort<T> (T what, int begin, int end, Comp comp)
		{
			int dist = end - begin + 1;
			if (dist == 0 || dist == 1)
			{
				return;
			}
			if(dist == 2)
			{
				if(comp(what[begin], what[end]) == 1)
				{
					int tmp = what[begin];
					what[begin] = what[end];
					what[end] = tmp;
				}
				return ;
			}
			dist /= 2;
			int mid = begin + dist;
			Sort(what, begin, mid, comp);
			Sort(what, mid, end, comp);
			Merge(what, begin, mid, mid, end, comp);
		}
	}
}
