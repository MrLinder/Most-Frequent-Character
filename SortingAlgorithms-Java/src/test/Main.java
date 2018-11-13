package test;

enum TypeSort{
	SELECT,
	BOUBLE
}

public class Main{
	
	public static SelectSorting selectSorting =  new SelectSorting();
	
	public static void main(String[] args) {
				
		Sorting selrct = selectSorting.getSort(TypeSort.SELECT);
		Sorting bouble = selectSorting.getSort(TypeSort.BOUBLE);
		
		selrct.doSmth();
		bouble.doSmth();
		
		
		
		
	}
}