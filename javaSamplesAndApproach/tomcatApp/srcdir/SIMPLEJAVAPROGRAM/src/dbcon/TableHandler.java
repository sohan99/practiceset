package db;
import java.sql.*;
import org.json.simple.JSONObject;


public class TableHandler{
	DBConnection db;

	public TableHandler(){
		this.db = new DBConnection();
	}

	public String displayTable(String tableName){
		// if the table name is empty then 
		if(tableName == ""){
			System.out.println("table name empty..");
			return "NULL";
		}
		String output = "[";
		Statement statement = null;
		ResultSet resultset = null;
		try{
			this.db.ConnectDB();
			statement = this.db.conn.createStatement();
			String query = "select * from " + tableName + ";";
			resultset=statement.executeQuery(query);
			ResultSetMetaData metaData = resultset.getMetaData();
			//System.out.format("%32s%10d%16s", string1, int1, string2);

			// int count = metaData.getColumnCount();
			// for (int i = 1; i <= count; i++){
			// 		System.out.format("%32s   ",metaData.getColumnName(i));
			// }

			// System.out.println("");
			// while(resultset.next()){
			// 	for (int i = 1; i <= count; i++){
			// 		System.out.format("%32s   ",resultset.getString(i));

			// 	}
			// 	System.out.println("");

			// }
			
			int count = metaData.getColumnCount();
			while(resultset.next()){
				output+="{";
				for (int i = 1; i <= count; i++){
						output += "'"+metaData.getColumnName(i)+"':'" + resultset.getString(i) +"'";
						if(i<count){
							output +=",";
						}
				}
				output+="},";
			}
			
			System.out.println(output);




		


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
		output += "]";
		return output;
	}

	public JSONObject insertTable(String tableName,String values){

		// if the table name is empty then 
		JSONObject objJson = new JSONObject();
		if(tableName == ""){
			System.out.println("table name empty..");
			objJson.put("count",0);
			objJson.put("error","Table Not Present");
			return objJson;
		}
		
		int count = 0;
		Statement statement = null;
		try{

			this.db.ConnectDB();
			statement = this.db.conn.createStatement();
			String query = "insert into  " + tableName + " values ("+values+");";
			System.out.println(query);
			count =statement.executeUpdate(query);
			objJson.put("count",count);
			objJson.put("error","None");


		}
		catch(Exception e){
			System.out.println("error : "+e);
			objJson.put("count",count);
			objJson.put("error",e.getMessage());
		}
		finally{
			try{
				if(statement!=null)statement.close();
			}catch(Exception e)	{
				e.printStackTrace();
			}
			this.db.closeDB();
			return objJson;
		}
	}











}