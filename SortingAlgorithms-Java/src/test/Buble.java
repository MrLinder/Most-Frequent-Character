package test;

public class Buble extends MainSort implements Sorting{
	@Override
	public void doSmth() {
		this.name = "buble";
		this.digit = 200;
		
		System.out.println(this.name + " " + this.digit);
	}
}
