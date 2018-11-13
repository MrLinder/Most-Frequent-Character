//общий интерфейс

public interface Sort extends Runnable{
	
	public String name; 
	public int size;
	public int[] array;
	
	public default initialization(int[]arr, String name) {
		this.name = String.format("%s", name);
		this.size = arr.length;
		this.array = new int[size];
		for (int i = 0; i < size; i++) {
			this.array[i] =  arr[i];
		}
		System.out.print("\t" + this.name + ":\t");
	}	
	
	
	
}
