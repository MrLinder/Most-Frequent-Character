package test;

public final class Selection extends MainSort implements Sorting {
	
	@Override
	public void doSmth() {
		this.name = "Select";
		this.digit = 100;
		
		System.out.println(this.name + " " + this.digit);
	}
}
