import java.util.*;

/**
 * <configuration>
   <sourcepath>HW7</sourcepath>
	</configuration>
 * @author Emirhan Utku Demir 200104004056
 * @version openjdk version "1.8.0_252"
 */

public class driver1{
	private static final char escCode = 0x1B; 

	/**
	 * Main method to start the program
	 * @param arg Console arguments - UNUSED
	 */
	public static void main (String arg[]){

		/*input will be used to get input from user*/
		Scanner input = new Scanner(System.in);
		/*Buffer will be used to hold user input*/
		String buffer = new String();

		int col = -1,row = -1;

		try {
			do{
				System.out.print("Please Enter row amount : ");
				row = input.nextInt();
				if (row < 0)
					throw new Exception();
					
					System.out.print("Please Enter col amount : ");
					col = input.nextInt();
					if (col < 0)
						throw new Exception();
			}while(row < 5 && col < 5);
		} catch (Exception e) {
			System.out.println("Invalid input, try again !!!\n");
		}


		Tetris Game = new Tetris(col,row);
		input.nextLine();	/*Clearing Input Buffer*/

		/*This loop will continue as long as user wants to continue*/
		do{
			try {
				System.out.print("Choose Your Tetromino (I,T,L,R,Q...): ");

				buffer = input.nextLine();

				/*Check user input*/
				if (buffer.length() == 0)
					throw new Exception();

				if (buffer.charAt(0) != 'T' &&
				buffer.charAt(0) != 'I' &&
				buffer.charAt(0) != 'L' &&
				buffer.charAt(0) != 'O' &&
				buffer.charAt(0) != 'S' &&
				buffer.charAt(0) != 'Z' &&
				buffer.charAt(0) != 'R' &&
				buffer.charAt(0) != 'J' &&
				buffer.charAt(0) != 'Q')
					throw new Exception();
				
				/*If user entered Q, terminate*/	
				if (buffer.charAt(0) == 'Q')
				{
					System.out.println("Good Bye !");
					break;
				}

				char tetroType = buffer.charAt(0);
				/*New Tetromino is created*/
				Tetromino newTetromino = new Tetromino(tetroType);

				System.out.print("How many rotation do you want (to right) : ");
				int rotationAmount = input.nextInt();

				for (int i = 0; i < rotationAmount; ++i)
				{
					newTetromino.tetriminorotateRight90();
				}

				System.out.println("Which direction you wanna move (1->Right, -1->Left) : ");
				int dir = input.nextInt();

				System.out.println("How many steps : ");
				int stepAmount = input.nextInt();

				if (Game.animate(newTetromino, dir, stepAmount) == false)
				{
					System.out.println("Game is over !!!");
					break;
				}

			} catch (Exception e) {
				System.out.println("Invalid input, try again !!!");
			}
			input.nextLine();	/*Clearing Input Buffer*/
			System.out.print(String.format("%c[%d;%df",escCode,5,0));

		}while(true);

		/*Closing scanner object*/
		input.close();
	}
}



