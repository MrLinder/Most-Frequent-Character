import java.util.Random;

public class Main{
	
	public static int[] array;
		
	public Main() {
			
		System.out.println("Source Array:"); 
		array = getRandomArray(100);
		printArray();		
		
		Sorting sorting = new Sorting(array, "Selection Sorting");
				sorting.start();
		
				try {
					sorting.join();
				} catch (InterruptedException e) {
					e.getStackTrace();
				}
				
				
		
		printArray(checkSequence(sorting.getArray()));
		
		
		
		printArray(sorting.getArray());
		
		
	}
	
	public static void main(String[] args) {
		new Main();
	}
	
	
	public boolean checkSequence(int[] arr) {
		
		for (int i : arr) {
			if(i > i+1)
				return false;
		}
		return true;
	}
	
	
	public int[] getRandomArray(int size) {
		Random rand = new Random();
		
		int[] arr = new int[size];
		
		for (int i = 0; i < size; i++)
			arr[i] = rand.nextInt(size);
		
		return arr;
	}
	
	public void printArray() {
		int counter = 0;
		for (int i : array) {
			counter++;
			System.out.print("[" + i + "]");
			if(counter == 10) {
				System.out.println();
				counter=0;
			}
		}
	}
		
	public void printArray(int[] arr) {
		int counter = 0;
		for (int i : arr) {
			counter++;
			System.out.print("[" + i + "]");
			if(counter == 10) {
				System.out.println();
				counter=0;
			}
		}
	}
	
	public void printArray(boolean seq) {
		if(seq == true)
			System.out.println("Array sorted correctly!");
		else
			System.err.println("Array not sorted...!");
	}
		
	
}
















