using System;
using System.Collections.Generic;
using AlexRo6afF;

static class ATDC_Sort
{
    static Random rnd = new Random();
    static void Main()
    {
        List<int> L = new List<int>();
        for (int i = 0; i < 25; i++)
        {
            L.Add(rnd.Next(-100, 100));
            Console.Write(L[i].ToString() + " ");
        }
        Console.WriteLine();

        ATDC.Sort((dynamic)L, 0, L.Count);
        for (int i = 0; i < 25; i++)
        {
            Console.Write(L[i].ToString() + " ");
        }
        Console.WriteLine();

        Comp<dynamic> c = (a, b) => { return b.CompareTo(a); };
        ATDC.Sort((dynamic)L, 0, L.Count, c);
        for (int i = 0; i < 25; i++)
        {
            Console.Write(L[i].ToString() + " ");
        }
        Console.WriteLine();
    }
}
