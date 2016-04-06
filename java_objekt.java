import java.util.*;

public class java_objekt
{
	public static void main(String args[]) {
		// create a 100 MB byte array
		// we need to get a larger heap size than the default one to measure more precisely
		byte[] bytes = new byte[99999999];
		for (int i = 0; i < bytes.length; i++) {
			bytes[i] = (byte)(i % 10);
		}

		long memoryStart = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

		ArrayList<Model> list = new ArrayList<Model> ();
		for (int i = 0; i < 1000000; i++) {
			Model m = new Model();
			m.id = i;
			m.spalte_a = new String("abcdefghijklmnopqrstuvwxyz");
			m.spalte_b = new String("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
			m.spalte_c = new String("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz");
			m.spalte_d = new String("0123456789");
			m.spalte_e = new String("0123456789012345678901234567890123456789012345678901234567890123456789");
			m.spalte_f = new String("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
			list.add (m);
		}

		long memoryEnd = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
		//System.out.println (" java objekt: memory start: " + (memoryStart / 1024) + " KB");
		//System.out.println (" java objekt: memory end: " + (memoryEnd / 1024) + " KB");
		System.out.println (" java objekt: memory diff: " + ((memoryEnd - memoryStart) / 1024) + " KB");
		System.out.println (" java objekt: memory per row: " + ((memoryEnd - memoryStart) / 1000000) + "bytes");

		// keep the byte array it alive
		if (bytes.length == 123) {
			System.out.println("test");
		}
	}

	public static class Model
	{
		public int id;
		public String spalte_a;
		public String spalte_b;
		public String spalte_c;
		public String spalte_d;
		public String spalte_e;
		public String spalte_f;
	}
}
