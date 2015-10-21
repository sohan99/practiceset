
import com.db.DBConnection*;
import java.sql.*;


public class Test {


	public static void main(String argv[]){

		DBConnection db = new DBConnection();

		db.ConnectDB();
		System.out.println("ha done");
		try{
			ResultSet resultset;
			Statement statement = db.conn.createStatement();
			resultset=statement.executeQuery("select * from test");
			while(resultset.next())
			{ 
			     System.out.println(resultset.getString("role"));
			}
		}
		catch(Exception e){
			System.out.println("error : "+e);
		}
		finally{
			db.closeDB();
		}
	}
}