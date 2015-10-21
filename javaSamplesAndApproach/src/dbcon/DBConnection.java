package com.db;

import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.*;	
import java.util.Properties;

public class DBConnection
{
	public Connection conn = null;	
	private String IP_ADDRESS_PORT = "";
	private String URL = "";
	private String CLASS_NAME = "";
	private String DATABASE_NAME = "";
	private String USERNAME = "";
	private String PASSWORD = "";

	/**
	 Function to retrieve data for the database connection	 
	*/
	public DBConnection()
	{	
		try {			
			InputStream is = new FileInputStream("com/db_details/dbConnection.properties");
			Properties props = new Properties();
			props.load(is);
			
			this.IP_ADDRESS_PORT = (String)props.get("IP_ADDRESS_PORT");
			this.URL 			= (String)props.get("URL");
			this.CLASS_NAME 		= (String)props.get("CLASS_NAME");
			this.DATABASE_NAME	= (String)props.get("DATABASE_NAME");
			this.USERNAME 		= (String)props.get("USERNAME");
			this.PASSWORD 		= (String)props.get("PASSWORD");			
		}catch(Exception e){

			System.out.println("Class Name : DBConnection");
			System.out.println("Function Name : DBConnection");
			System.out.println("prroperty file missing : " +e);
		}
	}
	/**
		Connection to the database
	*/	
	public void ConnectDB()
	{
		try{
			
			Class.forName(this.CLASS_NAME);
			this.conn = DriverManager.getConnection(this.URL+"://"+this.IP_ADDRESS_PORT+"/"+this.DATABASE_NAME,this.USERNAME,this.PASSWORD);
		}
		catch(Exception e){
			System.out.println("Class Name : DBConnection");
			System.out.println("Function Name : ConnectDB");
			System.out.println("Error :"+e);
		}
	}

	public void closeDB()
	{
		try{
			this.conn.close();
		}
		catch(Exception e){
			System.out.println("Class Name : DBConnection");
			System.out.println("Function Name : closeDB");
			System.out.println("Error :"+e);
		}
	}

}
