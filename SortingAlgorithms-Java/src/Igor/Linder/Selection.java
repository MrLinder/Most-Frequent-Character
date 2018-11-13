package Igor.Linder;

public class Selection extends ArchetypeSort {
	
	public Selection(int[] arr, String name ) {
		super(arr, name);
	}

	@Override
	public void run() {
		System.out.println(Thread.currentThread().getName() + " -> " + super.nameSort + ": ");
	
	}
}
