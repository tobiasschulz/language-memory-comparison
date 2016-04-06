using System;
using System.Diagnostics;
using System.Dynamic;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;

public class Speicherauslastung
{
	public static void Main ()
	{
		var memoryStart = Process.GetCurrentProcess ().PeakWorkingSet64;
		var list = new List<dynamic> ();
		for (int i = 0; i < 1000000; i++) {
			list.Add (new {
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
		//Console.WriteLine ("   c# objekt (anonyme dynamische Klasse): memory start: {0} KB", memoryStart / 1024);
		//Console.WriteLine ("   c# objekt (anonyme dynamische Klasse): memory end: {0} KB", memoryEnd / 1024);
		Console.WriteLine ("   c# objekt (anonyme dynamische Klasse): memory diff: {0} KB", (memoryEnd - memoryStart) / 1024);
		Console.WriteLine ("   c# objekt (anonyme dynamische Klasse): memory per row: {0} byte", (memoryEnd - memoryStart) / 1000000);
	}
}
