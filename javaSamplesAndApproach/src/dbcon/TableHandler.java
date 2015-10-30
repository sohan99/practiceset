package db;
import java.sql.*;


public class TableHandler{
	DBConnection db;

	public TableHandler(){
		this.db = new DBConnection();
	}

	public void displayTable(String tableName){
		// if the table name is empty then 
		if(tableName == ""){
			System.out.println("table name empty..");
			return;
		}
		Statement statement = null;
		ResultSet resultset = null;
		try{
			this.db.ConnectDB();
			statement = this.db.conn.createStatement();
			String query = "select * from " + tableName + ";";
			resultset=statement.executeQuery(query);
			ResultSetMetaData metaData = resultset.getMetaData();
			//System.out.format("%32s%10d%16s", string1, int1, string2);

			int count = metaData.getColumnCount();
			for (int i = 1; i <= count; i++){
					System.out.format("%32s   ",metaData.getColumnName(i));
			}

			System.out.println("");
			while(resultset.next()){
				for (int i = 1; i <= count; i++){
					System.out.format("%32s   ",resultset.getString(i));

				}
				System.out.println("");

			}

		}
		catch(Exception e){
			System.out.println("error : "+e);
		}
		finally{
			try{
				if(resultset!=null)resultset.close();
				if(statement!=null)statement.close();
			}catch(Exception e)	{
				e.printStackTrace();
			}
			this.db.closeDB();
		}
	}

	public int insertTable(String tableName,String values){
		// if the table name is empty then 
		if(tableName == ""){
			System.out.println("table name empty..");
			return 0;
		}
		int count = 0;
		Statement statement = null;
		try{

			this.db.ConnectDB();
			statement = this.db.conn.createStatement();
			String query = "insert into  " + tableName + " values ("+values+");";
			System.out.println(query);
			count =statement.executeUpdate(query);


		}
		catch(Exception e){
			System.out.println("error : "+e);

		}
		finally{
			try{
				if(statement!=null)statement.close();
			}catch(Exception e)	{
				e.printStackTrace();
			}
			this.db.closeDB();
			return count;
		}
	}











}