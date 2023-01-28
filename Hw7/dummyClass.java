import java.util.*;

public class dummyClass {
	/*This function is used to copy an vector into another */

	static Vector<Vector<Character>> deepCopy(Vector<Vector<Character>> object){
		
		Vector<Vector<Character>> Holder = new Vector<Vector<Character>>();

		int row = object.size();
		int col = object.get(0).size();

		for (int i = 0; i < row; ++i)
		{
			Vector<Character> temp = new Vector<Character>();

			for (int j = 0; j < col; ++j)
			{
				temp.add(object.get(i).get(j));
			}

			Holder.add(temp);
		}

		return Holder;
	}
}
