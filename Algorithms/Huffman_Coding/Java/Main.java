
public class Main {
	public static void main(String[] args) {
		String s = "mjhcdibygwfwejifwiue jugcfbcwewiy fvvwevhwihi";
		HuffmanCoding hc = new HuffmanCoding();
		hc.encode(s);
		hc.compressionStats();
		hc.printCodes();
	}
}
