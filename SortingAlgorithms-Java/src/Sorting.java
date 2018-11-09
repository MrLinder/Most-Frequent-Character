public class Sorting extends Thread{
	
	protected String name; 
	protected int size;
	protected int[] array;
	
	
	public Sorting(int[]arr, String name) {
		this.name = String.format("%s", name);
		this.size = arr.length;
		this.array = new int[size];
		for (int i = 0; i < size; i++) {
			this.array[i] =  arr[i];
		}
		System.out.print("\t" + this.name + ":\t");
	}
	
	@Override
	public void run() {
		
		for (int i = 0; i < size; i++) {
			for (int j = i+1; j < size; j++) {
				if(array[i] > array[j])
					swap(i, j);
			}
		}
	}
	
	private void swap(int x, int y){
		int t = array[x];
		array[x] = array[y];
		array[y] = t;
	}
	
	
	public int[] getArray() {
		return this.array;
	}
	
	
	
	
}
