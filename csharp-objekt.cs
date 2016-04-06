using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;

public class Speicherauslastung
{
	public static void Main ()
	{
		var memoryStart = Process.GetCurrentProcess ().PeakWorkingSet64;
		var list = new List<Model> ();
		for (int i = 0; i < 1000000; i++) {
			list.Add (new Model {
				id = i,
				spalte_a = "abcdefghijklmnopqrstuvwxyz",
				spalte_b = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
				spalte_c = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz",
				spalte_d = "0123456789",
				spalte_e = "0123456789012345678901234567890123456789012345678901234567890123456789",
				spalte_f = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc",
			});
		}
		var memoryEnd = Process.GetCurrentProcess ().PeakWorkingSet64;
		Console.WriteLine ("   c# objekt (deklarierte attribute): memory start: {0} KB", memoryStart / 1024);
		Console.WriteLine ("   c# objekt (deklarierte attribute): memory end: {0} KB", memoryEnd / 1024);
		Console.WriteLine ("   c# objekt (deklarierte attribute): memory diff: {0} KB", (memoryEnd - memoryStart) / 1024);
		Console.WriteLine ("   c# objekt (deklarierte attribute): memory per row: {0} byte", (memoryEnd - memoryStart) / 1000000);
	}
}

public class Model
{
	public int id;
	public string spalte_a;
	public string spalte_b;
	public string spalte_c;
	public string spalte_d;
	public string spalte_e;
	public string spalte_f;
}
