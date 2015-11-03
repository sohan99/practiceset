package java151041010;


import java.sql.*;
import java.io.*;
import java.sql.DriverManager;


public class DBHandler {
	
	
		public void insertTable(String tableName,String Value)
		{
			Connection conn = null;
			Statement stmt = null;
			int count = 0;
		try {
		       	Class.forName("org.postgresql.Driver");
		       	conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/asses","postgres","postgres");
		       	String query = "insert into "+tableName+" values ('"+Value+"');";
		       	stmt = conn.createStatement();
		       	count = stmt.executeUpdate(query);
		       	System.out.println("rows updated : "+count);
		       	
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		catch(ClassNotFoundException e)
		{
			System.out.println("Import jar file");
			e.printStackTrace();
		}
		finally{
			try{
				if(stmt!=null)stmt.close();
				if(conn!=null)conn.close();
			}
			catch(SQLException e)
			{
			 e.printStackTrace();
			}
		}
	}

	public void getResult(String tableName)
		{
			Connection conn = null;
			Statement stmt = null;
			ResultSet rs = null;
			int count = 0;
		try {
		       	Class.forName("org.postgresql.Driver");
		       	conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/asses","postgres","postgres");
		       	String query = "select tempString from "+tableName +";";
		       	stmt = conn.createStatement();
		       	rs = stmt.executeQuery(query);
		       	while (rs.next()){
		       		System.out.println(rs.getString(1));
		       	}
		       	System.out.println("rows updated : "+count);
		}
		catch(SQLException e)
		{
			e.printStackTrace();
			System.out.println("Error :\nclass: DBHandler \nmethod getResult");
		}
		catch(ClassNotFoundException e)
		{
			System.out.println("Import jar file");
			e.printStackTrace();
		}// close connection 
		finally{
			try{
				if(rs != null)rs.close();
				if(stmt != null)stmt.close();
				if(conn != null)conn.close();
			}
			catch(SQLException e)
			{
			 e.printStackTrace();
			}
		}
	}
		
	public void insertFile(String fileName,String Value){
		BufferedWriter bd = null;
		File fl = null;
		try{
				fl = new File(fileName+"_txt.txt");
				if(!fl.exists())
					fl.createNewFile();
				FileWriter writer = new FileWriter(fl,true);
				bd = new BufferedWriter(writer);
				bd.write(Value+"\n"); 
			
			}
		catch(FileNotFoundException e){
				e.printStackTrace();
		}
		catch(IOException e){
			//e.printStackTrace();
		}
		finally{
			try{
				if(bd != null) bd.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
		
	public void readFileToConsole(String fileName){
		try{
				File fl = new File(fileName);
				if(!fl.exists()){
					System.out.println("File does nt exists");
					return ;
				}
				FileReader reader = new FileReader(fl);
				BufferedReader bd = new BufferedReader(reader);
				String str = null;
				System.out.println("Contents of the file");
				while((str = bd.readLine()) != null){
					System.out.println(str);
				}
				bd.close();
			}
			catch(Exception e){
				e.printStackTrace();
			}
		}
		
}


