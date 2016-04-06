using System;
using System.Diagnostics;
using System.Collections.Generic;

public class Speicherauslastung
{
	public static void Main ()
	{
		var memoryStart = Process.GetCurrentProcess ().PeakWorkingSet64;
		//var memoryStart = GC.GetTotalMemory (false);
		var list = new List<Dictionary<string,string>> ();
		for (int i = 0; i < 1000000; i++) {
			list.Add (new Dictionary<string,string> (7) {
				[ "id" ] = i.ToString (),
				[ "spalte_a" ] = "abcdefghijklmnopqrstuvwxyz",
				[ "spalte_b" ] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
				[ "spalte_c" ] = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz",
				[ "spalte_d" ] = "0123456789",
				[ "spalte_e" ] = "0123456789012345678901234567890123456789012345678901234567890123456789",
				[ "spalte_f" ] = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc",
			});
		}
		var memoryEnd = Process.GetCurrentProcess ().PeakWorkingSet64;
		//var memoryEnd = GC.GetTotalMemory (false);
		//Console.WriteLine ("  c# hashmap: memory start: {0} KB", memoryStart / 1024);
		//Console.WriteLine ("  c# hashmap: memory end: {0} KB", memoryEnd / 1024);
		Console.WriteLine ("  c# hashmap: memory diff: {0} KB", (memoryEnd - memoryStart) / 1024);
		Console.WriteLine ("  c# hashmap: memory per row: {0} byte", (memoryEnd - memoryStart) / 1000000);
	}
}
