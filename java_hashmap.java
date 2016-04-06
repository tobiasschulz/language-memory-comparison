import java.util.*;

public class java_hashmap
{
	public static void main(String args[]) {
		// create a 100 MB byte array
		// we need to get a larger heap size than the default one to measure more precisely
		byte[] bytes = new byte[99999999];
		for (int i = 0; i < bytes.length; i++) {
			bytes[i] = (byte)(i % 10);
		}

		long memoryStart = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

		ArrayList<HashMap<String,String>> list = new ArrayList<HashMap<String,String>> ();
		for (int i = 0; i < 1000000; i++) {
			HashMap<String,String> m = new HashMap<String,String>();
			m.put("id", i+"");
			m.put("spalte_a", new String("abcdefghijklmnopqrstuvwxyz"));
			m.put("spalte_b", new String("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
			m.put("spalte_c", new String("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"));
			m.put("spalte_d", new String("0123456789"));
			m.put("spalte_e", new String("0123456789012345678901234567890123456789012345678901234567890123456789"));
			m.put("spalte_f", new String("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"));
			list.add (m);
		}

		long memoryEnd = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
		//System.out.println ("java hashmap: memory start: " + (memoryStart / 1024) + " KB");
		//System.out.println ("java hashmap: memory end: " + (memoryEnd / 1024) + " KB");
		System.out.println ("java hashmap: memory diff: " + ((memoryEnd - memoryStart) / 1024) + " KB");
		System.out.println ("java hashmap: memory per row: " + ((memoryEnd - memoryStart) / 1000000) + "bytes");

		// keep the byte array it alive
		if (bytes.length == 123) {
			System.out.println("test");
		}
	}
}
