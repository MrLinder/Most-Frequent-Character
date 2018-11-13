package Igor.Linder;

public class SortSelection {
	
	private Sorting sorting = null;
	
	private int[] array;
	
	//Registered sorting types
	private TypeSort type_Selection = TypeSort.SELECTION;
	private TypeSort type_Insertion = TypeSort.INSERTION;
			
	public SortSelection(Integer[] arr) {
		this.array = new int[arr.length];
		for (int i = 0; i < arr.length; i++) 
			this.array[i] = arr[i];
	}	
	
	public Sorting getSort(TypeSort type) {
		
		switch (type)
		{
			case SELECTION: sorting = new Selection(this.array, type_Selection.nameSort());		break;
			case INSERTION: sorting = new Insertion(this.array, type_Insertion.nameSort());		break;
			default:
				break;
		}
		
		return sorting;
	}
}
