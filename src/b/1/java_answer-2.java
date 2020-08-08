import java.util.Scanner;

public class Test
{

	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		
		System.out.println("");
		
		int lambAmount=scan.nextInt();
		int lengthOfStreet=scan.nextInt();
		
		int[] array=new int[lambAmount];
		
		for(int i=0;i<lambAmount;i++) 
		{
			array[i]=scan.nextInt();
		}
		
		System.out.println(minimumLightRadius(lambAmount,lengthOfStreet,array));
		
		scan.close();
		
		
	}
	
	
	//Assume that lambAmount==positionOfLambs.length
	public static double minimumLightRadius(int lambAmount,int lengthOfStreet,int[] positionsOfLambs) 
	{
		bubbleSort(positionsOfLambs);
		
		double maxDistance=0;   //Variable to store maximum distance between two lambs
		double difference=0;    //Temporary variable
		
		for(int i=0;i<positionsOfLambs.length-1;i++) 
		{
			difference=positionsOfLambs[i+1]-positionsOfLambs[i];
			if(difference>maxDistance) 
			{
				maxDistance=difference;
			}
		}
		
		//Checks whether maxDistance can adjust the boundaries
		double lowerDifference=positionsOfLambs[0]-(maxDistance/2);
		double upperDifference=lengthOfStreet-(positionsOfLambs[positionsOfLambs.length-1] + (maxDistance/2));
		
		
		if(lowerDifference<0) 
		{
			lowerDifference=0;
		}
		
		if(upperDifference<0) 
		{
			upperDifference=0;
		}
		
		if((lowerDifference==0) || (upperDifference>lowerDifference))
		{
			return (maxDistance/2)+upperDifference;
		}
		
		else if((upperDifference==0) || (lowerDifference>=upperDifference))
		{
			return (maxDistance/2)+lowerDifference;
		}
		
		return 0;
		
		
		
	}
	
	
	
	public static void bubbleSort(int[] array) 
	{
		for(int i=0;i<array.length;i++) 
		{
			for(int j=0;j<array.length;j++) 
			{
				if((i!=j) && (array[i]<array[j]))
				{
					swap(array,i,j);
				}
			}
			
		}
	}
	
	
	
	public static void swap(int[] array,int first,int second) 
	{
		int temp=array[second];
		array[second]=array[first];
		array[first]=temp;
	}

}
